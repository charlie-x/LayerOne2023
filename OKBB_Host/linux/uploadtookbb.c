#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <hidapi/hidapi.h>

int uploadToFlash ( unsigned char *inputBuffer )
{
    unsigned char tempBuffer[20];

    int res;

    // attempt to open device
    hid_device* handle = hid_open ( 0x0032, 0x0808, NULL );
    if( handle == 0 ) {
        fprintf(stderr,"failed to open okbb device\n");
        return -2;
    }

    if ( inputBuffer == NULL ) {
        fprintf(stderr,"empty string to send\n");
        return -1;
    }

    memset ( tempBuffer, 0, sizeof ( tempBuffer ) );

    tempBuffer[ 0 ] = 0;

// write to internal buffer
    tempBuffer[ 1 ] = 0xfe;

    for ( unsigned int index = 0; index < 16; index++ ) {

        // 0..15 index for offset of internal buffer to write 8 bytes too
        tempBuffer[ 2 ] = index;

        // buf 3 to 3+8 is the data
        memcpy ( &tempBuffer[3], inputBuffer, 8 );

        // skip into buffer
        inputBuffer += 8;

        //write to HID
        res = hid_write ( handle, tempBuffer, 16 + 1 );

        if (res == -1) {
            fprintf(stderr,"failed to upload to okbb\n");
            hid_close(handle);
            return res;
        }
    }

    tempBuffer[0] = 0;

// write from internal ram to flash(HE)
    tempBuffer[1] = 0xfd;

    res = hid_write ( handle, tempBuffer, 16 + 1 );

    hid_close(handle);

    return res;
}

int main(int argc, char*argv[])
{
    if( argc >1  ) {
        uploadToFlash( argv[1]) ;
    }

    hid_exit();

}

