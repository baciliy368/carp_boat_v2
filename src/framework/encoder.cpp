#include "encoder.h"
#include "ui/interface_setups.h"

EncButton eb(ENC_A_PIN, ENC_B_PIN, ENC_BUTTON_PIN, INPUT_PULLUP, INPUT_PULLUP);

void callbackEncoder()
{
    switch (eb.action())
    {
    case EB_RELEASE:
        selectMenuItem();
        Serial.print("click");
        break;
    case EB_TURN:
        size_t numberOfRows = getNuberOfCurrentMenuPositions();
        if(eb.dir() > 0) {
            if(numberOfRows <= ACTIVE_MENU_POSITION) {
                ACTIVE_MENU_POSITION = 0;
            } else {
                ACTIVE_MENU_POSITION += 1;
            }
        } 
        else {
            if(ACTIVE_MENU_POSITION == 0) {
                ACTIVE_MENU_POSITION = numberOfRows;
            } else {
                ACTIVE_MENU_POSITION -= 1;
            }
        }

        Serial.print(eb.dir() > 0 ? 20 : 10);
        break;
    }
}

void checkEncoder()
{
    eb.tick();
}

void prepareEncoder()
{
    eb.setEncType(EB_STEP4_LOW);
    eb.attach(callbackEncoder);
}