#include "Datalink.h"
#include "Driver.h"
#include <cstring>
#include <iostream>
using namespace std;

Datalink::Datalink() {}

int Datalink::send(char* c, short recvHardwareID, int cSize) {
    senderID = SENDER_HW_ID;
    recvID = recvHardwareID;
    memcpy(c + cSize, (char*)link, LINK_HEAD_SIZE);
    Driver driver = new Driver();
    return driver.send(c, cSize + LINK_HEAD_SIZE);
}
