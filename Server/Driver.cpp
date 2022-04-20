#include "Driver.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

char* Driver::recv() {
    //get new message
    ifstream infile(PATH);
    if (!infile) {
        cerr << "Error opening the file for reading\n";
        exit(0);
    }
    static streampos posFile;
    infile.seekg(posFile);
    string st_recv;
    bool wait=true;
    string mes1;
    string mes2;
    char* ret;
    ack = false;

    while (wait) {
        if (getline(infile,st_recv)) {
            //check if the two sent messages match
            int meslen = (st_recv.length()/2)+1;
            mes1 = st_recv.c_str().substr(0,meslen);
            mes2 = st_recv.c_str().substr(meslen,st_recv.length());
            if (mes1.compare(mes2) != 0) {
                cerr << "Error in sent message\n";
            }
            else {
                ack = true;
            }
            memcpy(ret, mes1, st_recv.length()/2);
            posFile = infile.tellg();
            wait=false;
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


    //write ack or nack to shared file and return the message
    ofstream outfile(PATH, ofstream::app);
    if (!outfile)
    {
        cerr << "Error opening file";
        exit(0);
    }

    if (ack) {
        outfile.write("ACK", 3);
        outfile << endl;
    }
    else {
        outfile.write("NACK", 4);
        outfile << endl;
    }
    return ret;
}
