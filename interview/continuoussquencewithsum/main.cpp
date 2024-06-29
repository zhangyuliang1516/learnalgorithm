#include <iostream>
#include <exception>

using namespace std;

void printContinuousSequence(int small, int big)
{
    for (int i = small; i <= big; ++i)
        cout << i << " ";
    cout << endl;
}
void continuousSequenceWithSum(int sum)
{
    if (sum < 3)
        return;
    int small = 1;
    int big = 2;
    int mid = (1 + sum) >> 1;
    int curSum = small + big;
    while (small < mid) {
        if (curSum == sum)
            printContinuousSequence(small, big);
        while (curSum > sum && small < mid) {
            curSum -= small;
            small++;
            if (curSum == sum)
                printContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}
int main()
{
    return 0;
}
