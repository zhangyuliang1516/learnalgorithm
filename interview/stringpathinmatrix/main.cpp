#include <iostream>
#include <exception>

using namespace std;

bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char *str,
                 int &pathLength, bool *visited)
{
    if (str[pathLength] == '\0')
        return true;
    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols
        && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col]) {
        ++pathLength;
        visited[row * cols + col] = true;
        bool hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);
        if (!hasPath) {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }
    return hasPath;
}

bool hasPath(const char *matrix, int rows, int cols, const char *str)
{
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
        return false;
    int pathLength = 0;
    bool *visited = new bool[rows * cols];
    bool has = false;
    memset(visited, false, rows * cols);
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (hasPathCore(matrix, rows, cols, i, j, str, pathLength, visited)) {
                has = true;
                break;
            }
        }
        if (has)
            break;
    }
    delete[] visited;
    return has;
}

void test(const char *testName, const char *matrix, int rows, int cols, const char *str,
          bool expected)
{
    cout << testName << " begin: ";
    if (hasPath(matrix, rows, cols, str) == expected)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;
}

int main()
{
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "BFCE";

    test("Test1", (const char *)matrix, 3, 4, str, true);
    return 0;
}
