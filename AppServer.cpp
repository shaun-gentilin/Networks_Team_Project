#include <iostream>
#include <string>
#include "Transport.h"

std::string encode(unsigned char* k, std::string me)
{
    std::string cypher;

    for(int i = 0; i < me.size(); i++)
    {
        unsigned char cypherChar = me[i] ^ k[i];
        cypher.push_back(cypherChar);
    }

    return cypher;
}

int main()
{
    unsigned char key[] = {13,240,2,245,65,34,87,26,134,3,
                            58,25,7,45,37,67,25,245,73,235,
                            254,54,179,142,87,12,14,34,65,
                            142,54,13,240,2,245,65,34,87,
                            26,134,3,58,25,7,45,37,67,25,
                            245,13,73,235,254,54,179,142,
                            87,12,14,34,65,142,54,6}; //

    Transport t;
    char message[64];
    std::string m_string = "";

    if(t.receive(message) == 1)
    {
        for(int i = 0; i < 64; i++)
        {
            m_string.push_back(message[i]);
        }

        std::string decoded_string = encode(key, m_string);
    }
    else
    {
        std::cerr << "Error: failed to receive message";
    }
}