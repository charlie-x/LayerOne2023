#ifndef USBDESCRIPTORS_H
#define	USBDESCRIPTORS_H

#include "GenericTypeDefs.h"

// Vendor and Product Information
#define VendorId                0x0032
#define ProductId               0x0808
#define ReleaseNo               0x0001

// Definitions
#define InterfaceCount          0x02 // Three Interfaces - Generic HID = 0, Keyboard = 1
#define StringDescriptorCount   0x05 // Six string descriptors - See Bottom of this file
#define Endpoint0BufferSize     0x08 // Endpoint 0 Buffer Size
#define HidDescriptorSize       0x59 // Size Of HID Descriptor
// HID
#define HidReportByteCount      0x10 // Hid Report Size, also size of Buffers etc. ( Memory usage can go over the roof if not careful with this value)
#define KbdReportByteCount      0x08 // Keyboard Report Size

#define HidInterfaceNumber      0x00 // Interface For HID
#define KbdInterfaceNumber      0x01 // Interface For Keyboard

// Strings
#define SMAN 0x01   // Manufacturer Name String Index
#define SPRD 0x02   // Product Name String Index
#define SSER 0x00   // Serial Number String Index
#define SCON 0x00   // Configuration String Index
#define SHID 0x03   // Configuration String Index
#define SKBD 0x04   // Configuration String Index
#define SMSE 0x05   // Configuration String Index

// Actual USB Data Buffers
volatile unsigned char controlRXBuffer[HidReportByteCount];
volatile BYTE controlTXBuffer[HidReportByteCount];
volatile BYTE keyboardRXBuffer[KbdReportByteCount];
volatile BYTE KBDTxBuffer[KbdReportByteCount];

BufferInfo Buffers[(InterfaceCount * 2)] =
{
    { HidReportByteCount, controlTXBuffer },
    { HidReportByteCount, controlRXBuffer },
    { KbdReportByteCount, keyboardRXBuffer },
    { KbdReportByteCount, KBDTxBuffer }
};

/***********************/
/* Descriptors         */
/***********************/

// Device Descriptor
const BYTE DeviceDescriptor[]=
{
    0x12,   // Size of this descriptor in bytes
    0x01,   // DEVICE descriptor type
    0x00,   // USB Spec Release Number in BCD format LSB
    0x02,   // USB Spec Release Number in BCD format MSB
    0x00,   // Class Code
    0x00,   // Subclass code
    0x00,   // Protocol code
    E0SZ,   // Max packet size for EP0 (8)
    VIDL,   // Vendor ID LSB
    VIDH,   // Vendor ID MSB
    PIDL,   // Product ID: Custom HID device demo LSB
    PIDH,   // Product ID: Custom HID device demo MSB
    RELL,   // Device release number in BCD format LSB
    RELH,   // Device release number in BCD format MSB
    SMAN,   // Manufacturer string index
    SPRD,   // Product string index
    SSER,   // Device serial number string index
    0x01    // Number of possible configurations
};

// ...Stuck these here to keep the number of files to minimum
#define HRBC HidReportByteCount
#define KRBC KbdReportByteCount

typedef struct _configStruct
{
    BYTE configHeader[CONFIG_HEADER_SIZE];
    BYTE HIDDescriptor[HidDescriptorSize];
} ConfigStruct;

// Configuration descriptor
const ConfigStruct ConfigurationDescriptor =
{
    {
       // Configuration descriptor
    0x09,   // Size of this descriptor in bytes
    0x02,   // CONFIGURATION descriptor type
    0x62,   // Total length of data for this cfg LSB
    0x00,   // Total length of data for this cfg MSB
    INTF,   // Number of interfaces in this cfg
    0x01,   // Index value of this configuration
    SCON,   // Configuration string index
    0xA0,   // Attributes
    0x32,   // Max power consumption (50 mA)
    },
    {
        // Generic HID Interface descriptor
    0x09,   // Size of this descriptor in bytes
    0x04,   // INTERFACE descriptor type
    IHID,   // Interface Number
    0x00,   // Alternate Setting Number
    0x02,   // Number of endpoints in this interface
    0x03,   // Class code (HID)
    0x00,   // Subclass code
    0x00,   // Protocol code 0-none, 1-Keyboard, 2- Mouse
    SHID,   // Interface string index

        // Generic Hid Class-Specific descriptor
    0x09,   // Size of this descriptor in bytes
    0x21,   // HID descriptor type
    0x11,   // HID Spec Release Number in BCD format (1.11) LSB
    0x01,   // HID Spec Release Number in BCD format (1.11) MSB
    0x00,   // Country Code (0x00 for Not supported)
    0x01,   // Number of class descriptors
    0x22,   // Report descriptor type
    0x2F,   // Report Size LSB  (47 bytes)
    0x00,   // Report Size MSB

    	// Generic HID Endpoint 1 In
    0x07,   // Size of this descriptor in bytes
    0x05,   // ENDPOINT descriptor type
    0x81,   // Endpoint Address
    0x03,   // Attributes (Interrupt)
    HRBC,   // Max Packet Size LSB
    0x00,   // Max Packet Size MSB
    0x01,   // Interval (1 millisecond)

    	// Generic HID Endpoint 1 Out
    0x07,   // Size of this descriptor in bytes
    0x05,   // ENDPOINT descriptor type
    0x01,   // Endpoint Address
    0x03,   // Attributes (Interrupt)
    HRBC,   // Max Packet Size LSB
    0x00,   // Max Packet Size MSB
    0x01,   // Interval (1 millisecond)

        // Keyboard HID Interface descriptor
    0x09,   // Size of this descriptor in bytes
    0x04,   // INTERFACE descriptor type
    IKBD,   // Interface Number
    0x00,   // Alternate Setting Number
    0x02,   // Number of endpoints in this interface
    0x03,   // Class code (HID)
    0x01,   // Subclass code (Sublass Boot(1) as opposed to NONE(0) the rest reserved)
    0x01,   // Protocol code 0-none, 1-Keyboard, 2- Mouse
    SKBD,   // Interface String Descriptor Index

        // Keyboard Class-Specific descriptor
    0x09,   // Size of this descriptor in bytes
    0x21,   // HID descriptor type
    0x11,   // HID Spec Release Number in BCD format (1.11) LSB
    0x01,   // HID Spec Release Number in BCD format (1.11) MSB
    0x00,   // Country Code (0x00 for Not supported)
    0x01,   // Number of class descriptors
    0x22,   // Report descriptor type
    0x3F,   // Report Size LSB  (63 bytes)
    0x00,   // Report Size MSB

    	// Keyboard Endpoint 2 In
    0x07,   // Size of this descriptor in bytes
    0x05,   // ENDPOINT descriptor type
    0x82,   // Endpoint Address
    0x03,   // Attributes (Interrupt)
    KRBC,   // Max Packet Size LSB
    0x00,   // Max Packet Size MSB
    0x01,   // Interval (1 millisecond)

    	// Keyboard Endpoint 2 Out
    0x07,   // Size of this descriptor in bytes
    0x05,   // ENDPOINT descriptor type
    0x02,   // Endpoint Address
    0x03,   // Attributes (Interrupt)
    KRBC,   // Max Packet Size LSB
    0x00,   // Max Packet Size MSB
    0x01   // Interval (1 millisecond)

    }
};

// Report For Generic HID
const BYTE HIDReport[] = {
    0x06, 0xa0, 0xff,  // USAGE_PAGE (Vendor Defined Page 1)
    0x09, 0x01,        // USAGE (Vendor Usage 1)
    0xa1, 0x01,        // COLLECTION (Application)

	// The Input report
	0x09, 0x01,     	// Usage ID - vendor defined
	0x15, 0x00,     	// Logical Minimum (0)
	0x26, 0xFF, 0x00,       // Logical Maximum (255)
	0x75, 0x08,     	// Report Size (8 bits)
	0x95, HRBC,     	// Report Count
	0x81, 0x02,     	// Input (Data, Variable, Absolute)

	// The Output report
	0x09, 0x01,     	// Usage ID - vendor defined
	0x15, 0x00,     	// Logical Minimum (0)
	0x26, 0xFF, 0x00,       // Logical Maximum (255)
	0x75, 0x08,     	// Report Size (8 bits)
	0x95, HRBC,     	// Report Count
	0x91, 0x02,      	// Output (Data, Variable, Absolute)

	// The Feature report
	0x09, 0x02,     	// Usage ID - vendor defined
	0x15, 0x00,     	// Logical Minimum (0)
	0x26, 0xFF, 0x00,       // Logical Maximum (255)
	0x75, 0x08,     	// Report Size (8 bits)
	0x95, HRBC,     	// Report Count
	0xB1, 0x02,      	// Feature (Data, Variable, Absolute)

    0xc0               // END_COLLECTION
};

// Report For Keyboard
const BYTE KBDReport[] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,                    // USAGE (Keyboard)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x95, 0x08,                    //   REPORT_COUNT (8)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
    0x95, 0x05,                    //   REPORT_COUNT (5)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x05, 0x08,                    //   USAGE_PAGE (LEDs)
    0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
    0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
    0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
    0x95, 0x01,                    //   REPORT_COUNT (1)
    0x75, 0x03,                    //   REPORT_SIZE (3)
    0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
    0x95, 0x06,                    //   REPORT_COUNT (6)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};


const BYTE *const ReportDescriptorPointers[InterfaceCount]=
{
    (const BYTE *const)HIDReport,
    (const BYTE *const)KBDReport
};

const struct{BYTE bLength;BYTE bDscType;WORD string[1];}StringDescriptor0={sizeof(StringDescriptor0),0x03,{0x0409}};

const struct{BYTE bLength;BYTE bDscType;WORD string[11];}SD_OEM={sizeof(SD_OEM),0x03,
    {'[','N','U','L','L','S','p','a','c','e',']'}
};

const struct{BYTE bLength;BYTE bDscType;WORD string[25];}SD_HIDGeneric={sizeof(SD_HIDGeneric),0x03,
{'O','K','B','B',' ','C','o','m','p','o','s','i','t','e',' ','H','I','D',' ','D','e','v','i','c','e'}};

const struct{BYTE bLength;BYTE bDscType;WORD string[18];}SD_HIDDevice={sizeof(SD_HIDDevice),0x03,
{'O','K','K','B',' ','L','E','D',' ','I','n','t','e','r','f','a','c','e'}};

const struct{BYTE bLength;BYTE bDscType;WORD string[26];}SD_HIDKeyboard={sizeof(SD_HIDKeyboard),0x03,
{'N','S','L',' ','O','n','e','K','e','y',' ','K','e','y','b','o','a','r','d',' ','P','I','C','V','E','R'}};


//Array of string descriptors
const BYTE *const StringDescriptorPointers[StringDescriptorCount]=
{
    (const BYTE *const)&StringDescriptor0,
    (const BYTE *const)&SD_OEM,
    (const BYTE *const)&SD_HIDGeneric,
    (const BYTE *const)&SD_HIDDevice,
    (const BYTE *const)&SD_HIDKeyboard

};

#endif	/* USBDESCRIPTORS_H */

