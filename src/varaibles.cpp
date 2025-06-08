#include "varaibles.h"

MessageData currentBoatInfo;

const char *MAIN_MENU_ARRAY[] = {
    "BOAT CONTROL",
    "SETTINGS"};
const size_t MAIN_MENU_ARRAY_SIZE = sizeof(MAIN_MENU_ARRAY) / sizeof(MAIN_MENU_ARRAY[0]);

const char *BOAT_CONTROL_MENU_ARRAY[] = {
    "MAIN MENU",
    "TELEMETRYYYYY",
    "SETTINGS",
    "GET BOAT  INFO"};
const size_t BOAT_CONTROL_MENU_ARRAY_SIZE = sizeof(BOAT_CONTROL_MENU_ARRAY) / sizeof(BOAT_CONTROL_MENU_ARRAY[0]);

const char *SETTINGS_MENU_ARRAY[] = {
    "MAIN MENU",
    "OTA enable",
    "OTA disable"};
const size_t SETTINGS_MENU_ARRAY_SIZE = sizeof(SETTINGS_MENU_ARRAY) / sizeof(SETTINGS_MENU_ARRAY[0]);

const char MENU_POINTER = '<';

uint8_t ACTIVE_MENU_VIEW = 0;
uint8_t ACTIVE_MENU_POSITION = 0;

double INTERNAL_BAT_VALUE = 0.0;
bool INTERNAL_WIFI_VALUE = false;

uint8_t LAST_UPDATE_DURATION;
