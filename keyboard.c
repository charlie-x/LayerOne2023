/*
 * File:   keyboard.c
 * Author: charlie
 *
 * Created on November 5, 2017, 10:57 AM
 */

#include "keyboard.h"

void ascii2scan ( unsigned char ascii, unsigned char ledState, unsigned char* modifier, unsigned char* keyCode )
{
    *keyCode = 0x00;
    *modifier = 0x00;

    if ( ascii >= 'A' && ascii <= 'Z' ) {
        *keyCode = 4U + ascii - (unsigned char)('A'); // set letter

        if ( is_bit_set ( ledState, 1 ) ) { // if caps is on
            *modifier = 0x00; // no shift

        } else {
            *modifier = _bitTest ( 1 ); // hold shift // hold shift
        }

    } else if ( ascii >= 'a' && ascii <= 'z' ) {
        *keyCode = 4 + ascii - 'a'; // set letter

        if ( is_bit_set ( ledState, 1 ) ) { // if caps is on
            *modifier = _bitTest ( 1 ); // hold shift // hold shift

        } else {
            *modifier = 0x00; // no shift
        }

    } else if ( ascii >= '0' && ascii <= '9' ) {
        *modifier = 0x00;

        if ( ascii == '0' ) {
            *keyCode = KEY_0;

        } else {
            *keyCode = 30 + ascii - '1';
        }

    } else {
        switch ( ascii ) { // convert ASCII  to key code
            case '!':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 1;
                break;

            case '@':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 2;
                break;

            case '#':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 3;
                break;

            case '$':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 4;
                break;

            case '%':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 5;
                break;

            case '^':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 6;
                break;

            case '&':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 7;
                break;

            case '*':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 8;
                break;

            case '(':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = 29 + 9;
                break;

            case ')':
                *modifier = _bitTest ( 1 ); // hold shift
                *keyCode = KEY_0;
                break;

            case '~':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '`':
                *keyCode = KEY_GRAVE;
                break;

            case '_':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '-':
                *keyCode = KEY_MINUS;
                break;

            case '+':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '=':
                *keyCode = KEY_EQUAL;
                break;

            case '{':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '[':
                *keyCode = KEY_LEFTBRACE;
                break;

            case '}':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case ']':
                *keyCode = KEY_RIGHTBRACE;
                break;

            case '|':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '\\':
                *keyCode = KEY_BACKSLASH;
                break;

            case ':':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case ';':
                *keyCode = KEY_SEMICOLON;
                break;

            case '"':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '\'':
                *keyCode = KEY_APOSTROPHE;
                break;

            case '<':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case ',':
                *keyCode = KEY_COMMA;
                break;

            case '>':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '.':
                *keyCode = KEY_DOT;
                break;

            case '?':
                *modifier = _bitTest ( 1 ); // hold shift

            // fall through
            case '/':
                *keyCode = KEY_SLASH;
                break;

            case ' ':
                *keyCode = KEY_SPACE;
                break;

            case '\t':
                *keyCode = KEY_TAB;
                break;

            case '\n':
                *keyCode = KEY_ENTER;
                break;
        }
    }
}

// convert a 0-9-AF hex to a scancode
BYTE value2hex ( BYTE value )
{
    switch ( value ) {
        case 0:
            return KEY_0;

        case 1:
            return KEY_1;

        case 2:
            return KEY_2;

        case 3:
            return KEY_3;

        case 4:
            return KEY_4;

        case 5:
            return KEY_5;

        case 6:
            return KEY_6;

        case 7:
            return KEY_7;

        case 8:
            return KEY_8;

        case 9:
            return KEY_9;

        case 0xA:
            return KEY_A;

        case 0xB:
            return KEY_B;

        case 0xC:
            return KEY_C;

        case 0xD:
            return KEY_D;

        case 0xE:
            return KEY_E;

        case 0xF:
            return KEY_F;
    }

    return 0;
}

void pressKeyOnly ( BYTE modifiers, BYTE keycode1, BYTE keycode2, BYTE keycode3, BYTE keycode4, BYTE keycode5, BYTE keycode6 )
{
    KBDTxBuffer[0] = modifiers;
    KBDTxBuffer[1] = 0;             // reserved
    KBDTxBuffer[2] = keycode1;
    KBDTxBuffer[3] = keycode2;
    KBDTxBuffer[4] = keycode3;
    KBDTxBuffer[5] = keycode4;
    KBDTxBuffer[6] = keycode5;
    KBDTxBuffer[7] = keycode6;

    while (    HIDSend ( KbdInterfaceNumber ) == 0 );

}

void pressKey ( BYTE modifiers, BYTE keycode1, BYTE keycode2, BYTE keycode3, BYTE keycode4, BYTE keycode5, BYTE keycode6 )
{
    // construct the report, follow the standard format as described
    // this format is compatible with "boot protocol"

    KBDTxBuffer[0] = modifiers;
    KBDTxBuffer[1] = 0;             // reserved
    KBDTxBuffer[2] = keycode1;
    KBDTxBuffer[3] = keycode2;
    KBDTxBuffer[4] = keycode3;
    KBDTxBuffer[5] = keycode4;
    KBDTxBuffer[6] = keycode5;
    KBDTxBuffer[7] = keycode6;

    while (    HIDSend ( KbdInterfaceNumber ) == 0 );

    // __delay_ms(10);

    //PrepareHidTxBuffer();
    //while(     HIDSend(HidInterfaceNumber) == 0 );

    KBDTxBuffer[0] = modifiers;
    KBDTxBuffer[1] = 0;
    KBDTxBuffer[2] = 0;
    KBDTxBuffer[3] = 0;
    KBDTxBuffer[4] = 0;
    KBDTxBuffer[5] = 0;
    KBDTxBuffer[6] = 0;
    KBDTxBuffer[7] = 0;

    while (    HIDSend ( KbdInterfaceNumber ) == 0 );

}

unsigned char typeChar ( BYTE ascii )
{
    BYTE modifier, keycode;

    ascii2scan ( ascii, getLEDstate(), &modifier, &keycode );

    // key down
    pressKey ( modifier, keycode, 0, 0, 0, 0, 0 );

    // key up
    pressKey ( 0, 0, 0, 0, 0, 0, 0 );

    return 1;
}

int strlen ( char* str )
{
    if ( !str ) {
        return 0;
    }

    char* ptr = str;

    while ( *str ) {
        ++str;
    }

    return str - ptr;
}

size_t print ( const BYTE* buffer )
{
    size_t  size ;
    size_t n = 0;

    size = (size_t)strlen ((unsigned char*) buffer );

    while ( size-- ) {
        if ( typeChar ( *buffer++ ) )
        { n++; }

        else
        { break; }
    }

    return n;
}
