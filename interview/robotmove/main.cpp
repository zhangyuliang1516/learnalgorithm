#include <iostream>
#include <exception>

using namespace std;

int getDigitSum(int num)
{
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int countCore(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    int count = 0;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && (getDigitSum(row) + getDigitSum(col) <= threshold) && !visited[row * cols + col]) {
        visited[row * rows + col] = true;
        count = 1 + countCore(threshold, rows, cols, row - 1, col, visited)
            + countCore(threshold, rows, cols, row, col - 1, visited)
            + countCore(threshold, rows, cols, row + 1, col, visited)
            + countCore(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}

int count(int threshold, int rows, int cols)
{
    if (threshold <= 0 || rows <= 0 || cols <= 0)
        return 0;
    bool *visited = new bool[rows * cols];
    memset(visited, false, rows * cols);
    int c = countCore(threshold, rows, cols, 0, 0, visited);
    delete[] visited;
    return c;
}

int main()
{
    return 0;
}
