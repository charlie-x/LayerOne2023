# LayerOne2023


# Hardware

PIC16F1455

WS2812B/SK6812

# Software Needed

Microchip MPLAB 6.10

  https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide
  
XC8 2.41

  https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers/downloads-documentation#XC8
  

# DFU mode bootloader

 Badge has a DFU loader, hold the button down while plugging in USB should appear as device
 In Windows use ZADIG https://github.com/pbatard/libwdi/releases/download/v1.5.0/zadig-2.8.exe to change the driver to WinUSB device ID will be 1209:2002
 Modified Bootloader code is at https://github.com/charlie-x/PIC16F1455_Bootloader full fork https://github.com/charlie-x/PIC16F1455_Bootloader with tools
 
# dfu-utils to upload to badge
 
 convert hex file from Bootloader MPLAB project ( must use the HTxxxxxx_BootLoader version )
 
 get 454hex2dfu here https://github.com/charlie-x/PIC16F1-USB-DFU-Bootloader/tree/master/tools 
 
  454hex2dfu input.hex OKBBPIC_firmware.production.dfu
 
 put badge in DFU mode by holding button down and plugging into usb. (only when L1 bootloader is installed, if its overwritten you have to reinstall it with a PIC programmer like the pickkit3)
 
  dfu-util  -l -D OKBBPIC_firmware.production.dfu -R
 
# Optional Programmer

Pickit 3 or better , Pickit 2 supports CU with 3rd party sofware ,3 or 4 is recommended.



# badge competition

there is a very partial rubberducky 2.0 script commented out in the code, whoever makes it run duckyscript first, wins the single prize. claim with charliex, mmca or datagram. 
