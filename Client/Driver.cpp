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
    outfile.write(c, PACKET_SIZE);
    outfile.write(c, PACKET_SIZE);
    outfile << endl;
    outfile.close();

    //check for acknowledgement
    ifstream infile(PATH);
    if (!infile) {
        cerr << "Error opening the file for reading\n";
	      exit(0);
    }
    static streampos posFile;
    infile.seekg(posFile);
    string st_recv;
    bool wait=true;

    while (wait) {
        if (getline(infile,st_recv)) {
      	    posFile = infile.tellg();
      	    wait=false;
            if (st_recv == "ACK") {
                return 0;
            }
            else {
                return 1;
            }
      	}
      	else {
      	    infile.close();
      	    infile.open(PATH);
      	    if (!infile) {
      	        cerr << "Error opening the file for reading\n";
      		      exit(0);
      	    }
      	    infile.seekg(posFile);
      	}
    }
    infile.close();
}
