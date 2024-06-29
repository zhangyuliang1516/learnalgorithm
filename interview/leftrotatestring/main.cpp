#include <iostream>
#include <exception>

using namespace std;

void reverse(char *start, char *end)
{
    if (start && end) {
        while (start < end) {
            char tmp = *start;
            *start = *end;
            *end = tmp;
            start++;
            end--;
        }
    }
}
char *leftRotateString(char *str, int n)
{
    if (str) {
        int length = strlen(str);
        if (length > 0 && n > 0 && n < length) {
            char *leftStart = str;
            char *leftEnd = str + n - 1;
            char *rightStart = str + n;
            char *rightEnd = str + length - 1;
            reverse(leftStart, leftEnd);
            reverse(rightStart, rightEnd);
            reverse(leftStart, rightEnd);
        }
    }
    return str;
}
int main()
{
    char input[] = "I am a student.";
    leftRotateString(input, 2);
    return 0;
}
