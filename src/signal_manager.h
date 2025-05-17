#pragma once

#include "varaibles.h"
#include "framework/nrf_utill.h"

// Сохранение состояния лодки
void saveIncomingBoatInfo(MessageData incomingMessageData);

// Отправка готового сообщения
void sendMessageData(MessageData messageData);

// Простая операция по коду
void simpleOperation(uint8_t value);

// Управление трюмом
void dropTrume();
void rollbackTrume();
void releaseTrume();
void slowReleaseTrume();

// OTA режим
void enableOta();
void disableOta();

// Навигация
void sendNavigationParams(uint8_t x, uint8_t y);
void sendStop();
