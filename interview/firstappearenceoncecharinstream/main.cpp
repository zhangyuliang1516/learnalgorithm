#include <iostream>

using namespace std;

class CharStatistics
{
    CharStatistics()
        : index(0)
    {
        for (int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }
    void insert(char c)
    {
        if (occurrence[c] == -1)
            occurrence[c] = index;
        else if (occurrence[c] >= 0)
            occurrence[c] = -2;
        index++;
    }
    char firstAppearenceOnceChar()
    {
        char c = '\0';
        int index = numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i) {
            if (occurrence[i] >= 0) {
                if (occurrence[i] < index) {
                    c = i;
                    index = occurrence[i];
                }
            }
        }
        return c;
    }

private:
    int occurrence[256];
    int index;
};

int main()
{
    return 0;
}
