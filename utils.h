#pragma once

#include <iostream>

int binarySearch(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int binarySearch2(int arr[], int l, int r, int target)
{
    if (l > r)
        return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearch2(arr, l, mid - 1, target);
    else
        return binarySearch2(arr, mid + 1, r, target);
}

double pow(double x, int n)
{
    double r = 1.0;
    for (int i = 0; i < n; ++i)
        r *= x;
    return r;
}

double pow2(double x, int n)
{
    if (n == 0)
        return 1.0;
    double t = pow2(x, n / 2);
    if (n % 2)
        return x * t * t;
    return t * t;
}

void reverse(std::string &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; ++i)
        std::swap(s[i], s[n - 1 - i]);
}

std::string intToString(int num)
{
    std::string s = "";
    while (num) {
        s += '0' + num % 10;
        num /= 10;
    }
    reverse(s);
    return s;
}
