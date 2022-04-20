#ifndef H_TRANSPORT
#define H_TRANSPORT
#include <string>

class Transport
{
private:

public:
    int send(short address, short port, std::string message);

    int receive();
};

#endif //H_TRANSPORT