#pragma once

#include <iostream>
#include <unordered_map>
#include <stack>

bool validParentheses(const std::string &s)
{
    int n = s.size();
    if (n % 2 != 0)
        return false;
    std::unordered_map<char, char> pairs = { { ')', '(' }, { ']', '[' }, { '}', '{' } };
    std::string left = "([{";
    std::stack<char> stk;
    for (char c : s) {
        if (pairs.count(c)) {
            if (stk.empty() || stk.top() != pairs[c])
                return false;
            stk.pop();
        } else if (left.find(c)) {
            stk.push(c);
        }
    }
    return stk.empty();
}

bool validateStackSequences(std::vector<int> pushed, std::vector<int> popped)
{
    std::stack<int> st;
    for (int i = 0, j = 0; i < pushed.size(); ++i) {
        st.emplace(pushed[i]);
        while (!st.empty() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
{
    size_t n = temperatures.size();
    std::vector<int> ans(n), next(101, INT_MAX);
    for (int i = n - 1; i >= 0; --i) {
        int warmerIndex = INT_MAX;
        for (int t = temperatures[i] + 1; t <= 100; ++t)
            warmerIndex = std::min(warmerIndex, next[t]);
        if (warmerIndex != INT_MAX)
            ans[i] = warmerIndex - i;
        next[temperatures[i]] = i;
    }
    return ans;
}

std::vector<int> dailyTemperatures2(std::vector<int> &temperatures)
{
    int n = temperatures.size();
    std::vector<int> ans(n);
    std::stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int previousIndex = s.top();
            ans[previousIndex] = i - previousIndex;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
