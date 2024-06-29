#include <iostream>
#include <exception>

using namespace std;

bool twoNumbersWithSum(int *data, int n, int sum, int *num1, int *num2)
{
    if (data == nullptr || num1 == nullptr || num2 == nullptr || n < 2)
        return false;
    int left = 0;
    int right = n - 1;
    while (left < right) {
        long long curSum = data[left] + data[right];
        if (curSum == sum) {
            *num1 = data[left];
            *num2 = data[right];
            return true;
        }
        if (curSum > sum)
            right--;
        else
            left++;
    }
    return false;
}
int main()
{
    return 0;
}
