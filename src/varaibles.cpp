#include "varaibles.h"

MessageData currentBoatInfo;

const char *MAIN_MENU_ARRAY[] = {
    "BOAT CONTROL",
    "SETTINGS"};

const char *BOAT_CONTROL_MENU_ARRAY[] = {
    "MAIN MENU",
    "TELEMETRY",
    "SETTINGS"};

const char *SETTINGS_MENU_ARRAY[] = {
    "MAIN MENU",
    "OTA enable",
    "OTA disable"};



const char MENU_POINTER = '<';


uint8_t ACTIVE_MENU_VIEW = 0;
uint8_t ACTIVE_MENU_POSITION = 0;

double INTERNAL_BAT_VALUE = 0.0;
bool INTERNAL_WIFI_VALUE = false;

uint8_t LAST_UPDATE_DURATION;
