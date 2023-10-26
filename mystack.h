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
