#include "Transport.h"
#include <iostream>
#include <cstring>

int Transport::send(short address, short port, std::string message)
{
    std::string totalMessage = message + std::to_string(address) + std::to_string(port);
    int totalMessageSize = totalMessage.size();
    char* c = new char[totalMessageSize];
    memcpy(c, totalMessage.c_str(), totalMessageSize);
    
    //Send to datalink
    

    delete c;
    return 1;
}

int Transport::receive()
{
    return 1;
}