#include "Datalink.h"
#include "Driver.h"
#include <cstring>
#include <iostream>
using namespace std;

Datalink::Datalink() {}

char* link_recv() {
    Driver* driver = new Driver();
    Datalink* link = new Datalink();
    char* link_data = driver->recv(link);
    link->setSenderID();
    link->setRecvID();
    //strip off the link header and send up
    char* data_link_stripped;
    memcpy(data_link_stripped, link_data, MESSAGE_AND_TRANS_LENGTH);
    return data_link_stripped;
}

char* Datalink::getDataHead() {
    return data;
}

void Datalink::setSenderID() {
    memcpy(&senderID, data + MESSAGE_AND_TRANS_LENGTH, sizeof(short));
    if (SENDER_HW_ID != senderID) {
        cout << "Sender ID does not match\n";
    }
}

void Datalink::setRecvID() {
    memcpy(&recvID, data + MESSAGE_AND_TRANS_LENGTH + sizeof(short), sizeof(short));
    if (RECV_HW_ID != recvID) {
        cout << "Receiver ID does not match\n";
    }
}
