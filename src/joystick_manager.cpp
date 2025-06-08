#include <varaibles.h>
#include <Arduino.h>
#include <signal_manager.h>
#include <framework/ota.h>

void checkButton()
{
    if (digitalRead(JOYSTICK_BATTON_PIN) == LOW)
    {
        // releaseTrume();
        Serial.println("buttonReleased");
    }
}

// TODO: remove after debug
void checkJoystick()
{
    checkButton();
    int8_t joystickX = map(analogRead(JOYSTICK_X_PIN), 0, 4095, -100, 100);
    int8_t joystickY = map(analogRead(JOYSTICK_Y_PIN), 0, 4095, -100, 100);

    if (joystickX > 20 || joystickX < -20 || joystickY > 20 || joystickY < -20)
    {
        Serial.print("отправляем: ");
        Serial.print(joystickX);
        Serial.print(" || ");
        Serial.println(joystickY);
        sendNavigationParams(joystickX, joystickY);
    }
}

void prepareJoystick()
{
    pinMode(JOYSTICK_BATTON_PIN, INPUT_PULLUP);
    pinMode(JOYSTICK_X_PIN, INPUT);
    pinMode(JOYSTICK_Y_PIN, INPUT);
}
