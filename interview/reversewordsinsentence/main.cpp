#include <iostream>
#include <exception>

using namespace std;

void reverse(char *pBegin, char *pEnd)
{
    if (pBegin == nullptr || pEnd == nullptr)
        return;
    while (pBegin < pEnd) {
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        pBegin++;
        pEnd--;
    }
}
char *reverseSentence(char *pData)
{
    if (pData == nullptr)
        return nullptr;
    char *pBegin = pData;
    char *pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;
    reverse(pBegin, pEnd);
    pBegin = pData;
    pEnd = pData;
    while (*pBegin != '\0') {
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else if (*pEnd == ' ' || *pEnd == '\0') {
            reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        } else {
            pEnd++;
        }
    }
    return pData;
}
int main()
{
    char input[] = "I am a student.";
    reverseSentence(input);
    return 0;
}
