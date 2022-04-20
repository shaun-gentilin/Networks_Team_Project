#ifndef DataLink_H
#define DataLink_H

#define SENDER_HW_ID 0
#define LINK_HEAD_SIZE 4
#define PACKET_SIZE 68

class Datalink {
private:
    short senderID;
    short recvID;
public:
    Datalink(); //Constructor
    int send(char* c, short recvHardwareID);
};

#endif
