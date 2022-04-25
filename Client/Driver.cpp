#include "Driver.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

int Driver::send(char* c) {
    //wrtie bytes to client server share file
    ofstream outfile(PATH, ofstream::app);
    if (!outfile)
    {
        cerr << "Error opening file";
        exit(0);
    }
    //send message twice for error detection
    outfile.write(c, PACKET_SIZE_DRIVER);
    outfile.write(c, PACKET_SIZE_DRIVER);
    outfile << endl;
    outfile.close();
    return 0;
}
