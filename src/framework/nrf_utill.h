#pragma once

#include <Arduino.h>
#include <RF24.h>
#include <SPI.h>
#include <Wire.h>
#include "varaibles.h"  // для NRF_CE_PIN и NRF_CSN_PIN

extern RF24 radio;
extern uint8_t address[][6];
extern bool role;
extern bool radioNumber;

void sendMessage(MessageData messageData);
MessageData waitResponse();
