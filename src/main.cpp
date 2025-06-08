#include <Arduino.h>
#include <joystick_manager.h>
#include <framework/encoder.h>
#include <ui/interface_setups.h>
#include <framework/ota.h>

unsigned long lastScreenUpdate = 0;

void setup()
{
    Serial.begin(9600);
    prepareRfn();
    prepareJoystick();
    prepareOled();
    prepareEncoder();
    startWiFi();
    otaLogic();
    disableWifi();
}

void processUsability()
{
    if (millis() - lastScreenUpdate >= SCREEN_UPDATE_INTERVAL)
    {
        lastScreenUpdate = millis();
        updateScreen();
        if (WiFi.status() == WL_CONNECTED)
        {
            ArduinoOTA.handle();
            
        }
    }
}

void loop()
{
    checkEncoder();
    checkJoystick();
    checkEncoder();
    processUsability();
}