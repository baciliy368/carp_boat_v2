#pragma once

#include <Arduino.h>
#include "varaibles.h"
#include "signal_manager.h"

// Проверка состояния кнопки
void checkButton();

// Чтение положения джойстика (отладка)
void checkJoystick();

// Подготовка джойстика (инициализация пинов)
void prepareJoystick();
