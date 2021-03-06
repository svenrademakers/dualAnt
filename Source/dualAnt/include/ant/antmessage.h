/* ANT PROTOCOL LIBRARY INTERFACE - DO NOT MODIFY!
 *
 * Dynastream Innovations Inc.
 * Cochrane, AB, CANADA
 *
 * Copyright � 1998-2008 Dynastream Innovations Inc.
 * All rights reserved. This software may not be reproduced by
 * any means without express written approval of Dynastream
 * Innovations Inc.
 */
#ifndef ANTMESSAGE_H
#define ANTMESSAGE_H

#include "types.h"
#include "antdefines.h"

/////////////////////////////////////////////////////////////////////////////
// Message Format
// Messages are in the format:
//
// AX XX YY -------- CK
//
// where: AX    is the 1 byte sync byte either transmit or recieve
//        XX    is the 1 byte size of the message (0-249) NOTE: THIS WILL BE LIMITED BY THE EMBEDDED RECEIVE BUFFER SIZE
//        YY    is the 1 byte ID of the message (1-255, 0 is invalid)
//        ----- is the data of the message (0-249 bytes of data)
//        CK    is the 1 byte Checksum of the message
/////////////////////////////////////////////////////////////////////////////
#define MESG_TX_SYNC                         ((UCHAR)0xA4)
#define MESG_RX_SYNC                         ((UCHAR)0xA5)
#define MESG_SYNC_SIZE                       ((UCHAR)1)
#define MESG_SIZE_SIZE                       ((UCHAR)1)
#define MESG_ID_SIZE                         ((UCHAR)1)
#define MESG_CHANNEL_NUM_SIZE                ((UCHAR)1)
#define MESG_EXT_MESG_BF_SIZE                ((UCHAR)1)  // NOTE: this could increase in the future
#define MESG_CHECKSUM_SIZE                   ((UCHAR)1)
#define MESG_DATA_SIZE                       ((UCHAR)9)

// The largest serial message is an ANT data message with all of the extended fields
#define MESG_ANT_MAX_PAYLOAD_SIZE            ANT_STANDARD_DATA_PAYLOAD_SIZE

#define MESG_MAX_EXT_DATA_SIZE               (ANT_EXT_MESG_DEVICE_ID_FIELD_SIZE + 4 + 2) // ANT device ID (4 bytes) +  (4 bytes) +  (2 bytes)

#define MESG_MAX_DATA_SIZE                   (MESG_ANT_MAX_PAYLOAD_SIZE + MESG_EXT_MESG_BF_SIZE + MESG_MAX_EXT_DATA_SIZE) // ANT data payload (8 bytes) + extended bitfield (1 byte) + extended data (10 bytes)
#define MESG_MAX_SIZE_VALUE                  (MESG_MAX_DATA_SIZE + MESG_CHANNEL_NUM_SIZE)  // this is the maximum value that the serial message size value is allowed to be
#define MESG_BUFFER_SIZE                     (MESG_SIZE_SIZE + MESG_ID_SIZE + MESG_CHANNEL_NUM_SIZE + MESG_MAX_DATA_SIZE + MESG_CHECKSUM_SIZE)
#define MESG_FRAMED_SIZE                     (MESG_ID_SIZE + MESG_CHANNEL_NUM_SIZE + MESG_MAX_DATA_SIZE)
#define MESG_HEADER_SIZE                     (MESG_SYNC_SIZE + MESG_SIZE_SIZE + MESG_ID_SIZE)
#define MESG_FRAME_SIZE                      (MESG_HEADER_SIZE + MESG_CHECKSUM_SIZE)

#define MESG_SIZE_OFFSET                     (MESG_SYNC_SIZE)
#define MESG_ID_OFFSET                       (MESG_SYNC_SIZE + MESG_SIZE_SIZE)
#define MESG_DATA_OFFSET                     (MESG_HEADER_SIZE)
#define MESG_RECOMMENDED_BUFFER_SIZE         ((UCHAR) 64)                         // This is the recommended size for serial message buffers if there are no RAM restrictions on the system

//////////////////////////////////////////////
// Message ID's
//////////////////////////////////////////////
#define MESG_INVALID_ID                      ((UCHAR)0x00)
#define MESG_EVENT_ID                        ((UCHAR)0x01)

#define MESG_VERSION_ID                      ((UCHAR)0x3E)
#define MESG_RESPONSE_EVENT_ID               ((UCHAR)0x40)

#define MESG_UNASSIGN_CHANNEL_ID             ((UCHAR)0x41)
#define MESG_ASSIGN_CHANNEL_ID               ((UCHAR)0x42)
#define MESG_CHANNEL_MESG_PERIOD_ID          ((UCHAR)0x43)
#define MESG_CHANNEL_SEARCH_TIMEOUT_ID       ((UCHAR)0x44)
#define MESG_CHANNEL_RADIO_FREQ_ID           ((UCHAR)0x45)
#define MESG_NETWORK_KEY_ID                  ((UCHAR)0x46)
#define MESG_RADIO_TX_POWER_ID               ((UCHAR)0x47)
#define MESG_RADIO_CW_MODE_ID                ((UCHAR)0x48)
#define MESG_SEARCH_WAVEFORM_ID              ((UCHAR)0x49)

#define MESG_SYSTEM_RESET_ID                 ((UCHAR)0x4A)
#define MESG_OPEN_CHANNEL_ID                 ((UCHAR)0x4B)
#define MESG_CLOSE_CHANNEL_ID                ((UCHAR)0x4C)
#define MESG_REQUEST_ID                      ((UCHAR)0x4D)

#define MESG_BROADCAST_DATA_ID               ((UCHAR)0x4E)
#define MESG_ACKNOWLEDGED_DATA_ID            ((UCHAR)0x4F)
#define MESG_BURST_DATA_ID                   ((UCHAR)0x50)

#define MESG_CHANNEL_ID_ID                   ((UCHAR)0x51)
#define MESG_CHANNEL_STATUS_ID               ((UCHAR)0x52)
#define MESG_RADIO_CW_INIT_ID                ((UCHAR)0x53)
#define MESG_CAPABILITIES_ID                 ((UCHAR)0x54)

#define MESG_STACKLIMIT_ID                   ((UCHAR)0x55)

#define MESG_SCRIPT_DATA_ID                  ((UCHAR)0x56)
#define MESG_SCRIPT_CMD_ID                   ((UCHAR)0x57)

#define MESG_ID_LIST_ADD_ID                  ((UCHAR)0x59)
#define MESG_ID_LIST_CONFIG_ID               ((UCHAR)0x5A)
#define MESG_OPEN_RX_SCAN_ID                 ((UCHAR)0x5B)

#define MESG_EXT_CHANNEL_RADIO_FREQ_ID       ((UCHAR)0x5C)  // OBSOLETE: (for 905 radio)
#define MESG_EXT_BROADCAST_DATA_ID           ((UCHAR)0x5D)
#define MESG_EXT_ACKNOWLEDGED_DATA_ID        ((UCHAR)0x5E)
#define MESG_EXT_BURST_DATA_ID               ((UCHAR)0x5F)

#define MESG_CHANNEL_RADIO_TX_POWER_ID       ((UCHAR)0x60)
#define MESG_GET_SERIAL_NUM_ID               ((UCHAR)0x61)
#define MESG_GET_TEMP_CAL_ID                 ((UCHAR)0x62)
#define MESG_SET_LP_SEARCH_TIMEOUT_ID        ((UCHAR)0x63)
#define MESG_SET_TX_SEARCH_ON_NEXT_ID        ((UCHAR)0x64)
#define MESG_SERIAL_NUM_SET_CHANNEL_ID_ID    ((UCHAR)0x65)
#define MESG_RX_EXT_MESGS_ENABLE_ID          ((UCHAR)0x66)  
#define MESG_RADIO_CONFIG_ALWAYS_ID          ((UCHAR)0x67)
#define MESG_ENABLE_LED_FLASH_ID             ((UCHAR)0x68)
#define MESG_LED_OVERIDE_ID                  ((UCHAR)0x69)

#define MESG_AGC_CONFIG_ID                   ((UCHAR)0x6A)
#define MESG_CLOCK_DRIFT_DATA_ID             ((UCHAR)0x6B)
#define MESG_RUN_SCRIPT_ID                   ((UCHAR)0x6C)
#define MESG_XTAL_ENABLE_ID                  ((UCHAR)0x6D)
#define MESG_ANTLIB_CONFIG_ID                ((UCHAR)0x6E)
#define MESG_STARTUP_MESG_ID                 ((UCHAR)0x6F)
#define MESG_AUTO_FREQ_CONFIG_ID             ((UCHAR)0x70)
#define MESG_PROX_SEARCH_CONFIG_ID           ((UCHAR)0x71)

#define MESG_CUBE_CMD_ID                     ((UCHAR)0x80)
                   
#define MESG_PIN_DIODE_CONTROL_ID            ((UCHAR)0x8E)
#define MESG_FIT1_SET_AGC_ID                 ((UCHAR)0x8F)

#define MESG_FIT1_SET_EQUIP_STATE_ID         ((UCHAR)0x91)  // *** CONFLICT: w/ Sensrcore, Fit1 will never have sensrcore enabled

// Sensrcore Messages
#define MESG_SET_CHANNEL_INPUT_MASK_ID       ((UCHAR)0x90)
#define MESG_SET_CHANNEL_DATA_TYPE_ID        ((UCHAR)0x91)
#define MESG_READ_PINS_FOR_SECT_ID           ((UCHAR)0x92)
#define MESG_TIMER_SELECT_ID                 ((UCHAR)0x93)
#define MESG_ATOD_SETTINGS_ID                ((UCHAR)0x94)
#define MESG_SET_SHARED_ADDRESS_ID           ((UCHAR)0x95)
#define MESG_ATOD_EXTERNAL_ENABLE_ID         ((UCHAR)0x96)
#define MESG_ATOD_PIN_SETUP_ID               ((UCHAR)0x97)
#define MESG_SETUP_ALARM_ID                  ((UCHAR)0x98)
#define MESG_ALARM_VARIABLE_MODIFY_TEST_ID   ((UCHAR)0x99)
#define MESG_PARTIAL_RESET_ID                ((UCHAR)0x9A)
#define MESG_OVERWRITE_TEMP_CAL_ID           ((UCHAR)0x9B)
#define MESG_SERIAL_PASSTHRU_SETTINGS_ID     ((UCHAR)0x9C)

#define MESG_READ_SEGA_ID                    ((UCHAR)0xA0)
#define MESG_SEGA_CMD_ID                     ((UCHAR)0xA1)
#define MESG_SEGA_DATA_ID                    ((UCHAR)0xA2)
#define MESG_SEGA_ERASE_ID                   ((UCHAR)0xA3)   
#define MESG_SEGA_WRITE_ID                   ((UCHAR)0xA4)

#define MESG_SEGA_LOCK_ID                    ((UCHAR)0xA6)
#define MESG_FLASH_PROTECTION_CHECK_ID       ((UCHAR)0xA7)
#define MESG_UARTREG_ID                      ((UCHAR)0xA8)
#define MESG_MAN_TEMP_ID                     ((UCHAR)0xA9)
#define MESG_BIST_ID                         ((UCHAR)0xAA)
#define MESG_SELFERASE_ID                    ((UCHAR)0xAB)
#define MESG_SET_MFG_BITS_ID                 ((UCHAR)0xAC)
#define MESG_UNLOCK_INTERFACE_ID             ((UCHAR)0xAD)

#define MESG_SERIAL_ERROR_ID                 ((UCHAR)0xAE)

#define MESG_IO_STATE_ID                     ((UCHAR)0xB0)
#define MESG_CFG_STATE_ID                    ((UCHAR)0xB1)
#define MESG_BLOWFUSE_ID                     ((UCHAR)0xB2)
#define MESG_MASTERIOCTRL_ID                 ((UCHAR)0xB3)
#define MESG_PORT_GET_IO_STATE_ID            ((UCHAR)0xB4)
#define MESG_PORT_SET_IO_STATE_ID            ((UCHAR)0xB5)



#define MESG_SLEEP_ID                        ((UCHAR)0xC5)

#define MESG_DEBUG_ID                        ((UCHAR)0xF0)  // use 2 byte sub-index identifier

//////////////////////////////////////////////
// Message Sizes
//////////////////////////////////////////////
#define MESG_INVALID_SIZE                    ((UCHAR)0)

#define MESG_VERSION_SIZE                    ((UCHAR)11)
#define MESG_RESPONSE_EVENT_SIZE             ((UCHAR)3)
#define MESG_CHANNEL_STATUS_SIZE             ((UCHAR)2)

#define MESG_UNASSIGN_CHANNEL_SIZE           ((UCHAR)1)
#define MESG_ASSIGN_CHANNEL_SIZE             ((UCHAR)3)
#define MESG_CHANNEL_ID_SIZE                 ((UCHAR)5)
#define MESG_CHANNEL_MESG_PERIOD_SIZE        ((UCHAR)3)
#define MESG_CHANNEL_SEARCH_TIMEOUT_SIZE     ((UCHAR)2)
#define MESG_CHANNEL_RADIO_FREQ_SIZE         ((UCHAR)2)
#define MESG_CHANNEL_RADIO_TX_POWER_SIZE     ((UCHAR)2)
#define MESG_NETWORK_KEY_SIZE                ((UCHAR)9)
#define MESG_RADIO_TX_POWER_SIZE             ((UCHAR)2)
#define MESG_RADIO_CW_MODE_SIZE              ((UCHAR)3)
#define MESG_RADIO_CW_INIT_SIZE              ((UCHAR)1)
#define MESG_SEARCH_WAVEFORM_SIZE            ((UCHAR)3)

#define MESG_SYSTEM_RESET_SIZE               ((UCHAR)1)
#define MESG_OPEN_CHANNEL_SIZE               ((UCHAR)1)
#define MESG_CLOSE_CHANNEL_SIZE              ((UCHAR)1)
#define MESG_REQUEST_SIZE                    ((UCHAR)2)

#define MESG_CAPABILITIES_SIZE               ((UCHAR)6)
#define MESG_STACKLIMIT_SIZE                 ((UCHAR)2)

#define MESG_SCRIPT_DATA_SIZE                ((UCHAR)10)
#define MESG_SCRIPT_CMD_SIZE                 ((UCHAR)3)

#define MESG_ID_LIST_ADD_SIZE                ((UCHAR)6)
#define MESG_ID_LIST_CONFIG_SIZE             ((UCHAR)3)
#define MESG_OPEN_RX_SCAN_SIZE               ((UCHAR)1)
#define MESG_EXT_CHANNEL_RADIO_FREQ_SIZE     ((UCHAR)3)

#define MESG_RADIO_CONFIG_ALWAYS_SIZE        ((UCHAR)2)
#define MESG_RX_EXT_MESGS_ENABLE_SIZE        ((UCHAR)2)
#define MESG_SET_TX_SEARCH_ON_NEXT_SIZE      ((UCHAR)2)
#define MESG_SET_LP_SEARCH_TIMEOUT_SIZE      ((UCHAR)2)

#define MESG_SERIAL_NUM_SET_CHANNEL_ID_SIZE  ((UCHAR)3)
#define MESG_ENABLE_LED_FLASH_SIZE           ((UCHAR)2)
#define MESG_GET_SERIAL_NUM_SIZE             ((UCHAR)4)
#define MESG_GET_TEMP_CAL_SIZE               ((UCHAR)4)
#define MESG_CLOCK_DRIFT_DATA_SIZE           ((UCHAR)9)

#define MESG_AGC_CONFIG_SIZE                 ((UCHAR)2)
#define MESG_RUN_SCRIPT_SIZE                 ((UCHAR)2)
#define MESG_ANTLIB_CONFIG_SIZE              ((UCHAR)2)
#define MESG_XTAL_ENABLE_SIZE                ((UCHAR)1)
#define MESG_STARTUP_MESG_SIZE               ((UCHAR)1)
#define MESG_AUTO_FREQ_CONFIG_SIZE           ((UCHAR)4)
#define MESG_PROX_SEARCH_CONFIG_SIZE         ((UCHAR)2)

#define MESG_PIN_DIODE_CONTROL_ID_SIZE       ((UCHAR)2)
#define MESG_FIT1_SET_EQUIP_STATE_SIZE       ((UCHAR)2)

#define MESG_READ_SEGA_SIZE                  ((UCHAR)2)
#define MESG_SEGA_CMD_SIZE                   ((UCHAR)3)
#define MESG_SEGA_DATA_SIZE                  ((UCHAR)10)
#define MESG_SEGA_ERASE_SIZE                 ((UCHAR)0)
#define MESG_SEGA_WRITE_SIZE                 ((UCHAR)3)
#define MESG_SEGA_LOCK_SIZE                  ((UCHAR)1)
#define MESG_FLASH_PROTECTION_CHECK_SIZE     ((UCHAR)1)
#define MESG_UARTREG_SIZE                    ((UCHAR)2)
#define MESG_MAN_TEMP_SIZE                   ((UCHAR)2)
#define MESG_BIST_SIZE                       ((UCHAR)6)
#define MESG_SELFERASE_SIZE                  ((UCHAR)2)
#define MESG_SET_MFG_BITS_SIZE               ((UCHAR)2)
#define MESG_UNLOCK_INTERFACE_SIZE           ((UCHAR)1)
#define MESG_SET_SHARED_ADDRESS_SIZE         ((UCHAR)3)

#define MESG_IO_STATE_SIZE                   ((UCHAR)2)
#define MESG_CFG_STATE_SIZE                  ((UCHAR)2)
#define MESG_BLOWFUSE_SIZE                   ((UCHAR)1)
#define MESG_MASTERIOCTRL_SIZE               ((UCHAR)1)
#define MESG_PORT_SET_IO_STATE_SIZE          ((UCHAR)5)


#define MESG_SLEEP_SIZE                      ((UCHAR)1)


#define MESG_EXT_DATA_SIZE                   ((UCHAR)13)


//////////////////////////////////////////////
// ANT serial message structure
//////////////////////////////////////////////
#if defined (DSI_TYPES_OTHER_OS)  // Nameless unions/struct are not supported by all compilers, remove this if you wish to use the following structures

typedef union
{
   UCHAR ucExtMesgBF;
   struct
   {
      BOOL bExtFieldCont : 1;
      BOOL               : 1;
      BOOL               : 1;
      BOOL               : 1;
      BOOL               : 1;
      BOOL bANTTimeStamp : 1;
      BOOL bReserved1    : 1;
      BOOL bANTDeviceID  : 1;
   };

} EXT_MESG_BF;                                                          // extended message bitfield

typedef union
{
   UCHAR aucMessage[MESG_BUFFER_SIZE];                                  // the complete message buffer pointer
   struct
   {
      UCHAR ucSize;                                                     // the message size
      union
      {
         UCHAR aucFramedData[MESG_FRAMED_SIZE];                         // pointer for serial framer
         struct
         {
            UCHAR ucMesgID;                                             // the message ID
            union
            {
               UCHAR aucMesgData[MESG_MAX_DATA_SIZE];                   // the message data
               struct
               {
                  UCHAR       ucChannel;                                // ANT channel number 
                  UCHAR       aucPayload[ANT_STANDARD_DATA_PAYLOAD_SIZE];// ANT message payload
                  EXT_MESG_BF sExtMesgBF;                               // extended message bitfield (NOTE: this will not be here for longer data messages)
                  UCHAR       aucExtData[MESG_MAX_EXT_DATA_SIZE];       // extended message data
               };
            };
         };
      };
      UCHAR ucCheckSum;                                                 // the message checksum
   };

} ANT_MESSAGE;

#endif

#endif // !ANTMESSAGE_H
