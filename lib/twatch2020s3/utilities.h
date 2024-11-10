#pragma once
#define BOARD_TFT_WIDTH             (240)
#define BOARD_TFT_HEIHT             (240)

// ST7789
#define BOARD_TFT_MISO              (-1)
#define BOARD_TFT_MOSI              (13)
#define BOARD_TFT_SCLK              (18)
#define BOARD_TFT_CS                (12)
#define BOARD_TFT_DC                (38)
#define BOARD_TFT_RST               (-1)
#define BOARD_TFT_BL                (45)

// Touch
#define BOARD_TOUCH_SDA             (39)
#define BOARD_TOUCH_SCL             (40)
#define BOARD_TOUCH_INT             (16)

//BMA423,PCF8563,AXP2101,DRV2605L
#define BOARD_I2C_SDA               (10)
#define BOARD_I2C_SCL               (11)

// PCF8563 Interrupt
#define BOARD_RTC_INT_PIN           (17)
// AXP2101 Interrupt
#define BOARD_PMU_INT               (21)
// BMA423 Interrupt
#define BOARD_BMA423_INT1           (14)

// IR Transmission
#define BOARD_IR_PIN                (2)

// MAX98357A
#define BOARD_DAC_IIS_BCK           (48)
#define BOARD_DAC_IIS_WS            (15)
#define BOARD_DAC_IIS_DOUT          (46)

// SX1262 Radio Pins
#define BOARD_RADIO_SCK              (3)
#define BOARD_RADIO_MISO             (4)
#define BOARD_RADIO_MOSI             (1)
#define BOARD_RADIO_SS               (5)
#define BOARD_RADIO_DI01             (9)
#define BOARD_RADIO_RST              (8)
#define BOARD_RADIO_BUSY             (7)
#define BOARD_RADIO_DI03             (6)

// PDM Microphone
#define BOARD_MIC_DATA              (47)
#define BOARD_MIC_CLOCK             (44)

#define SHIELD_GPS_TX               (42)
#define SHIELD_GPS_RX               (41)
// Motor
#define MOTOR_PIN2                  (4)


