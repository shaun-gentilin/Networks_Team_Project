#include "Datalink.h"
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  Datalink* link = new Datalink();
  char* packet = link_recv();
  char* ret;
  memcpy(ret, packet, 64);
  cout << ret << endl;
  return 0;
}
