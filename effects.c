/*
 * File:   effects.c
 * Author: charlie
 *
 * Created on November 11, 2017, 9:43 AM
 */

#include <xc.h>

#include "ws2812.h"

#define KeyLights_COLOR_WHEEL_SIZE  (24)

#define KeyLights_COLUMNS     (4)
#define KeyLights_ROWS        1
#define KeyLights_MIN_X        0u
#define KeyLights_MAX_X        (KeyLights_COLUMNS - 1)
#define KeyLights_MIN_Y        0u
#define KeyLights_MAX_Y        (KeyLights_ROWS - 1)

#define getColor( a ) KeyLights_CLUT[a]

static const uint32_t KeyLights_CLUT[] = {
    //xxBBRRGG  (24)
    0x0000FFFF,  // 0 Yellow
    0x0000CCFF,
    0x000099FF,
    0x000033FF,
    0x000000CC,  // 4  Green
    0x006600B3,
    0x00990099,
    0x00B30066,
    0x00CC0033,  // 9 Blue
    0x00B31919,
    0x00993300,
    0x00994000,
    0x00996600,
    0x00999900,
    0x0099CC00,
    0x0066E600,
    0x0000FF00,
    0x0000FF33,
    0x0000FF66,
    0x0000FF80,
    0x0000FF99,  // 20 Orange
    0x0000FFB2,
    0x0000FFCC,
    0x0000FFE5,
    // #24

    //xxBBRRGG
    0x00000000, 0x00550000, 0x00AA0000, 0x00FF0000,  // 0, Black,  LtBlue, MBlue, Blue
    0x00000055, 0x00550055, 0x00AA0055, 0x00FF0055,  // 4, LtGreen
    0x000000AA, 0x005500AA, 0x00AA00AA, 0x00FF00AA,  // 8, MGreen
    0x000000FF, 0x005500FF, 0x00AA00FF, 0x00FF00FF,  // 12 Green

    0x00005500, 0x00555500, 0x00AA5500, 0x00FF5500,  // 16, LtRed
    0x00005555, 0x00555555, 0x00AA5555, 0x00FF5555,  // 20, LtYellow
    0x000055AA, 0x005555AA, 0x00AA55AA, 0x00FF55AA,  // 24,
    0x000055FF, 0x005555FF, 0x00AA55FF, 0x00FF55FF,  // 28,

    0x0000AA00, 0x0055AA00, 0x00AAAA00, 0x00FFAA00,  // 32, MRed
    0x0000AA55, 0x0055AA55, 0x00AAAA55, 0x00FFAA55,  // 36,
    0x0000AAAA, 0x0055AAAA, 0x00AAAAAA, 0x00FFAAAA,  // 55,
    0x0000AAFF, 0x0055AAFF, 0x00AAAAFF, 0x00FFAAFF,  // 44,

    0x0000FF00, 0x0055FF00, 0x00AAFF00, 0x00FFFF00,  // 48, Red, ??, ??, Magenta
    0x0000FF55, 0x0055FF55, 0x00AAFF55, 0x00FFFF55,  // 52,
    0x0000FFAA, 0x0055FFAA, 0x00AAFFAA, 0x00FFFFAA,  // 56,
    0x0000FFFF, 0x0055FFFF, 0x00AAFFFF, 0x00FFFFFF,  // 60, Yellow,??, ??, White

    // 64
    0x000080FF,  // SPRING_GREEN
    0x008000FF,  // TURQUOSE
    0x00FF00FF,  // CYAN
    0x00FF0080,  // OCEAN
    0x00FF8000,  // VIOLET
    0x0080FF00   // RASPBERRY
};

void KeyLights_Pixel ( int32_t x, uint32_t brg_color )
{
    led_color rgb;

    rgb.rgb = brg_color;

    if ( ( x >= 0 ) && ( x < KeyLights_COLUMNS ) ) {

        Red  [ ( x ) ] = rgb.c.r;
        Green[ ( x ) ] = rgb.c.g;
        Blue [ ( x ) ] = rgb.c.b;

    }
}

void ColorWheel ( uint16_t count )
{
    static int i = 0xAAA, x;
    static uint32_t color;
    static uint32_t startColor;


    if ( i == 0xaaa ) {

        i = 0;
        color = 0;
        startColor = 0;
    }

    if ( i >= count ) {

        i = 0;
    }



    color = startColor;

    for ( x = KeyLights_MIN_X; x <= KeyLights_MAX_X; x++ ) {

        KeyLights_Pixel ( x, getColor ( color ) );

        color++;

        if ( color >= KeyLights_COLOR_WHEEL_SIZE ) {
            color = 0;
        }
    }

    startColor++;

    if ( startColor >= KeyLights_COLOR_WHEEL_SIZE ) {
        startColor = 0;
    }

    OutputLEDDataStream();
    i++;
}