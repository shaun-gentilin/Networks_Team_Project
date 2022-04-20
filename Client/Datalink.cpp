#include "Datalink.h"
#include "Driver.h"
#include <cstring>
#include <iostream>
using namespace std;

Datalink::Datalink(short sID, short rID) {
    senderID = sID;
    recvID = rID;
}

int Datalink::send(char* c, int recvHardwareID, int cSize) {
    short sHWID = (short)SENDER_HW_ID;
    short rHWID = (short)recvHardwareID;
    Datalink link = new Datalink(sHWID, rHWID);
    memcpy(c + cSize, (char*)link, LINK_HEAD_SIZE);
    Driver driver = new Driver();
    return driver.send(c, cSize + LINK_HEAD_SIZE);    
}
