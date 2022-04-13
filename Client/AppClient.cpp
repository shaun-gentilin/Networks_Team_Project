#include <iostream>
#include <string>

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

    std::string message = "USER_ID:..............DEVICE:..............STATUS:.............."; //64 byte string
    std::string userId;
    std::string device;
    std::string status;

    bool running = true;
    while(running)
    {
        std::cout << "KEY SIZE: " << sizeof(key) << std::endl;

        std::cout << "Enter user ID (14 chars): ";
        std::cin >> userId;
        message.replace(8, userId.size(), userId);

        std::cout << "Enter device (14 chars): ";
        std::cin >> device;
        message.replace(29, device.size(), device);

        std::cout << "Enter status (14 chars): ";
        std::cin >> userId;
        message.replace(50, userId.size(), userId);
        std::cout << message << std::endl;

        std::string cypherText = encode(key, message);
        std::cout << cypherText << std::endl;

        std::string answer = encode(key, cypherText);
        std::cout << answer << std::endl;

        running = false;
    }
}