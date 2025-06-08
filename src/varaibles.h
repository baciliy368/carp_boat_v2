#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include <stdint.h>
#include <stddef.h>

#define NRF_CE_PIN 4
#define NRF_CSN_PIN 17

#define CE_PIN 4
#define CSN_PIN 17
#define SCK_PIN 18
#define MISO_PIN 19
#define MOSI_PIN 13

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

struct MessageData
{
  float latitude;        // 4 байта
  float longitude;       // 4 байта
  float battery_voltage; // 4 байта

  uint8_t operation_type; // 1 байт
  uint8_t wifi;           // 1 байт
  uint8_t maxSpeed;       // 1 байт
  uint8_t joystickX;      // 1 байт

  uint8_t joystickY;  // 1 байт
  uint8_t reserved1;  // 1 байт
  uint16_t reserved2; // 2 байта (выравнивание)

  uint8_t reserved[16]; // 16 байт под расширение, crc и т.д.
};

extern MessageData currentBoatInfo;

extern const char *MAIN_MENU_ARRAY[];
extern const size_t MAIN_MENU_ARRAY_SIZE;
#define BOAT_CONTROL 0
#define SETTINGS 1

extern const char *BOAT_CONTROL_MENU_ARRAY[];
extern const size_t BOAT_CONTROL_MENU_ARRAY_SIZE;
#define MAIN_MENU 0
#define TELEMENTRY 1
#define SETTINGS_BOAT_CONTROL 2
#define GET_INFO 3

extern const char *SETTINGS_MENU_ARRAY[];
extern const size_t SETTINGS_MENU_ARRAY_SIZE;
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