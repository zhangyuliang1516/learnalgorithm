#include <iostream>
#include <exception>

using namespace std;

bool isUgly(int number)
{
    while (number % 2 == 0)
        number /= 2;
    while (number % 3 == 0)
        number /= 3;
    while (number % 5 == 0)
        number /= 5;
    return (number == 1) ? true : false;
}
int getUglyNumber1(int index)
{
    if (index < 1)
        return 0;
    int number = 0;
    int count = 0;
    while (count < index) {
        number++;
        if (isUgly(number))
            count++;
    }
    return number;
}
int minValue(int n1, int n2, int n3)
{
    return (n1 < n2) ? ((n1 < n3) ? n1 : n3) : ((n2 < n3) ? n2 : n3);
}
int getUglyNumber2(int index)
{
    if (index < 1)
        return 0;
    int *uglyNumbers = new int[index];
    uglyNumbers[0] = 1;
    int count = 1;
    int *multiply2 = uglyNumbers;
    int *multiply3 = uglyNumbers;
    int *multiply5 = uglyNumbers;
    while (count < index) {
        int min = minValue(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
        uglyNumbers[count] = min;
        while (*multiply2 * 2 <= uglyNumbers[count])
            multiply2++;
        while (*multiply3 * 3 <= uglyNumbers[count])
            multiply3++;
        while (*multiply5 * 5 <= uglyNumbers[count])
            multiply5++;
        count++;
    }
    int result = uglyNumbers[index - 1];
    delete[] uglyNumbers;
    return result;
}

int main()
{
    return 0;
}
