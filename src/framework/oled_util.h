#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "varaibles.h"

// Экземпляр дисплея
extern Adafruit_SSD1306 display;

// Инициализация OLED
void prepareOled();
void addMenuRowsByArray(const char **rows);
