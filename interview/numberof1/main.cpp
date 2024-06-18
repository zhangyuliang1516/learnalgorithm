#include <iostream>
#include <exception>

using namespace std;

int numberOf1_1(int n)
{
    int count = 0;
    unsigned int f = 1;
    while (f) {
        if (n & f)
            count++;
        f = f << 1;
    }
    return count;
}
int numberOf1_2(int n)
{
    int count = 0;
    while (n) {
        count++;
        n = (n - 1) & n;
    }
    return count;
}

int main()
{
    return 0;
}
