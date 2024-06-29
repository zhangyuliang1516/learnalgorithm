#include "list.h"

#include <iostream>
#include <exception>

using namespace std;

int getFirstK(int *data, int n, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) >> 1;
    if (data[mid] == k) {
        if (mid == 0 || data[mid - 1] != k)
            return mid;
        else
            end = mid - 1;
    } else if (data[mid] > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    return getFirstK(data, n, k, start, end);
}
int getLastK(int *data, int n, int k, int start, int end)
{
    if (start > end)
        return -1;
    int mid = (start + end) >> 1;
    if (data[mid] == k) {
        if (mid == n - 1 || data[mid + 1] != k)
            return mid;
        else
            start = mid + 1;
    } else if (data[mid] > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    return getLastK(data, n, k, start, end);
}
int numberOfK(int *data, int n, int k)
{
    if (data == nullptr || n < 1)
        return 0;
    int first = getFirstK(data, n, k, 0, n -1);
    int last = getLastK(data, n, k, 0, n - 1);
    if (first > -1 && last > -1)
        return last - first + 1;
    return 0;
}

int main()
{
    return 0;
}
