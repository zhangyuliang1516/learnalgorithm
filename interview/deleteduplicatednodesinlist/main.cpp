#include "../utils/list.h"

#include <iostream>
#include <exception>

using namespace std;

void deleteDuplicatedNodesInList(ListNode **head)
{
    if (head == nullptr || *head == nullptr)
        return;
    ListNode *pre = nullptr;
    ListNode *node = *head;
    while (node) {
        ListNode *next = node->m_next;
        bool needDelete = false;
        if (next && next->m_value == node->m_value)
            needDelete = true;
        if (needDelete) {
            int value = node->m_value;
            ListNode *toBeDeleted = node;
            while (toBeDeleted && toBeDeleted->m_value == value) {
                next = toBeDeleted->m_next;
                delete toBeDeleted;
                toBeDeleted = next;
            }
            if (pre == nullptr)
                *head = next;
            else
                pre->m_next = next;
            node = next;
        } else {
            pre = node;
            node = next;
        }
    }
}

int main()
{
    return 0;
}
