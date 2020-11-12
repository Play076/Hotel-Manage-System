#include <random>

using namespace std;

string generateUniqueHexaId()
{
    int str_len = 16;

    const char hexaId[str_len] = "0123456789ABCDEF";

    char newId[str_len];

    for (int i = 0; i < 15; i++)
    {
        newId[i] = hexaId[rand() % str_len];
    }

    return newId;
};