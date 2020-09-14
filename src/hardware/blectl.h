/****************************************************************************
 *   Aug 11 17:13:51 2020
 *   Copyright  2020  Dirk Brosswick
 *   Email: dirk.brosswick@googlemail.com
 ****************************************************************************/
 
/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#ifndef _BLECTL_H
    #define _BLECTL_H

    #include "TTGO.h"

    // See the following for generating UUIDs:
    // https://www.uuidgenerator.net/
    #define SERVICE_UUID BLEUUID("6E400001-B5A3-F393-E0A9-E50E24DCCA9E") // UART service UUID
    #define CHARACTERISTIC_UUID_RX BLEUUID("6E400002-B5A3-F393-E0A9-E50E24DCCA9E")
    #define CHARACTERISTIC_UUID_TX BLEUUID("6E400003-B5A3-F393-E0A9-E50E24DCCA9E")

    #define DEVICE_INFORMATION_SERVICE_UUID  BLEUUID((uint16_t)0x180A) // Device Information server UUID
    #define MANUFACTURER_NAME_STRING_CHARACTERISTIC_UUID  BLEUUID((uint16_t)0x2A29) // Device Information - manufacturer name string  UUID
    #define FIRMWARE_REVISION_STRING_CHARACTERISTIC_UUID  BLEUUID((uint16_t)0x2A26) // Device Information - firmware revision  UUID

    #define BATTERY_SERVICE_UUID  BLEUUID((uint16_t)0x180F) // Battery service UUID
    #define BATTERY_LEVEL_CHARACTERISTIC_UUID  BLEUUID((uint16_t)0x2A19) // battery level characteristic  UUID
    #define BATTERY_LEVEL_DESCRIPTOR_UUID  BLEUUID((uint16_t)0x2901) // battery level descriptor UUID
    #define BATTERY_POWER_STATE_CHARACTERISTIC_UUID  BLEUUID((uint16_t)0x2A1A) // battery power state characteristic  UUID

    #define BATTERY_POWER_STATE_BATTERY_UNKNOWN 0x0
    #define BATTERY_POWER_STATE_BATTERY_NOT_SUPPORTED 0x1
    #define BATTERY_POWER_STATE_BATTERY_NOT_PRESENT 0x2
    #define BATTERY_POWER_STATE_BATTERY_PRESENT 0x3

    #define BATTERY_POWER_STATE_DISCHARGE_UNKNOWN 0x0
    #define BATTERY_POWER_STATE_DISCHARGE_NOT_SUPPORTED 0x4
    #define BATTERY_POWER_STATE_DISCHARGE_NOT_DISCHARING 0x8
    #define BATTERY_POWER_STATE_DISCHARGE_DISCHARING 0xc

    #define BATTERY_POWER_STATE_CHARGE_UNKNOWN 0x0
    #define BATTERY_POWER_STATE_CHARGE_NOT_CHARGEABLE  0x10
    #define BATTERY_POWER_STATE_CHARGE_NOT_CHARING 0x20
    #define BATTERY_POWER_STATE_CHARGE_CHARING 0x30

    #define BATTERY_POWER_STATE_LEVEL_UNKNOWN 0x0
    #define BATTERY_POWER_STATE_LEVEL_NOT_SUPPORTED 0x40
    #define BATTERY_POWER_STATE_LEVEL_GOOD 0x80
    #define BATTERY_POWER_STATE_LEVEL_CRITICALLY_LOW 0xC0

    #define BLECTL_JSON_COFIG_FILE         "/blectl.json"

    #define EndofText               0x03
    #define LineFeed                0x0a
    #define DataLinkEscape          0x10

    #define BLECTL_CHUNKSIZE        20
    #define BLECTL_CHUNKDELAY       50

    typedef struct {
        bool advertising = true;
        bool enable_on_standby = false;
        int32_t txpower = 1;
    } blectl_config_t;

    typedef struct {
        bool active;
        char *msg;
        int32_t msglen;
        int32_t msgpos;
        int32_t msgchunk;
    } blectl_msg_t;

    typedef void ( * BLECTL_CALLBACK_FUNC ) ( EventBits_t event, char *msg );

    typedef struct {
        EventBits_t event;
        BLECTL_CALLBACK_FUNC event_cb;
        const char *id;
        uint64_t counter;
    } blectl_event_t;

    #define BLECTL_CONNECT               _BV(0)
    #define BLECTL_DISCONNECT            _BV(1)
    #define BLECTL_STANDBY               _BV(2)
    #define BLECTL_ON                    _BV(3)
    #define BLECTL_OFF                   _BV(4)
    #define BLECTL_ACTIVE                _BV(5)
    #define BLECTL_MSG                   _BV(6)
    #define BLECTL_PIN_AUTH              _BV(7)
    #define BLECTL_PAIRING               _BV(8)
    #define BLECTL_PAIRING_SUCCESS       _BV(9)
    #define BLECTL_PAIRING_ABORT         _BV(10)
    #define BLECTL_MSG_SEND_SUCCESS      _BV(11)
    #define BLECTL_MSG_SEND_ABORT        _BV(12)

    /**
     * @brief ble setup function
     */
    void blectl_setup( void );
    /**
     * @brief trigger a blectl managemt event
     * 
     * @param   bits    event to trigger
     */
    void blectl_set_event( EventBits_t bits );
    /**
     * @brief clear a blectl managemt event
     * 
     * @param   bits    event to clear
     */
    void blectl_clear_event( EventBits_t bits );
    /**
     * @brief get a blectl managemt event state
     * 
     * @param   bits    event state, example: POWERMGM_STANDBY to evaluate if the system in standby
     */
    bool blectl_get_event( EventBits_t bits );
    /**
     * @brief registers a callback function which is called on a corresponding event
     * 
     * @param   event  possible values:     BLECTL_CONNECT,
     *                                      BLECTL_DISCONNECT,
     *                                      BLECTL_STANDBY,
     *                                      BLECTL_ON,
     *                                      BLECTL_OFF,       
     *                                      BLECTL_ACTIVE,    
     *                                      BLECTL_MSG,
     *                                      BLECTL_PIN_AUTH,
     *                                      BLECTL_PAIRING,
     *                                      BLECTL_PAIRING_SUCCESS,
     *                                      BLECTL_PAIRING_ABORT
     * @param   blectl_event_cb     pointer to the callback function
     * @param   id                  pointer to an string
     */
    void blectl_register_cb( EventBits_t event, BLECTL_CALLBACK_FUNC blectl_event_cb, const char *id );
    /**
     * @brief enable blueetooth on standby
     * 
     * @param   enable_on_standby   true means enabled, false means disabled 
     */
    void blectl_set_enable_on_standby( bool enable_on_standby );
    /**
     * @brief enable advertising
     * 
     * @param   advertising true means enabled, false means disabled
     */
    void blectl_set_advertising( bool advertising );
    /**
     * @brief get the current enable_on_standby config
     * 
     * @return  true means enabled, false means disabled
     */
    bool blectl_get_enable_on_standby( void );
    /**
     * @brief get the current advertising config
     * 
     * @return  true means enabled, false means disabled
     */
    bool blectl_get_advertising( void );
    /**
     * @brief store the current configuration to SPIFFS
     */
    void blectl_save_config( void );
    /**
     * @brief read the configuration from SPIFFS
     */
    void blectl_read_config( void );
    /**
     * @brief send an battery update over bluetooth to gadgetbridge
     * 
     * @param   percent     battery percent
     * @param   charging    charging state
     * @param   plug        powerplug state
     */
    void blectl_update_battery( int32_t percent, bool charging, bool plug );
    /**
     * @brief send an message over bluettoth to gadgetbridge
     * 
     * @param   msg     pointer to a string
     */
    void blectl_send_msg( char *msg );

#endif // _BLECTL_H