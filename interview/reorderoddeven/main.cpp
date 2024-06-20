#include <iostream>
#include <exception>

using namespace std;

void reorderOdEven1(int *arr, int n)
{
    if (arr == nullptr || n <= 0)
        return;
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        while (start < end && (*start & 1) == 1)
            start++;
        while (start < end && (*end & 1) == 0)
            end--;
        if (start < end) {
            int tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
}
bool isEven(int n)
{
    return (n & 1) == 0;
}
void reorderOddEven2(int *arr, int n, bool (*func)(int))
{
    if (arr == nullptr || n <= 0)
        return;
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        while (start < end && !func(*start))
            start++;
        while (start < end && func(*end))
            end--;
        if (start < end) {
            int tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
}

int main()
{
    return 0;
}
