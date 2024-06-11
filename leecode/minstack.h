#ifndef MINSTACK_H
#define MINSTACK_H

#include <stack>

class MinStack
{
public:
    MinStack() { minStack.push(INT_MAX); }

    void push(int v)
    {
        stack.push(v);
        minStack.push(std::min(minStack.top(), v));
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top() { return stack.top(); }

    int min() { return minStack.top(); }

private:
    std::stack<int> stack;
    std::stack<int> minStack;
};

class MinStack2
{
public:
    MinStack2() { }

    void push(int val)
    {
        if (stack.empty()) {
            stack.push(0);
            min_s = val;
        } else {
            int diff = val - min_s;
            stack.push(diff);
            min_s = diff > 0 ? min_s : val;
        }
    }

    void pop()
    {
        if (!stack.empty()) {
            int diff = stack.top();
            stack.pop();
            min_s = diff > 0 ? min_s : min_s - diff;
        }
    }

    int top()
    {
        if (stack.empty()) {
            return -1;
        } else {
            int diff = stack.top();
            if (diff > 0)
                return min_s + diff;
            else
                return min_s;
        }
    }

    int min()
    {
        if (stack.empty())
            return -1;
        else
            return min_s;
    }

private:
    std::stack<int> stack;
    int min_s;
};

#endif // MINSTACK_H
