
#ifndef _CONFIG_H

    #include "lvgl.h"

    #ifdef NATIVE_64BIT
            #define RES_X_MAX       LV_HOR_RES_MAX
            #define RES_Y_MAX       LV_VER_RES_MAX
            #define HARDWARE_NAME   "NATIVE 64BIT APP"
    #else
        #if defined( LILYGO_WATCH_2020_V1 )
            #undef LILYGO_WATCH_LVGL
            #define HARDWARE_NAME   "T-Watch2020V1"
            #define RES_X_MAX       240
            #define RES_Y_MAX       240
            #define USE_PSRAM_ALLOC_LVGL                    /** @brief enabled LVGL to use PSRAM */ 
            #define ENABLE_WEBSERVER                        /** @brief To disable built-in webserver, comment this line */
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
        #elif defined( LILYGO_WATCH_2020_V2 )
            #undef LILYGO_WATCH_LVGL
            #define HARDWARE_NAME   "T-Watch2020V2"
            #define RES_X_MAX       240
            #define RES_Y_MAX       240
            #define USE_PSRAM_ALLOC_LVGL                    /** @brief enabled LVGL to use PSRAM */ 
            #define ENABLE_WEBSERVER                        /** @brief To disable built-in webserver, comment this line */
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
        #elif defined( LILYGO_WATCH_2020_V3 )
            #undef LILYGO_WATCH_LVGL
            #define HARDWARE_NAME   "T-Watch2020V3"
            #define RES_X_MAX       240
            #define RES_Y_MAX       240
            #define USE_PSRAM_ALLOC_LVGL                    /** @brief enabled LVGL to use PSRAM */ 
            #define ENABLE_WEBSERVER                        /** @brief To disable built-in webserver, comment this line */
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
        #elif defined( LILYGO_WATCH_2020_S3 )
            #undef LILYGO_WATCH_LVGL
            #define HARDWARE_NAME   "T-Watch2020S3"
            #define LVGL_BUFFER_SIZE        (240*240)
            #define AXP2101_ON 1
            #define AXP2101_OFF 0
            #define RES_X_MAX       240
            #define RES_Y_MAX       240
            #define USE_PSRAM_ALLOC_LVGL                    /** @brief enabled LVGL to use PSRAM */ 
            #define ENABLE_WEBSERVER                        /** @brief To disable built-in webserver, comment this line */
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
        #elif defined( LILYGO_WATCH_2021 )
            #define HARDWARE_NAME   "T-Watch2021"
            #define RES_X_MAX       240
            #define RES_Y_MAX       240
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
            #define ONLY_ESSENTIAL
            #define ROUND_DISPLAY
            #define NO_UPDATES
        #elif defined( M5PAPER )
            #define HARDWARE_NAME   "m5stack-fire"
            #define RES_X_MAX       540
            #define RES_Y_MAX       960
            #define ENABLE_WEBSERVER                        /** @brief To disable built-in webserver, comment this line */
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
            #define NO_WATCHFACE
        #elif defined( M5CORE2 )
            #define HARDWARE_NAME   "m5stack-core2"
            #define RES_X_MAX       320
            #define RES_Y_MAX       240
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
        #elif defined( WT32_SC01 )
            #undef LILYGO_WATCH_LVGL
            #define HARDWARE_NAME   "wt32-sc01"
            #define RES_X_MAX       480
            #define RES_Y_MAX       320
            #define USE_PSRAM_ALLOC_LVGL                    /** @brief enabled LVGL to use PSRAM */ 
            #define ENABLE_FTPSERVER                        /** @brief To disable built-in ftpserver, comment this line */
            #define NO_WATCHFACE
        #else
            #error "no destination hardware version defined"
        #endif
    #endif
    /**
     * Enable non-latin languages support
     */
    #define USE_EXTENDED_CHARSET CHARSET_CYRILLIC
    /**
     * firmeware version string
     */
    #define __FIRMWARE__            "2023091101"
    /**
     * Allows to include config.h from C code
     */
    #ifdef __cplusplus
        #ifdef NATIVE_64BIT
        #else
            #ifdef M5PAPER
            #elif defined( LILYGO_WATCH_2020_V1 ) || defined( LILYGO_WATCH_2020_V2 ) || defined( LILYGO_WATCH_2020_V3 ) 
                #include <LilyGoWatch.h>
            #elif defined( LILYGO_WATCH_2020_S3 )
                #include <../include/twatch2020s3/Setup212_LilyGo_T_Watch_S3.h>
                #include <../lib/twatch2020s3/utilities.h>
                #include "Arduino.h"
                #include <Wire.h>
                #include <SPI.h>
                #include <LilyGoLib.h>
                #include <FT6336U.h>
                #include <freertos/event_groups.h>
                #include <freertos/FreeRTOS.h>
                #include <lv7_helper.h>
                #include "gui/png_decoder/lv_png.h"
                #include <focaltech.h>
                #include <Ticker.h>
                #include <TFT_eSPI.h>
                #include <WiFi.h>
                #include <config_ext.h>
                #include <sqlite3.h>
                extern LilyGoLib watch;
                extern XPowersAXP2101 pmu;
                extern SensorPCF8563 rtc;    
                extern Ticker *tickTicker;          
            #endif
        
        #endif
        #define _CONFIG_H 
    #endif
#endif // _CONFIG_H