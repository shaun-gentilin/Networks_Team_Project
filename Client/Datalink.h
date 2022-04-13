#ifndef DataLink_H
#define DataLink_H

#define SENDER_HW_ID 0
#define LINK_HEAD_SIZE 8

class Datalink{
private:
    short senderID;
    short recvID;
public:
    Datalink(short sID, short rID); //Constructor
    int send(char* c, int recvHardwareID, int cSize, int rHWIDSize);
    //int receive(char* c);
};

#endif
