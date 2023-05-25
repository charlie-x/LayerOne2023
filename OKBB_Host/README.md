# OKBB Host


Windows Version of OKBB Macro uploader build with Visual Studoi 2022 , select X86 build


# how to upload to the HID flash

    int uploadToFlash ( unsigned char *inputBuffer )
    {
      unsigned char tempBuffer[20];

      int res;
    
    if ( inputBuffer == NULL ) {
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

		    _RPT4(_CRT_WARN, "uploadToFlash  [0x%02x] [%d] [%s] [%d]\n", tempBuffer[1] , tempBuffer[2] , &tempBuffer[3], 16);

        //write to HID
        res = hid_write ( handle, tempBuffer, 16 + 1 );
        if (res == -1) {
            return res;
        }
    }

    tempBuffer[0] = 0;
    
    // write from internal ram to flash(HE)
    tempBuffer[1] = 0xfd;

    res = hid_write ( handle, tempBuffer, 16 + 1 );

    return res;
}


