#ifndef Driver_h
#define Driver_h

//#define PATH "/cygdrive/c/Users/Shaun/College/Spring 2022/Networks/Networks_Team_Project/client_to_server.txt"
#define PATH "../client_to_server.txt"
#define MES_AND_HEAD_SIZE 72

#include "Datalink.h"

class Driver {
public:
    char* recv(Datalink* link);
};

#endif
