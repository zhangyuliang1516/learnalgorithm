#include <iostream>

using namespace std;

void printMatrixInCircle(int **numbers, int rows, int columns, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;
    for (int i = start; i <= endX; ++i)
        cout << numbers[start][i] << "\t";
    if (endY > start) {
        for (int i = start + 1; i <= endY; ++i)
            cout << numbers[i][endX] << "\t";
    }
    if (endY > start && endX > start) {
        for (int i = endX - 1; i >= start; --i)
            cout << numbers[endY][i] << "\t";
    }
    if (endX > start && endY - 1 > start) {
        for (int i = endY - 1; i > start; --i)
            cout << numbers[i][start] << "\t";
    }
}
void printMatrixClockwisely(int **numbers, int rows, int columns)
{
    if (numbers == nullptr || rows <= 0 || columns <= 0)
        return;
    int start = 0;
    while (rows > start * 2 && columns > start * 2) {
        printMatrixInCircle(numbers, rows, columns, start);
        start++;
    }
}

int main()
{
    return 1;
}
