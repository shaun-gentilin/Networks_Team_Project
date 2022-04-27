#include "Datalink.h"
#include "Driver.h"
#include <cstring>
#include <iostream>
using namespace std;

Datalink::Datalink() {}

char* Datalink::recv() {
    Driver* driver = new Driver();
    char* data = driver->recv();
    memcpy(&senderID, data + MESSAGE_AND_TRANS_LENGTH, sizeof(short));
    if (SENDER_HW_ID != senderID) {
        cout << "Sender ID does not match\n";
    }
    memcpy(&recvID, data + MESSAGE_AND_TRANS_LENGTH + sizeof(short), sizeof(short));
    if (RECV_HW_ID != recvID) {
        cout << "Receiver ID does not match\n";
    }
    //strip off the link header and send up
    data[69] = '\0'; //null terminate it after message and transport header
    return data;
}
