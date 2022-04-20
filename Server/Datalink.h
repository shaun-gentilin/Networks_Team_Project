#ifndef DataLink_H
#define DataLink_H

#define SENDER_HW_ID 0
#define RECV_HW_ID 5
#define LINK_HEAD_SIZE 8
#define MESSAGE_AND_TRANS_LENGTH 68

class Datalink{
private:
    short senderID;
    short recvID;
public:
    Datalink(); //Constructor
    char* recv();
};

#endif
