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
