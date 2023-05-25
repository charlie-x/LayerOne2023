#include <htc.h>

#include "ws2812.h"

#define LEDDataStreamOutputPin RC3

static unsigned char ByteOut;

// starting values/buffer for RGB Leds
unsigned char Green[NUMBER_OF_LEDS] = {100,   0,   0, 50};
unsigned char Red[NUMBER_OF_LEDS]   = {  0, 100,   0, 50};
unsigned char Blue[NUMBER_OF_LEDS]  = {  0,   0, 100, 50};

// how much to dim RGB leds by 
unsigned char dim = 3;


// Bit bang to the LEDs
void OutputAZeroBit(void) {
    LEDDataStreamOutputPin = 1;

    asm("nop");
    asm("nop");

    LEDDataStreamOutputPin = 0;

    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");

}

//
void OutputAOneBit(void) {
    LEDDataStreamOutputPin = 1;

    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");

    LEDDataStreamOutputPin = 0;

    asm("nop");
    asm("nop");
    asm("nop");

}

//

void
OutputByte(void) {
    
    // data sent to the LEDs must be sent MSB first
    
    for (int i = 1; i <= 8; i++) {
        if (ByteOut > 127) // Is MSB on?
            OutputAOneBit();
        else
            OutputAZeroBit();

        ByteOut = ByteOut * 2; // shift left one bit
    }
}



void OutputLEDDataStream(void) {

    for (int j = 0; j < NUMBER_OF_LEDS; j++) {
        ByteOut =  Green[j] >> dim ; 
        OutputByte();

        ByteOut = Red[j] >> dim ;
        OutputByte();

        ByteOut = Blue[j] >> dim ;
        OutputByte();
    }
    
     __delay_us(50);  
}
