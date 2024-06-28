#include <iostream>
#include <exception>

using namespace std;

bool hasDuplication(const string &str, int position[])
{
    for (int i = 0; i < 26; ++i)
        position[i] = -1;
    for (int i = 0; i < str.length(); ++i) {
        int indexInPosition = str[i] - 'a';
        if (position[indexInPosition] >= 0)
            return true;
        position[indexInPosition]++;
    }
    return false;
}
int longestSubStringWithoutDup(const string &str)
{
    int longest = 0;
    int *position = new int[26];
    for (int start = 0; start < str.length(); ++start) {
        for (int end = start; end < str.length(); ++end) {
            int count = end - start + 1;
            if (!hasDuplication(str.substr(start, count), position)) {
                if (count > longest)
                    longest = count;
            } else {
                break;
            }
        }
    }
    delete[] position;
    return longest;
}
int longestSubStringWithoutDup1(const string &str)
{
    int curLength = 0;
    int maxLength = 0;
    int *position = new int[26];
    for (int i = 0; i < 26; ++i)
        position[i] = -1;
    for (int i = 0; i < str.length(); ++i) {
        int indexInPosition = str[i] - 'a';
        int prevIndex = position[indexInPosition];
        if (prevIndex < 0 || i - prevIndex > curLength) {
            curLength++;
        } else {
            if (curLength > maxLength)
                maxLength = curLength;
            curLength = i - prevIndex;
        }
        position[indexInPosition] = i;
    }
    if (curLength > maxLength)
        maxLength = curLength;
    delete[] position;
    return maxLength;
}

int main()
{
    return 0;
}
