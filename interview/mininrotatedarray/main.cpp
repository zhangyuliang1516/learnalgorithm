#include <iostream>
#include <exception>

using namespace std;

int minInOrder(int arr[], int start, int end)
{
    int ret = arr[start];
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < ret)
            ret = arr[i];
    }
    return ret;
}

int minInRotatedArray(int arr[], int n)
{
    if (arr == nullptr || n <= 0)
        throw exception("Invalid input!");
    int start = 0;
    int end = n - 1;
    int mid = start;
    while (arr[start] >= arr[end]) {
        if (end - start == 1) {
            mid = end;
            break;
        }
        mid = (start + end) >> 1;
        if (arr[start] == arr[end] && arr[mid] == arr[start])
            return minInOrder(arr, 0, n - 1);
        if (arr[mid] <= arr[start])
            end = mid;
        else if (arr[mid] >= arr[end])
            start = mid;
    }
    return arr[mid];
}

void test(const char *testName, int *numbers, int n, int expected)
{
    cout << testName << " begin: " << endl;
    try {
        for (int i = 0; i < n; ++i)
            cout << numbers[i] << " ";
        int ret = minInRotatedArray(numbers, n);
        if (ret == expected)
            cout << "passed" << endl;
        else
            cout << "failed" << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

int main()
{
    int array1[] = { 3, 4, 5, 1, 2 };
    test("Test1", array1, 5, 1);

    int array2[] = { 3, 4, 5, 1, 1, 2 };
    test("Test2", array2, 6, 1);

    int array3[] = { 3, 4, 5, 1, 2, 2 };
    test("Test3", array3, 6, 1);

    int array4[] = { 1, 0, 1, 1, 1 };
    test("Test4", array4, 5, 0);

    int array5[] = { 1, 2, 3, 4, 5 };
    test("Test5", array5, 5, 1);

    int array6[] = { 1 };
    test("Test6", array6, 1, 1);

    test("Test7", nullptr, 0, 0);

    return 0;
}
