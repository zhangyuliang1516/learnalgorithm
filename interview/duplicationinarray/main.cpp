#include <iostream>

using namespace std;

bool duplicationInArray(int arr[], int n, int &value)
{
    if (arr == nullptr || n <= 0)
        return false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0 || arr[i] > n)
            return false;
    }
    for (int i = 0; i < n; ++i) {
        while (arr[i] != i) {
            if (arr[i] == arr[arr[i]]) {
                value = arr[i];
                return true;
            }
            int tmp = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp;
        }
    }
    return false;
}

bool contains(int arr[], int n, int value)
{
    if (arr == nullptr || n <= 0)
        return false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

void test(const char *testName, int arr[], int n, int expected[], int expectedCount,
          bool validArgument)
{
    cout << testName << " begin: ";
    int duplication = 0;
    bool ret = duplicationInArray(arr, n, duplication);
    if (ret == validArgument) {
        if (ret) {
            if (contains(expected, expectedCount, duplication))
                cout << "Passed" << endl;
            else
                cout << "Failed" << endl;
        } else {
            cout << "Passed" << endl;
        }
    } else {
        cout << "Failed" << endl;
    }
}

void test1()
{
    int arr[] = { 2, 3, 1, 5, 1, 4 };
    int expected[] = { 1 };
    test("Test1", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int), true);
}

void test2()
{
    int arr[] = { 2, 3, 1, 5, 1, 4 };
    int expected[] = { 5 };
    test("Test2", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int), true);
}

void test3()
{
    int arr[] = { 2, 3, 1, 5, 1, 3 };
    int expected[] = { 3, 1 };
    test("Test3", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int), true);
}

void test4()
{
    int arr[] = { 2, 3, 4, 5, 1, 6 };
    int expected[] = { -1 };
    test("Test4", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int), true);
}

void test5()
{
    int *arr = nullptr;
    int expected[] = { -1 };
    test("Test5", arr, 0, expected, sizeof(expected) / sizeof(int), false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 1;
}
