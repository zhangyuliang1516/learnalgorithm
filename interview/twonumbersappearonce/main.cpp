#include <iostream>
#include <exception>

using namespace std;

bool isBit1(int num, int index)
{
    num = num >> index;
    return (num & 1);
}
int firstBitIs1(int num)
{
    int index = 0;
    while (((num & 1) == 0) && (index < 8 * sizeof(int))) {
        num = (num >> 1);
        index++;
    }
    return index;
}
void twoNumbersAppearOnce(int *data, int n, int *num1, int *num2)
{
    if (data == nullptr || n < 2)
        return;
    int resultExclusiveOR = 0;
    for (int i = 0;  i< n; ++i)
        resultExclusiveOR ^= data[i];
    int indexBit1 = firstBitIs1(resultExclusiveOR);
    *num1 = 0;
    *num2 = 0;
    for (int i = 0; i < n; ++i) {
        if (isBit1(data[i], indexBit1))
            *num1 ^= data[i];
        else
            *num2 ^= data[i];
    }
}
int main()
{
    return 0;
}
