#ifndef USB_H
#define	USB_H

// Macros
#define PTR16(x)                        ((unsigned int)(((unsigned long)x) & 0xFFFF))
#define LSB(x)                          (x & 0xFF)
#define MSB(x)                          ((x & 0xFF00) >> 8)

#define ClearUsbInterruptFlag(x)        UIR &= ~(x)
#define IsUsbReady                      ((DeviceState == 0x05) && (UCONbits.SUSPND==0))
#define UsbInterrupt                    PIR2bits.USBIF

#define VIDL LSB(VendorId)  // Vendor Id Low Byte (LSB)
#define VIDH MSB(VendorId)  // Vendor Id High Byte (MSB)
#define PIDH MSB(ProductId) // Product Id High Byte (MSB)
#define PIDL LSB(ProductId) // Product Id Low Byte (LSB)
#define RELH MSB(ReleaseNo) // Release Number High Byte (MSB)
#define RELL LSB(ReleaseNo) // Release Number Low Byte (LSB)

#define INTF    InterfaceCount // Total Count of Interfaces
#define IHID    HidInterfaceNumber
#define IKBD    KbdInterfaceNumber
#define IMSE    MseInterfaceNumber
#define E0SZ    Endpoint0BufferSize

#define CONFIG_HEADER_SIZE      0x09 // Configuration descriptor header size (see UsbDescriptors.h) - Pretty much always 9 :)

#include "GenericTypeDefs.h"

// Structures
typedef struct _BufferInfo
{
    BYTE Size;
    volatile BYTE *Buffer;
} BufferInfo;

// Includes
#include "UsbDescriptors.h"

// Global Variables
BYTE DeviceState;    // Visible device states (from USB 2.0, chap 9.1.1)

// USB Functions
void InitializeUSB(void);
void EnableUSBModule(void);
unsigned char HIDSend(BYTE InterfaceNo);
void ProcessUSBTransactions(void);
void ReArmInterface(BYTE InterfaceNo);
BYTE IsUsbDataAvaialble(BYTE InterfaceNo);

#endif	/* USB_H */

