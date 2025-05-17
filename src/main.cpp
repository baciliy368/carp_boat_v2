#include <Arduino.h>
#include <joystick_manager.h>
#include <framework/encoder.h>
#include <ui/interface_setups.h>

unsigned long lastScreenUpdate = 0;

void setup()
{
    Serial.begin(9600);
    prepareJoystick();
    prepareOled();
    prepareEncoder();
}

void processUsability() {
    if (millis() - lastScreenUpdate >= SCREEN_UPDATE_INTERVAL) {
        lastScreenUpdate = millis();
        updateScreen();
      }
    
}

void loop()
{
    checkEncoder();
    checkJoystick();
    checkEncoder();
    processUsability();
}