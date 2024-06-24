#include <iostream>

using namespace std;

bool checkInvalidArray(int *numbers, int n)
{
    if (numbers == nullptr || n <= 0)
        return true;
    return false;
}

bool checkMoreThanHalf(int *numbers, int n, int number)
{
    int times = 0;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] == number)
            times++;
    }
    if (times * 2 > n)
        return true;
    return false;
}

int partion(int *numbers, int start, int end)
{
    int base = numbers[start];
    int mark = start;
    for (int i = start + 1; i <= end; ++i) {
        if (numbers[i] < base) {
            mark++;
            int tmp = numbers[mark];
            numbers[mark] = numbers[i];
            numbers[i] = tmp;
        }
    }
    numbers[start] = numbers[mark];
    numbers[mark] = base;
    return mark;
}
int moreThanHalfNumber1(int *numbers, int n)
{
    if (checkInvalidArray(numbers, n))
        return 0;
    int start = 0;
    int end = n - 1;
    int mid = n >> 1;
    int index = partion(numbers, start, end);
    while (index != mid) {
        if (index > mid) {
            end = index - 1;
            index = partion(numbers, start, end);
        } else {
            start = index + 1;
            index = partion(numbers, start, end);
        }
    }
    int result = numbers[index];
    if (checkMoreThanHalf(numbers, n, result))
        return result;
    return 0;
}
int moreThanHalfNumber2(int *numbers, int n)
{
    if (checkInvalidArray(numbers, n))
        return 0;
    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < n; ++i) {
        if (times == 0) {
            result = numbers[i];
            times = 1;
        }
        if (numbers[i] != result) {
            times--;
        } else {
            times++;
        }
    }
    if (checkMoreThanHalf(numbers, n, result))
        return result;
    return 0;
}

int main()
{
    return 1;
}
