#include "Transport.h"
#include "Datalink.h"
#include <iostream>
#include <cstring>

#define DATA_LENGTH 68

char* Transport::receive()
{
    //Do something to character pointer;
    Datalink d;
    return d.recv();
    /*
    std::cout << (int)m[67] << std::endl;
    std::cout << (int)m[66] << std::endl;
    std::cout << (int)m[65] << std::endl;
    std::cout << (int)m[64] << std::endl;
    */
}
