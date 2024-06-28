#include <iostream>
#include <exception>

using namespace std;

int maxValueOfGifts1(const int *values, int rows, int cols)
{
    if (values == nullptr || rows < 1 || cols < 1)
        return -1;
    int **maxValues = new int *[rows];
    for (int i = 0; i < rows; ++i)
        maxValues[i] = new int[cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int left = 0;
            int up = 0;
            if (j > 0)
                left = maxValues[i][j - 1];
            if (i > 0)
                up = maxValues[i - 1][j];
            maxValues[i][j] = max(left, up) + values[i * cols + j];
        }
    }
    int result = maxValues[rows - 1][cols - 1];
    for (int i = 0; i < rows; ++i)
        delete[] maxValues[i];
    delete[] maxValues;
    return result;
}
int maxValueOfGift2(const int *values, int rows, int cols)
{
    if (values == nullptr || rows < 1 || cols < 1)
        return -1;
    int *maxValues = new int[cols];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int left = 0;
            int up = 0;
            if (j > 0)
                left = maxValues[j - 1];
            if (i > 0)
                up = maxValues[j];
            maxValues[j] = max(left, up) + values[i * cols + j];
        }
    }
    int result = maxValues[cols - 1];
    delete[] maxValues;
    return result;
}

int main()
{
    return 0;
}
