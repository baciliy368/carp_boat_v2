#include <ui/interface_setups.h>

void addBatInfo()
{
    display.setCursor(0, 0);
    display.print("P:");
    display.print(INTERNAL_BAT_VALUE);
    display.print(" | ");
    display.print(currentBoatInfo.battery_voltage);
}

void addWifiStatusInfo()
{
    display.setCursor(0, 9);
    display.print("W:");
    display.print(INTERNAL_WIFI_VALUE ? '+' : '-');
    display.print(" | ");
    display.print(currentBoatInfo.wifi == 1 ? '+' : '-');
}

void addLastUpdateInfo()
{
    display.setTextSize(2, 2);
    display.setCursor(75, 2);
    display.print(LAST_UPDATE_DURATION);
    display.setTextSize(0, 0);
}

void statusBarPrint()
{
    if (ACTIVE_MENU_VIEW != 8)
    {
        addBatInfo();
        addWifiStatusInfo();
        addLastUpdateInfo();
    }
}

void latitudePrint()
{
    display.print(currentBoatInfo.latitude);
}

void longitudePrint()
{
    display.print(currentBoatInfo.longitude);
}

void maxSpeedPrint()
{
    display.print(currentBoatInfo.maxSpeed);
}

void mainMenuPrint()
{
    addMenuRowsByArray(MAIN_MENU_ARRAY);
}

void boatMenuPrint()
{
    addMenuRowsByArray(BOAT_CONTROL_MENU_ARRAY);
}

void settingsMenuPrint()
{
    addMenuRowsByArray(SETTINGS_MENU_ARRAY);
}

void boatTelemetryMenuPrint()
{
    uint8_t cursor = SCREEN_HEIGHT - SCREEN_BOTTOM_COLOR_HEIGHT;
    display.setCursor(0, cursor);
    latitudePrint();
    cursor += MENU_ITEMS_ON_SCREEN_DISTANCE;
    display.setCursor(0, cursor);
    cursor += MENU_ITEMS_ON_SCREEN_DISTANCE;
    longitudePrint();
    cursor += MENU_ITEMS_ON_SCREEN_DISTANCE;
    display.setCursor(0, cursor);
    maxSpeedPrint();
}

void printActualMenu()
{
    switch (ACTIVE_MENU_VIEW)
    {
    case MAIN_MENU_INDEX:
        mainMenuPrint();
        break;
    case BOAT_MENU_INDEX:
        boatMenuPrint();
        break;
    case SETTINGS_MENU_INDEX:
        settingsMenuPrint();
        break;
    case BOAT_SETTINGS_MENU_INDEX:
        settingsMenuPrint();
        break;
    case BOAT_TELEMETRY_MENU_INDEX:
        boatTelemetryMenuPrint();
        break;
    }
}

void updateScreen()
{
    display.clearDisplay();
    statusBarPrint();
    printActualMenu();
    display.display();
}

void mainMenuController()
{
    switch (ACTIVE_MENU_POSITION)
    {
    case BOAT_CONTROL:
        ACTIVE_MENU_VIEW = BOAT_MENU_INDEX;
        break;
    case SETTINGS:
        ACTIVE_MENU_VIEW = SETTINGS_MENU_INDEX;
        break;
    }
}

void boatMenuController()
{
    switch (ACTIVE_MENU_POSITION)
    {
    case MAIN_MENU:
        ACTIVE_MENU_VIEW = MAIN_MENU_INDEX;
        break;
    case TELEMENTRY:
        ACTIVE_MENU_VIEW = BOAT_TELEMETRY_MENU_INDEX;
        break;
    case SETTINGS_BOAT_CONTROL:
        ACTIVE_MENU_VIEW = BOAT_SETTINGS_MENU_INDEX;
        break;
    }
}

void settingsMenuController()
{
    switch (ACTIVE_MENU_POSITION)
    {
    case MAIN_MENU:
        ACTIVE_MENU_VIEW = MAIN_MENU_INDEX;
        break;
    case OTA_ENABLE:
        // ota
        break;
    case OTA_DISABLE:
        // ota
        break;
    }
}

void selectMenuItem()
{
    switch (ACTIVE_MENU_VIEW)
    {
    case MAIN_MENU_INDEX:
        mainMenuController();
        break;

    case BOAT_MENU_INDEX:
        boatMenuController();
        break;

    case SETTINGS_MENU_INDEX:
        settingsMenuController();
        break;
    }
}

size_t sizeOfArray(const char **rows) {
    return sizeof(rows) / sizeof(rows[0]);
}

size_t getNuberOfCurrentMenuPositions()
{
    switch (ACTIVE_MENU_VIEW)
    {
    case MAIN_MENU_INDEX:
        return sizeOfArray(MAIN_MENU_ARRAY);
    case BOAT_MENU_INDEX:
        return sizeOfArray(BOAT_CONTROL_MENU_ARRAY);
    case SETTINGS_MENU_INDEX:
        return sizeOfArray(SETTINGS_MENU_ARRAY);
    }
}
