#pragma once

#include "varaibles.h"
#include "EncButton.h" 

// Инициализация энкодера
extern EncButton eb;

// Проверка энкодера на события
void callbackEncoder();
void prepareEncoder();
void checkEncoder();
