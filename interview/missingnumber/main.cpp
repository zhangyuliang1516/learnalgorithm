#include <iostream>
#include <exception>

using namespace std;

int missingNumber(int *data, int n)
{
    if (data == nullptr || n < 1)
        return -1;
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) >> 1;
        if (data[mid] == mid) {
            start = mid + 1;
        } else {
            if (mid == 0 || data[mid - 1] == mid - 1)
                return mid;
            end = mid - 1;
        }
    }
    if (start == n)
        return n;
    return -1;
}

int main()
{
    return 0;
}
