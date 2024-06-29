#include <iostream>
#include <exception>

using namespace std;

int numberAppearingOnce(int *data, int n)
{
    if (data == nullptr || n < 1)
        throw exception("Invalid input!");
    int bits[32] = {0};
    for (int i = 0; i < n; ++i) {
        int bitMask = 1;
        for (int j = 31; j >= 0; --j) {
            if ((data[i] & bitMask) == 1)
                bits[j]++;
            bitMask = bitMask << 1;
        }
    }
    int result = 0;
    for (int i = 0; i < 32; ++i) {
        result = result << 1;
        result += bits[i] % 3;
    }
    return result;
}
int main()
{
    return 0;
}
