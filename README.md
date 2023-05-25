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
 
 
# Optional Programmer

Pickit 3 or better , Pickkit 2 supports CU with 3rd party sofware ,3 or 4 is recommended.

