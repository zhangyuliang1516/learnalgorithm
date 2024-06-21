#include "../utils/binarytree.h"

#include <iostream>

using namespace std;

bool verifySequenceOfBinarySearchTree(int arr[], int n)
{
    if (arr == nullptr || n <= 0)
        return false;
    int root = arr[n - 1];
    int i = 0;
    for (; i < n - 1; ++i) {
        if (arr[i] > root)
            break;
    }
    int j = i;
    for (; j < n - 1; ++j) {
        if (arr[j] < root)
            return false;
    }
    bool left = true;
    if (i > 0)
        left = verifySequenceOfBinarySearchTree(arr, i);
    if (!left)
        return false;
    bool right = true;
    if (i < n - 1)
        right = verifySequenceOfBinarySearchTree(arr + i, n - 1 - i);
    return right;
}

int main()
{
    return 0;
}
