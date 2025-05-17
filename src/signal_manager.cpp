#include <varaibles.h>
#include <framework/nrf_utill.h>
#include <signal_manager.h>

/*
    15 - navigation params
    16 - stop engine
    
    25 - ota enable
    26 - ota disable
    
    35 - save current position
    36 - delete position by id
    37 - clear positions
    38 - move to position
    39 - stop moving

    45 - drop trume
    46 - rollback trume
    47 - release trume
    48 - slow release trume
*/

void saveIncomingBoatInfo(MessageData incomingMessageData) {
    currentBoatInfo = incomingMessageData;
}

void sendMessageData(MessageData messageData) {
    sendMessage(messageData);
}

void simpleOperation (uint8_t value) {
    MessageData messageData;
    messageData.operation_type = value;
    sendMessageData(messageData);
}

/*
    45 - drop trume
    46 - rollback trume
    47 - release trume
    48 - slow release trume
*/
void dropTrume () {
    simpleOperation(45);
}

void rollbackTrume () {
    simpleOperation(46);
}

void releaseTrume () {
    simpleOperation(47);
}

void slowReleaseTrume () {
    simpleOperation(48);
}


/*
    25 - ota enable
    26 - ota disable
*/
void enableOta() {
    simpleOperation(25);
}

void disableOta() {
    simpleOperation(26);
}

/*
    15 - navigation params
    16 - stop engine
*/
void sendNavigationParams(uint8_t x, uint8_t y) {
    MessageData messageData;
    messageData.operation_type = 15;
    messageData.joystickX = x;
    messageData.joystickY = y;
}

/*
    15 - navigation params
    16 - stop engine
*/
void sendStop() {
    simpleOperation(16);
}