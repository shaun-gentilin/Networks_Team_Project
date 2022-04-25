#include "Transport.h"
#include "Datalink.h"
#include <iostream>
#include <cstring>

#define DATA_LENGTH 68

int Transport::send(short address, short port, std::string message)
{
    char c[DATA_LENGTH];
    for(int i = 0; i < DATA_LENGTH; i++)
    {
        c[i] = message[i];
    }

    c[67] = port & 0xffff;
    c[66] = (port & 0xffff) >> 8;
    c[65] = address & 0xffff;
    c[64] = (address & 0xffff) >> 8;

    Datalink d;
    d.send(c, 5);
}

int Transport::receive()
{
    return 1;
}