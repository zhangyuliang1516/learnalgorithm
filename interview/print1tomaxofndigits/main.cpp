#include <iostream>
#include <exception>

using namespace std;

void printNumber(const char *number)
{
    bool isBeginning0 = true;
    int length = strlen(number);
    for (int i = 0; i < length; ++i) {
        char c = number[i];
        if (isBeginning0 && c != '0')
            isBeginning0 = false;
        if (!isBeginning0)
            cout << c;
    }
    cout << endl;
}

bool increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int length = strlen(number);
    for (int i = length - 1; i >= 0; --i) {
        int n = number[i] - '0' + nTakeOver;
        if (i == length - 1)
            n++;
        if (n >= 10) {
            if (i == 0) {
                isOverflow = true;
            } else {
                n -= 10;
                number[i] = n + '0';
                nTakeOver = 1;
            }
        } else {
            number[i] = n + '0';
            break;
        }
    }
    return isOverflow;
}

void print1ToMaxOfNDigits1(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while (!increment(number))
        printNumber(number);
    delete[] number;
}
void print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
    if (index == length - 1) {
        printNumber(number);
        return;
    }
    for (int i = 0; i < 10; ++i) {
        number[index + 1] = i + '0';
        print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}
void print1ToMaxOfNDigits2(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    number[n] = '\0';
    for (int i = 0; i < 10; ++i) {
        number[0] = i + '0';
        print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
}

int main()
{
    print1ToMaxOfNDigits1(5);
    return 0;
}
