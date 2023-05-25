////////////////////////////////////////////
// LayerOne 2023 revision of OKBB firmware//
////////////////////////////////////////////

// LayerOne 2023
// Use HT_PIC16F54_BootLoader version for DFU load


#include <xc.h>
#include <math.h>
#include <stdio.h>
#include "HEFlash.h"
#include "Usb.h"
#include "ws2812.h"
#include "scan_codes.h"
#include "keyboard.h"


// --ROM=default,-1f80-1fff for Flash
// default,0-1FF,1F7F-1F7F for BootLoader

__IDLOC ( 4D8A );

// there is a bootloader, but we don't know where it is
#ifndef USE_BOOTLOADER

// don't need this in bootloader mode
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is Digital Input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = NOCLKDIV // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON        // Low-Voltage Programming Enable (Low-voltage programming enabled)

#endif

// const data of a breathe in/out ramp for the key led
static const unsigned char breathe[] = {
    1, 1, 2, 7, 15, 25, 39, 54, 72, 91, 111, 131, 151, 171, 189, 206,
    221, 234, 243, 250, 254, 254, 251, 245, 236, 225, 210, 194, 176,
    156, 136, 116, 96, 77, 59, 43, 29, 17, 9, 3, 1, 1
};

// Local Variables
static BYTE buttonStatus; // This is to hold last status of the button so that we only report if it changes
static BYTE ledState;

// status of modifier keys
static BYTE modifierKeys = 0;

static BYTE mode = 0;

// 32 bytes * 4 =128
static uint8_t flashBuffer[ FLASH_ROWSIZE * 4 ];

// interrupt driven counter ( needs to be calibrated)
volatile uint32_t microseconds = 0;

// Interrupt

// xc8 doesn't like interrupt keyword
// void interrupt ISRCode()
void interrupt ISRCode()
{
    if (INTCONbits.TMR0IF) {
        microseconds += 1; // With 1:16 pre-scaler and FOSC/4 clock source, Timer0 increments every 8 microseconds
        TMR0 = 0; // Reset Timer0 value
        INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    }

    if ( UsbInterrupt ) {
        ProcessUSBTransactions();
    }
}

static void InitializeSystem ( void )
{
    ANSELA = 0x00;
    ANSELC = 0x00;
    OSCTUNE = 0x00;
    OSCCON = 0xFC; // 16MHz HFINTOSC with 3x PLL enabled (48MHz operation)
    ACTCON = 0x90; // Enable active clock tuning with USB
    OPTION_REG = 0xC3; // Set pre-scaler to 256
    
/*
    Pinouts for peripherals
 *
    #define WS2812              RC3
    #define Button              RA4 // RA4 for new version
    #define Led                 RC5
    
*/
    TRISC = 0b00010000; // Set RC3 as output (WS2812) except RA4 for Button
    
    // TRISCbits.TRISC4 = 0b1;
    OPTION_REGbits.nWPUEN = 0;
    
    ////WPUA = 0b00010000;
    WPUAbits.WPUA4 = 0b1;
    buttonStatus = 0;
    LATC = 0b00000000; // Clear Port C Latches;
    
    TMR0 = 0; // Reset Timer0 value
    INTCONbits.TMR0IE = 1; // Enable Timer0 interrupt
    INTCONbits.TMR0IF = 0; // Clear Timer0 interrupt flag
    INTCONbits.PEIE = 1; // Enable peripheral interrupts
    INTCONbits.GIE = 1; // Enable global interrupts
}

static void EnableInterrupts ( void )
{
    UIE = 0x4B; // Transaction complete, Start Of Frame, Error, Reset
    INTCONbits.PEIE = 1; // Peripheral Interrupt enable
    INTCONbits.GIE = 1; // Global Interrupt Enable
    PIE2bits.USBIE = 1; // Enable USB Global Interrupt
}

BYTE getLEDstate ( void )
{
    return ledState;
}

BYTE getMODstate(void)
{
    return modifierKeys;
}

void ProcessIncommingKbdData ( void )
{
    // Windows Will send only a single Byte
    // with statuses of LEDs
    // first bit for NUM lock, second for caps etc..

    modifierKeys = keyboardRXBuffer[0];
    
    Led = ( modifierKeys & 0x01 );
}

void ProcessIncommingHidData ( void )
{
    BYTE i;

    switch ( controlRXBuffer[0] ) {

        case 0xF0:

            Red[3] = controlRXBuffer[10];
            Green[3] = controlRXBuffer[11];
            Blue[3] = controlRXBuffer[12];

        case 0xF1:

            Red[0] = controlRXBuffer[1];
            Green[0] = controlRXBuffer[2];
            Blue[0] = controlRXBuffer[3];

            Red[1] = controlRXBuffer[4];
            Green[1] = controlRXBuffer[5];
            Blue[1] = controlRXBuffer[6];

            Red[2] = controlRXBuffer[7];
            Green[2] = controlRXBuffer[8];
            Blue[2] = controlRXBuffer[9];

            break;

        case 0xF2:

            Red[3] = controlRXBuffer[1];
            Green[3] = controlRXBuffer[2];
            Blue[3] = controlRXBuffer[3];

            break;

        // writes out all the flash memory 128 bytes
        case 0xfd:
            HEFLASH_writeBlock ( 1, flashBuffer,  FLASH_ROWSIZE );
            HEFLASH_writeBlock ( 2, &flashBuffer[ FLASH_ROWSIZE * 2], FLASH_ROWSIZE );
            HEFLASH_writeBlock ( 3, &flashBuffer[ FLASH_ROWSIZE * 3], FLASH_ROWSIZE );
            HEFLASH_writeBlock ( 4, &flashBuffer[ FLASH_ROWSIZE * 4], FLASH_ROWSIZE );
            break;
            


        case 0xfe:
            // buffer is cmd = 0xfe, offset*8, 8 bytes of data

            // calculate offset  n * 8
            {
                unsigned char multiplier = controlRXBuffer[1];
                unsigned int offset = (unsigned int)multiplier * 8;

                for ( i = 0; i < 8; i++ ) {
                    flashBuffer[ ( offset ) + i ] = (unsigned char)controlRXBuffer[ 2 + i ];
                }
            }
            break;

        case 0xff:

            for ( i = 0; i < 15; i++ ) {
                flashBuffer[15 + i] = (unsigned char)controlRXBuffer[ 1 + i ];
            }

            flashBuffer[ FLASH_ROWSIZE - 1 ] = 0;

            break;

        default:

            // Windows Will send only a single byte
            // with statuses of LED
            // first bit for NUM lock, second for CAPS lock etc..
            Led = ((unsigned int)controlRXBuffer[0] & 0x01 );

            ledState = Led;

            break;
    }

    OutputLEDDataStream();
}

void PrepareHidTxBuffer ( void )
{
    BYTE i;

    controlTXBuffer[0] = 0x80; // Status
    controlTXBuffer[1] = Button; // Button Status
    controlTXBuffer[2] = Led; // Led Status
    controlTXBuffer[3] = 0x00; // Empty Byte

    // Keyboard
    for ( i = 3; i < 0x10; i++ ) {
        controlTXBuffer[i] = flashBuffer[i - 3];
    }
}

static void CheckUsb ( void )
{
    if ( IsUsbDataAvaialble ( HidInterfaceNumber ) > 0 ) {
        ProcessIncommingHidData();
        PrepareHidTxBuffer();
        ReArmInterface ( HidInterfaceNumber );

        while ( HIDSend ( HidInterfaceNumber ) == 0 );

    }

    if ( IsUsbDataAvaialble ( KbdInterfaceNumber ) > 0 ) {
        ProcessIncommingKbdData();
        ReArmInterface ( KbdInterfaceNumber );
    }
}

// correct sequence to mimic
//
// 04 00 00 00 00 00 00 00 ALT KEY PRESS
// 04 00 57 00 00 00 00 00 KPPLUS
// 04 00 00 00 00 00 00 00 KPPLUS UP
// 04 00 1F 00 00 00 00 00 KEY 2
// 04 00 00 00 00 00 00 00 KEY 2 UP
// 04 00 22 00 00 00 00 00 KEY 5
// 04 00 00 00 00 00 00 00 KEY 5 UP
// 04 00 25 00 00 00 00 00 KEY 8
// 04 00 00 00 00 00 00 00 KEY 8 UP
// 04 00 21 00 00 00 00 00 KEY 4
// 04 00 00 00 00 00 00 00 KEY 4 UP
// 00 00 00 00 00 00 00 00 ALT KEY UP

// Convert our Unicode WORD value to key codes
//


void pressKeyLALT2 ( unsigned short value )
{
    BYTE lo, hi;

    hi = value >> 8;
    lo = value;

    pressKeyOnly ( 0, 0, 0, 0, 0, 0, 0 );

#define DELAY __delay_ms(55)

    pressKeyOnly ( KEY_MOD_LALT, 0, 0, 0, 0, 0, 0 );


    pressKeyOnly ( KEY_MOD_LALT, KEY_KPPLUS, 0, 0, 0, 0, 0 );
    pressKeyOnly ( KEY_MOD_LALT, 0, 0, 0, 0, 0, 0 );

    pressKeyOnly ( KEY_MOD_LALT, value2hex ( hi >> 4 ), 0, 0, 0, 0, 0 );
    pressKeyOnly ( KEY_MOD_LALT, 0, 0, 0, 0, 0, 0 );

    pressKeyOnly ( KEY_MOD_LALT, value2hex ( hi & 0xf ), 0, 0, 0, 0, 0 );
    pressKeyOnly ( KEY_MOD_LALT, 0, 0, 0, 0, 0, 0 );

    pressKeyOnly ( KEY_MOD_LALT, value2hex ( lo >> 4 ), 0, 0, 0, 0, 0 );
    pressKeyOnly ( KEY_MOD_LALT, 0, 0, 0, 0, 0, 0 );

    pressKeyOnly ( KEY_MOD_LALT, value2hex ( lo & 0xf ), 0, 0, 0, 0, 0 );

    pressKeyOnly ( 0, 0, 0, 0, 0, 0, 0 );

    DELAY;

#if 0

    controlTXBuffer[0] = value2hex ( hi >> 4 );
    controlTXBuffer[1] = value2hex ( hi & 0xf );
    controlTXBuffer[2] = value2hex ( lo >> 4 );
    controlTXBuffer[3] = value2hex ( lo & 0xf );

    controlTXBuffer[4] = hi >> 4;
    controlTXBuffer[5] = hi & 0xf;
    controlTXBuffer[6] = lo >> 4;
    controlTXBuffer[7] = lo & 0xf;


    controlTXBuffer[8] = 0xEE;
    controlTXBuffer[9] = 0xEE;
    controlTXBuffer[10] = 0xEE;
    controlTXBuffer[11] = 0xEE;
    controlTXBuffer[12] = 0xEE;
    controlTXBuffer[13] = 0xEE;
    controlTXBuffer[14] = 0xEE;
    controlTXBuffer[15] = 0xEE;


    ReArmInterface ( HidInterfaceNumber );

    while ( HIDSend ( HidInterfaceNumber ) == 0 );

#endif

}

void ProcessIO ( void )
{
    // check USB for incoming Commands
    if ( IsUsbReady ) {
        CheckUsb();
    }

    // check status of the button
    if ( Button == buttonStatus ) {
        return;
    }

    if ( !Button ) {

        // needs, (seems to miss first key if we don't do this)
        pressKey ( 0, 0, 0, 0, 0, 0, 0 );

        if ( flashBuffer[0] != 0xff ) {

            print ( flashBuffer );

        } else {

            //check if flash buffer isn't initialised  (otherwise custom message) 
            switch ( flashBuffer[1] ) {

                case 0:
                case 0xff:
#if SEND_MOD_STATUS
                {
                        char buffer[10];
                        sprintf(buffer," 0x%x ",getMODstate());
                        print(buffer);
                   }
#endif

                   // default string stored to send back to host
                   print("LayerOne 2023");

#if 0
                    // send a shruggie, needs the OS to be able to handle unicode input though
                    //
                    pressKeyLALT2 ( 0x02c9 ); //KEY_0,KEY_2,KEY_C,KEY_9 ); // 9 18
                    //pressKeyLALT2 ( 0x005c ); //KEY_0,KEY_0,KEY_5,KEY_C ); // 9 18
                    //pressKeyLALT2 ( 0x005f ); //KEY_0,KEY_0,KEY_5,KEY_F ); // 9 18
                    print ( " \\_(" );
                    //pressKeyLALT2 ( 0x0028 ); //KEY_0,KEY_0,KEY_2,KEY_8 ); // 9 18
                    pressKeyLALT2 ( 0x30c4 ); //KEY_3,KEY_0,KEY_C,KEY_4 ); // 9 18
                    //pressKeyLALT2 ( 0x0029 ); //KEY_0,KEY_0,KEY_2,KEY_9 ); // 9 18
                    //pressKeyLALT2 ( 0x005f ); //KEY_0,KEY_0,KEY_5,KEY_F ); // 9 18
                    print ( " )_/" );
                    //pressKeyLALT2 ( 0x002f ); //KEY_0,KEY_0,KEY_2,KEY_F ); // 9 18
                    pressKeyLALT2 ( 0x02c9 ); //KEY_0,KEY_2,KEY_C,KEY_9 ); // 9 18
#endif
                    
#if 0
                    //alt version
                    // hand
                    //pressKeyLALT ( KEY_0, KEY_2, KEY_C, KEY_9);
                    pressKeyLALT2 ( 0x2c9 );

                    // 0x27, 0x1f , 0x06, 0x26

                    // doesn't need (maybe)
                    // pressKey(0,0,0,0,0,0,0);

                    // arm+ partial face
                    print ( "\\\_\(" );

                    // face
                    //pressKeyLALT (  KEY_3, KEY_0, KEY_C, KEY_4 );
                    pressKeyLALT2 ( 0x30c4 );

                    // does need
                    //pressKey ( 0, 0, 0, 0, 0, 0, 0 );

                    // end of face, beginning of last arm
                    print ( ")_/" );

                    // last hand
                    //pressKeyLALT ( KEY_0, KEY_2, KEY_C, KEY_9);
                    pressKeyLALT2 ( 0x2c9 );
#endif
                    break;

                case 1:

                    print ( "( " );

                    pressKeyLALT2 ( 0x0361 );
                    pressKeyLALT2 ( 0x00B0 );
                    print ( " " );
                    pressKeyLALT2 ( 0x035C );
                    pressKeyLALT2 ( 0x0296 );
                    print ( " " );
                    pressKeyLALT2 ( 0x0361 );
                    pressKeyLALT2 ( 0x00B0 );
                    print ( ")" );


                    break;

                case 2: {

                        unsigned char  length;

                        // get the number of key sets
                        length = flashBuffer[2];

                        for ( unsigned char i = 0; i < length; i++ ) {

                            pressKeyLALT2 (

                                ( flashBuffer[ 3 + ( ( i * 2 ) + 0 ) ] << 8 ) +
                                flashBuffer[ 3 + ( ( i * 2 ) + 1 ) ]

                            );
                        }
                    }
                    break;
            }
        }

        // needs
        // pressKey ( 0, 0, 0, 0, 0, 0, 0 );
        
        // this delay might help with ghosting/debounce ( add a real debounce pls )
        // not really
        
        __delay_ms ( 1 );
    }

    // Save New Button Status
    buttonStatus = Button;
}

void main ( void )
{
    unsigned int r, index;
    unsigned long counter2 = 0, counter = 0;

    InitializeSystem();
    InitializeUSB();
    EnableUSBModule();
    EnableInterrupts();

    r = FLASH_readConfig ( 0x8000 );

    r = HEFLASH_readBlock ( flashBuffer, 1, FLASH_ROWSIZE );
    r = HEFLASH_readBlock ( &flashBuffer[FLASH_ROWSIZE], 2, FLASH_ROWSIZE );
    r = HEFLASH_readBlock ( &flashBuffer[FLASH_ROWSIZE * 2], 3, FLASH_ROWSIZE );
    r = HEFLASH_readBlock ( &flashBuffer[FLASH_ROWSIZE * 3], 4, FLASH_ROWSIZE );

    
    // run the LEDS, then process the usb io -- software counts... 
    while ( 1 ) {

        switch ( mode ) {

            case LED_COLORWHEEL:


                if ( counter == 20000 ) {
                    ColorWheel ( 100 );
                    counter = 0;
                }

                counter++;


                break;

            case LED_SLOWFADE:

                if ( counter == 5000 ) {

                    if ( index >= sizeof ( breathe ) ) {
                        index = 0;
                    }
 
                        ColorWheel ( 1 );
 
                    r = breathe[index];

                    Red[3] = r;
                    Green[3] = r;
                    Blue[3] = r;

                    OutputLEDDataStream();

                    index++;

                    counter = 0;

                }

                counter++;
                break;

            default:

                mode = 0;
                break;
        }

        if ( microseconds > (5000*5UL) ) {
            counter2 = 0;
            counter = 0;
            mode++;
            microseconds = 0 ;
        }

        counter2++;

        ProcessIO();
    }
}
