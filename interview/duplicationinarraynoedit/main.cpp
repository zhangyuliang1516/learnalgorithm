#include <iostream>

using namespace std;

int countRange(int arr[], int n, int start, int end)
{
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= start && arr[i] <= end)
            count++;
    }
    return count;
}
int duplicationInArrayNoEdit(int arr[], int n)
{
    if (arr == nullptr || n <= 0)
        return -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 1 || arr[i] > n - 1)
            return -1;
    }
    int start = 1;
    int end = n - 1;
    while (start <= end) {
        int mid = (start + end) >> 1;
        int count = countRange(arr, n, start, mid);
        if (end == start) {
            if (count > 1)
                return start;
            else
                break;
        }
        if (count > (mid - start + 1))
            end = mid;
        else
            start = mid + 1;
    }
    return -1;
}

void test(const char *testName, int arr[], int n, int *expected, int expectedCount)
{
    cout << testName << " begin: ";
    int ret = duplicationInArrayNoEdit(arr, n);
    for (int i = 0; i < expectedCount; ++i) {
        if (ret == expected[i]) {
            cout << "Passed" << endl;
            return;
        }
    }
    cout << "failed" << endl;
}
void test1()
{
    int arr[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
    int dup[] = { 2, 3 };
    test("Test1", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test2()
{
    int arr[] = { 2, 3, 5, 4, 4, 1, 6, 7 };
    int dup[] = { 4 };
    test("Test2", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test3()
{
    int arr[] = { 1, 3, 5, 4, 1, 2, 6, 7 };
    int dup[] = { 1 };
    test("Test3", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test4()
{
    int arr[] = { 1, 3, 5, 4, 7, 2, 6, 7 };
    int dup[] = { 7 };
    test("Test4", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test5()
{
    int arr[] = { 1, 1 };
    int dup[] = { 1 };
    test("Test4", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test6()
{
    int arr[] = { 2, 3, 5, 4, 4, 1, 4, 7 };
    int dup[] = { 4 };
    test("Test6", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test7()
{
    int arr[] = { 2, 3, 5, 4, 1, 1, 6, 7 };
    int dup[] = { 1 };
    test("Test7", arr, sizeof(arr) / sizeof(int), dup, sizeof(dup) / sizeof(int));
}
void test8()
{
    int *arr = nullptr;
    int dup[] = { -1 };
    test("Test8", arr, 0, dup, sizeof(dup) / sizeof(int));
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}
