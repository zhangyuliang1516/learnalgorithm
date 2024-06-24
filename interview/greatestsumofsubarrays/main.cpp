#include <iostream>
#include <exception>

using namespace std;

int greatestSumOfSubArrays(int *numbers, int n)
{
    if (numbers == nullptr || n <= 0)
        return 0;
    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for (int i = 0; i < n; ++i) {
        if (nCurSum <= 0)
            nCurSum = numbers[i];
        else
            nCurSum += numbers[i];
        if (nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }
    return nGreatestSum;
}

int main()
{
    return 0;
}
