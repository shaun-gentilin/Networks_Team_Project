#include "Driver.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

char* Driver::recv() {
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
  bool ack = false;

  while (wait) {
      if (getline(infile,st_recv)) {
        //check if the two sent messages match
        int meslen = st_recv.length()/2;
        mes1 = st_recv.substr(0,meslen);
        mes2 = st_recv.substr(meslen,st_recv.length());
        if (mes1.compare(mes2) == 0) {
          ack = true;
        }
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
  if (!ack) {
      cout << "There was an error in the sent message, you may want to resend..." << endl;
  }
  return st_recv.c_str();
}
