#include "../utils/list.h"

#include <iostream>

using namespace std;

ListNode *reverseList(ListNode *head)
{
    ListNode *reversedHead = nullptr;
    ListNode *pre = nullptr;
    ListNode *node = head;
    while (node) {
        ListNode *next = node->m_next;
        if (next == nullptr)
            reversedHead = next;
        node->m_next = pre;
        pre = node;
        node = next;
    }
    return reversedHead;
}

int main()
{
    return 1;
}
