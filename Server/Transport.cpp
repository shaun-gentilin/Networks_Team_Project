#include "Transport.h"
#include "Datalink.h"
#include <iostream>
#include <cstring>

#define DATA_LENGTH 68
#define MESSAGE_LENGTH 64

char* Transport::receive()
{
    //Do something to character pointer;
    Datalink d;
    
    char* m = d.recv();
    
    std::cout << (int)m[67] << std::endl;
    std::cout << (int)m[66] << std::endl;

    short port = (m[67] & 0xfff) | ((m[66] & 0xffff) << 8);
    std::cout << "PORT: " << port << std::endl;
    if (port != 18)
    {
        std::cout << "Error invalid port number" << std::endl;
        //exit();
    }

    short address = (m[65] & 0xfff) | ((m[64] & 0xffff) << 8);
    std::cout << "ADDRESS: " << address << std::endl;
    if (address != 27)
    {
        std::cout << "Error invalid address number" << std::endl;
        //exit();
    }
    
    return m;
}
