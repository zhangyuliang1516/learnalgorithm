#include <iostream>

using namespace std;

bool findInPartiallySortedMatrix(int matrix[], int rows, int columns, int value)
{
    if (matrix && rows > 0 && columns > 0) {
        int row = 0;
        int col = columns - 1;
        while (col >= 0 && row < rows) {
            if (matrix[row * columns + col] == value)
                return true;
            else if (matrix[row * columns + col] > value)
                col--;
            else
                row++;
        }
    }
    return false;
}

void test(const char *testName, int matrix[], int rows, int columns, int value, bool expected)
{
    cout << testName << " begin: ";
    bool ret = findInPartiallySortedMatrix(matrix, rows, columns, value);
    if (ret == expected)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
}

void test1()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test1", matrix, 4, 4, 7, true);
}

void test2()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test2", matrix, 4, 4, 5, false);
}

void test3()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test3", matrix, 4, 4, 1, true);
}

void test4()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test4", matrix, 4, 4, 15, true);
}

void test5()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test5", matrix, 4, 4, 0, false);
}

void test6()
{
    int matrix[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
    test("Test6", matrix, 4, 4, 16, false);
}

void test7()
{
    test("Test7", nullptr, 0, 0, 1, false);
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
    return 1;
}
