#include <iostream>
#include <stack>
#include <assert.h>

using namespace std;

bool isPopOrder(const int *push, const int *pop, int n)
{
    bool bPossible = false;
    if (push != nullptr && pop != nullptr && n > 0) {
        const int *nextPush = push;
        const int *nextPop = pop;
        stack<int> stackData;
        while (nextPop - pop < n) {
            while (stackData.size() == 0 || stackData.top() != *nextPop) {
                if (nextPush - push >= n)
                    break;
                stackData.push(*nextPush);
                nextPush++;
            }
            if (stackData.size() == 0 || stackData.top() != *nextPop)
                break;
            stackData.pop();
            nextPop++;
        }
        if (stackData.size() == 0 && nextPop - pop == n)
            bPossible = true;
    }
    return bPossible;
}

int main()
{
    return 0;
}
