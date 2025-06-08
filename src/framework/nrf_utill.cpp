#include "nrf_utill.h"

RF24 radio(NRF_CE_PIN, NRF_CSN_PIN);
uint8_t address[][6] = {"1Node", "2Node"};
bool role = false;
bool radioNumber = 1;

void sendMessage(MessageData messageData)
{
  radio.write(&messageData, sizeof(MessageData));
}

MessageData waitResponse()
{
  uint8_t pipe;
  MessageData messageData;
  radio.startListening();
  delay(400);
  while (!radio.available(&pipe))
  {
    // ждать данные
  }
  if (radio.available(&pipe))
  {
    uint8_t bytes = radio.getPayloadSize();
    radio.read(&messageData, bytes);
  }
  radio.stopListening();
  delay(400);
  return messageData;
}

void prepareRfn()
{
  SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CSN_PIN);
  if (!radio.begin())
  {
    Serial.println(F("radio hardware is not responding!!"));
    while (1)
    {
    } // hold in infinite loop
  }
  radioNumber = 1 == 1;
  radio.setPALevel(RF24_PA_HIGH);  // уровень мощности передатчика. На выбор RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setDataRate(RF24_250KBPS); // скорость обмена. На выбор RF24_2MBPS, RF24_1MBPS, RF24_250KBPS

  radio.setPayloadSize(24); // размер пакета, в байтах

  radio.openWritingPipe(address[radioNumber]);     // хотим слушать трубу 0
  radio.openReadingPipe(1, address[!radioNumber]); // using pipe 1

  radio.stopListening(); // не слушаем радиоэфир, мы передатчик
}
