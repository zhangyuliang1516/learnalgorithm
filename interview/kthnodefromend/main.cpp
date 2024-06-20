#include "../utils/list.h"

#include <iostream>

using namespace std;

ListNode *findKthToTail(ListNode *head, unsigned int k)
{
    ListNode *ahead = head;
    ListNode *behind = nullptr;
    for (int i = 0; i < k - 1; ++i) {
        if (ahead->m_next)
            ahead = ahead->m_next;
        else
            return nullptr;
    }
    behind = head;
    while (ahead->m_next) {
        ahead = ahead->m_next;
        behind = behind->m_next;
    }
    return behind;
}

int main()
{
    return 1;
}
