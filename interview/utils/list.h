#pragma once

struct ListNode
{
    int m_value;
    ListNode *m_next;
};

_declspec(dllexport) ListNode *createListNode(int value);
_declspec(dllexport) void connectListNode(ListNode *current, ListNode *next);
_declspec(dllexport) void printListNode(ListNode *current);
