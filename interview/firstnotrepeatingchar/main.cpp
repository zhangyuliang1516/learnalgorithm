#include <iostream>
#include <exception>

using namespace std;

char firstNotRepeatingChar(const char *str)
{
    if (str == nullptr)
        return '\0';
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for (int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    const char *hashKey = str;
    while (*hashKey != '\0')
        hashTable[*(hashKey++)]++;
    hashKey = str;
    while (*hashKey != '\0') {
        if (hashTable[*hashKey] == 1)
            return *hashKey;
        hashKey++;
    }
    return '\0';
}

int main()
{
    return 0;
}
