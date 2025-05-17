#include "nrf_utill.h"

RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);
uint8_t address[][6] = { "1Node", "2Node" };
bool role = false;
bool radioNumber = 1;

void sendMessage(MessageData messageData) {
  radio.write(&messageData, sizeof(MessageData));
}

MessageData waitResponse() {
  uint8_t pipe;
  MessageData messageData;
  radio.startListening();
  while (!radio.available(&pipe)) {
    // ждать данные
  }
  if (radio.available(&pipe)) {
    uint8_t bytes = radio.getPayloadSize();
    radio.read(&messageData, bytes);
  }
  radio.stopListening();
  return messageData;
}
