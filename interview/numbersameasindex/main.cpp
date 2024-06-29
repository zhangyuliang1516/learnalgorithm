#include <iostream>
#include <exception>

using namespace std;

int numberSameAsIndex(int *data, int n)
{
    if (data == nullptr || n <= 0)
        return -1;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (data[mid] == mid)
            return mid;
        if (data[mid] > mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    return 0;
}
