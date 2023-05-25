/*
 *  File: HEFlash.c
 *
 *  High Endurance Flash - EEPROM emulation and support routines
 *
 *  Author: Lucio Di Jasio
 *
 *  Created on August 28, 2013
 */
#include <xc.h>
#include "HEFlash.h"

/******************************************************************************
 * High Endurance Flash functions
 */

char HEFLASH_writeBlock( unsigned char radd, unsigned char* data, char count)
{
    // 1. obtain absolute address in HE FLASH row
    unsigned add = radd * FLASH_ROWSIZE + HEFLASH_START;

    // 2. check input parameters
    if ( ( count > FLASH_ROWSIZE) || (radd >= HEFLASH_MAXROWS))
        return -1;  // return parameter error

    // 3. erase the entire row
    FLASH_erase( add);

    // 4. fill the latches with data
    while( count > 1)
    {
        // load data in latches without writing
        FLASH_write( add++, (unsigned) *data++, 1);
        count--;
    }
    // no delay here!!!

    // 5. last byte of data -> write
    FLASH_write( add, (unsigned) *data, 0);

    // NOTE: 2ms typ. delay here!!!

    // 6. return success
    return PMCON1bits.WRERR;    // 0 success, 1 = write error

} // HEFLASH_writeBlock


char HEFLASH_readBlock( char *buffer, char radd, char count)
{
    // 1. obtain absolute address in HE FLASH row
    unsigned add = radd * FLASH_ROWSIZE + HEFLASH_START;

    // 2. check input parameters
    if ( ( count > FLASH_ROWSIZE) || (radd >= HEFLASH_MAXROWS))
        return -1;

    // 3. read content
    while ( count > 0)
    {
        *buffer++ = (char) FLASH_read( add++);
        count--;
    }
    
    // 4. success
    return 0;
} // HEFLASH_readBlock


char HEFLASH_readByte( char radd, char offset)
{
    // 1. add offset into HE Flash memory
    unsigned add = radd * FLASH_ROWSIZE + HEFLASH_START + offset;

    // 2. read content
    return (char) FLASH_read( add);
} // HEFLASH_read


/******************************************************************************
 * Generic Flash functions
 */

unsigned FLASH_readConfig( unsigned address)
{
    // 1. load the address pointers
    PMADR = address;
    PMCON1bits.CFGS = 1;    // select the configuration flash address space
    PMCON1bits.RD = 1;      // next operation will be a read
    NOP();
    NOP();

    // 2. return value read
    return PMDAT;
} // FLASH_config


unsigned FLASH_read( unsigned address)
{
    // 1. load the address pointers
    PMADR = address;
    PMCON1bits.CFGS = 0;    // select the flash address space
    PMCON1bits.RD = 1;      // next operation will be a read
    NOP();
    NOP();

    // 2. return value read
    return PMDAT;
} // FLASH_read


void FLASH_readBlock( unsigned *buffer, unsigned address, char count)
{
    while ( count > 0)
    {
        *buffer++ = FLASH_read( address++);
        count--;
    }
} // FLASH_readBLock


/**
 * unlock Flash Sequence
 */
void _unlock( void)
{
    #asm
        BANKSEL     PMCON2
        MOVLW       0x55
        MOVWF       PMCON2 & 0x7F
        MOVLW       0xAA
        MOVWF       PMCON2 & 0x7F
        BSF         PMCON1 & 0x7F,1    ; set WR bit
        NOP
        NOP
    #endasm
} // unlock


void FLASH_write( unsigned address, unsigned data, char latch)
{
    // 1. disable interrupts (remember setting)
    char temp = INTCONbits.GIE;
    INTCONbits.GIE = 0;

    // 2. load the address pointers
    PMADR = address;
    PMDAT = data;
    PMCON1bits.LWLO = latch;// 1 = latch, 0 = write row
    PMCON1bits.CFGS = 0;    // select the flash address space
    PMCON1bits.FREE = 0;    // next operation will be a write
    PMCON1bits.WREN = 1;    // enable flash memory write/erase

    // 3. perform unlock sequence
    _unlock();

    // 4. restore interrupts
    if ( temp)
        INTCONbits.GIE = 1;

} // FLASH_write


void FLASH_erase( unsigned address)
{
    // 1. disable interrupts (remember setting)
    char temp = INTCONbits.GIE;
    INTCONbits.GIE = 0;

    
    // 2. load the address pointers
    PMADR = address;
    PMCON1bits.CFGS = 0;    // select the flash address space
    PMCON1bits.FREE = 1;    // next operation will be an erase
    PMCON1bits.WREN = 1;    // enable flash memory write/erase

    // 3. perform unlock sequence and erase
    _unlock();

    // 4. disable writes and restore interrupts
    PMCON1bits.WREN = 0;    // disable flash memory write/erase
    if ( temp)
        INTCONbits.GIE = 1;

} // FLASH_erase



