#include <iostream>
#include <exception>

using namespace std;

// 0123456789101112131415...
int powerBase10(int n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
        result *= 10;
    return result;
}
int countOfIntegers(int digits)
{
    if (digits == 1)
        return 10;
    return 9 * powerBase10(digits - 1);
}
int beginOfIntegers(int digits)
{
    if (digits == 1)
        return 0;
    return powerBase10(digits - 1);
}
int digitAtIndex(int index, int digits)
{
    int number = beginOfIntegers(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for (int i = 1; i < indexFromRight; ++i)
        number /= 10;
    return number % 10;
}
int digitAtIndex(int index)
{
    if (index < 0)
        return -1;
    int digits = 1;
    while (1) {
        int count = countOfIntegers(digits);
        if (index < count * digits)
            return digitAtIndex(index, digits);
        index -= count * digits;
        digits++;
    }
    return -1;
}

int main()
{
    return 0;
}
