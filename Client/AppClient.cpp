#include <iostream>

int main()
{
    char test[] = {'T', 'E', 'S', 'T'};
    int key[] = {9,2,4,1};

    int b[4];
    int cypher[4];

    for(int i = 0; i < 4; i++)
    {
        b[i] = (int)test[i];
        cypher[i] = b[i] ^ key[i];
        std::cout << "cypher: " << cypher[i] << std::endl;
    }

    char ans[4];

    for(int i = 0; i < 4; i++)
    {
        ans[i] = (char)(cypher[i] ^ key[i]);
        std::cout << ans[i] << std::endl;
    }

}