#include "Driver.h"

int Driver::send(char* c, int cSize) {
    //wrtie bytes to client server share file
    ofstream outfile(PATH, ofstream::app);
    if (!outfile)
    {
        cerr << "Error opening file";
        exit(0);
    }
    outfile.write(c, cSize);
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
