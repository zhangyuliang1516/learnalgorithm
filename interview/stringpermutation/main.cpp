#include <iostream>

using namespace std;

void stringPermutation(char *str, char *begin)
{
    if (*begin == '\0') {
        cout << str << endl;
    } else {
        for (char *c = begin; *c != '\0'; ++c) {
            char tmp = *begin;
            *begin = *c;
            *c = tmp;
            stringPermutation(str, begin + 1);
            tmp = *begin;
            *begin = *c;
            *c = tmp;
        }
    }
}
void stringPermutation(char *str)
{
    if (str == nullptr)
        return;
    stringPermutation(str, str);
}

int main()
{
    char str[] = "abcdefg";
    stringPermutation(str);
    return 1;
}
