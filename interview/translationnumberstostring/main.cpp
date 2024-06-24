#include <iostream>

using namespace std;

int getTranslationCount(const string &str)
{
    int length = str.length();
    int *counts = new int[length];
    for (int i = str.length() - 1; i >= 0; --i) {
        int count = 0;
        if (i < length - 1)
            count = counts[i + 1];
        else
            count = 1;
        if (i < length - 1) {
            int number1 = str[i] - '0';
            int number2 = str[i + 1] - '0';
            int convert = number1 * 10 + number2;
            if (convert >= 10 && convert <= 25) {
                if (i < length - 2)
                    count += counts[i + 2];
                else
                    count += 1;
            }
        }
        counts[i] = count;
    }
    int count = counts[0];
    delete[] counts;
    return count;
}

int main()
{
    return 0;
}
