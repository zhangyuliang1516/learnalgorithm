#include <iostream>
#include <exception>
#include <algorithm>

using namespace std;

const int g_maxNumberLength = 10;
char *g_strCombine1 = new char[g_maxNumberLength * 2 + 1];
char *g_strCombine2 = new char[g_maxNumberLength * 2 + 1];

int compare(const void *strNumber1, const void *strNumber2)
{
    strcpy_s(g_strCombine1, strlen(*(const char **)strNumber1) + 1, *(const char **)strNumber1);
    strcat_s(g_strCombine1, strlen(*(const char **)strNumber2) + 1, *(const char **)strNumber2);
    strcpy_s(g_strCombine2, strlen(*(const char **)strNumber2) + 1, *(const char **)strNumber2);
    strcat_s(g_strCombine2, strlen(*(const char **)strNumber1) + 1, *(const char **)strNumber1);
    return strcmp(g_strCombine1, g_strCombine2);
}

void sortArrayFroMinNumber(int *numbers, int n)
{
    if (numbers == nullptr || n <= 0)
        return;
    char **strNumbers = (char **)(new int[n]);
    for (int i = 0; i < n; ++i) {
        strNumbers[i] = new char[g_maxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }
    qsort(strNumbers, n, sizeof(char *), compare);
    for (int i = 0; i < n; ++i)
        cout << strNumbers[i];
    for (int i = 0; i < n; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

int main()
{
    return 0;
}
