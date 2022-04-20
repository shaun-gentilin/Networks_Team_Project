#include "Datalink.h"
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    Datalink link = new Datalink();
    char* message = "Hello I'm Shaun."
    short IP = 12;
    short port = 3;
    char* packet;
    memcpy(packet, message, 16);
    memcpy(packet + 64, IP, sizeof(short));
    memcpy(packet + 64 + 2, port, sizeof(short));
    short rHWID = 5;
    int ret = link.send(packet, rHWID);
    cout << ret << endl;
    return ret;
}
