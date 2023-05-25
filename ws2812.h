#ifndef _WS2812_H_ 
#define  _WS2812_H_         ( 1 )

#include <htc.h>
#include <stdint.h>

#define NUMBER_OF_LEDS      ( 4 )
#define _XTAL_FREQ             48000000

typedef union rgb_t {

    uint32_t rgb;

    struct rgb_tag {
        uint8_t b, r, g, pad;
    } c;

} led_color;

enum {
    LED_COLORWHEEL,
    LED_SLOWFADE,
    LED_NONE
};


extern unsigned char Green[NUMBER_OF_LEDS] ;
extern unsigned char Red[NUMBER_OF_LEDS]  ;
extern unsigned char Blue[NUMBER_OF_LEDS] ;

void OutputLEDDataStream(void);
void ColorWheel ( uint16_t count );
void ProcessIO ( void );

#endif
