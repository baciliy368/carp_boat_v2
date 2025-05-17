#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include <stdint.h>

#define NRF_CE_PIN 4
#define NRF_CSN_PIN 17

#define JOYSTICK_X_PIN 26
#define JOYSTICK_Y_PIN 27
#define JOYSTICK_BATTON_PIN 5

#define BAT_PIN 5

#define ENC_A_PIN 33
#define ENC_B_PIN 25
#define ENC_BUTTON_PIN 32



#define OLED_RESET -1        
#define SCREEN_ADDRESS 0x3C 
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define SCREEN_TOP_COLOR_HEIGHT 16 
#define SCREEN_BOTTOM_COLOR_HEIGHT 48 
#define MENU_ITEMS_ON_SCREEN_DISTANCE 12

#define NUMBER_OF_ROWS_ON_SCREEN 5

extern uint8_t ACTIVE_MENU_VIEW;
extern uint8_t ACTIVE_MENU_POSITION;

extern double INTERNAL_BAT_VALUE;
extern bool INTERNAL_WIFI_VALUE;

extern uint8_t LAST_UPDATE_DURATION;



struct MessageData {
    uint8_t operation_type;           // 1 байт — тип сообщения (0–100)
    uint8_t battery;        // 1 байт — уровень заряда (0–100)
    uint8_t wifi;

    int32_t latitude;       // 4 байта — широта (например, *1e7)
    int32_t longitude;      // 4 байта — долгота (например, *1e7)
    uint8_t maxSpeed;

    uint8_t joystickX;      // 2 байта — ось X (-32768..32767)
    uint8_t joystickY;      // 2 байта — ось Y (-32768..32767)
  
    int32_t extraData;      // 4 байта — произвольные данные
  
    uint8_t reserved[12];   // 13 байт — под будущее (доп. флаги, crc, debug, и т.д.)
  };


extern MessageData currentBoatInfo;

extern const char* MAIN_MENU_ARRAY[];
#define BOAT_CONTROL 0
#define SETTINGS 1

extern const char* BOAT_CONTROL_MENU_ARRAY[];
#define MAIN_MENU 0
#define TELEMENTRY 1
#define SETTINGS_BOAT_CONTROL 2


extern const char* SETTINGS_MENU_ARRAY[];
#define OTA_ENABLE 1
#define OTA_DISABLE 2

#define MAIN_MENU_INDEX 0
#define BOAT_MENU_INDEX 2
#define BOAT_TELEMETRY_MENU_INDEX 3
#define BOAT_SETTINGS_MENU_INDEX 4
#define SETTINGS_MENU_INDEX 8



#define SCREEN_UPDATE_INTERVAL 300

extern const char MENU_POINTER;

#endif // __VARIABLES_H__