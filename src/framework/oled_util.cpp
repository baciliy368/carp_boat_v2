#include "oled_util.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void prepareOled()
{
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(0, 0);
    display.setTextColor(WHITE);
}

void addMenuRowsByArray(const char **rows, size_t count)
{
    int cursor = SCREEN_HEIGHT - SCREEN_BOTTOM_COLOR_HEIGHT;
    for (int i{ACTIVE_MENU_POSITION / 4 * 4}; i < count; i++)
    {
        if (ACTIVE_MENU_POSITION == i)
        {
            display.setCursor(110, cursor);
            display.print(MENU_POINTER);
        }
        display.setCursor(0, cursor);
        display.print(rows[i]);
        cursor += MENU_ITEMS_ON_SCREEN_DISTANCE;
    }
}
