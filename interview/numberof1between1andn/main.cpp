#include <iostream>
#include <exception>

using namespace std;

int numberOf1(int n)
{
    int count = 0;
    while (n) {
        if ((n % 10) == 1)
            count++;
        n /= 10;
    }
    return count;
}
int numberOf1Between1AndN1(int n)
{
    int count = 0;
    for (int i = 1; i <= n; ++i)
        count += numberOf1(i);
    return count;
}
int powerBase10(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
        result *= 10;
    return result;
}
int numberOf1(char *strN)
{
    if (strN == nullptr || *strN < 0 || *strN > 9 || *strN == '\0')
        return 0;
    int first = *strN - '0';
    int length = strlen(strN);
    if (length == 1 && first == 0)
        return 0;
    if (length == 1 && first > 0)
        return 1;
    // 21345 1 ~ 1345, 1346 ~ 21345
    int numFirstDigit = 0;
    if (first > 1) // 21345 or 31345 10000 ~ 19999
        numFirstDigit = powerBase10(length - 1);
    else
        numFirstDigit = atoi(strN + 1) + 1;
    // 1346~21345 number of 1 of right 4 bit
    int numOtherDigit = first * (length - 2) * powerBase10(length - 2);
    int numRecursive = numberOf1(strN + 1);
    return numFirstDigit + numOtherDigit + numRecursive;
}
int numberOf1Between1AndN2(int n)
{
    if (n <= 0)
        return 0;
    char strN[50];
    sprintf(strN, "%d", n);
    return numberOf1(strN);
}

int main()
{
    // 1234 ~ 21234
    int count = 0;
    for (int i = 1234; i <= 21234; ++i)
        count += numberOf1(i);
    return count;

    return 0;
}
