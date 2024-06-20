#include "../utils/list.h"

#include <iostream>

using namespace std;

ListNode *meetingNode(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    ListNode *slow = head->m_next;
    if (slow == nullptr)
        return nullptr;
    ListNode *fast = slow->m_next;
    while (fast != nullptr && slow != nullptr) {
        if (fast == slow)
            return fast;
        slow = slow->m_next;
        fast = fast->m_next;
        if (fast)
            fast = fast->m_next;
    }
    return nullptr;
}
ListNode *entryNodeInListLoop(ListNode *head)
{
    ListNode *meeting = meetingNode(head);
    if (meeting == nullptr)
        return nullptr;
    int nodesInLoop = 1;
    ListNode *node = meeting;
    while (node->m_next != meeting)
    {
        node = node->m_next;
        nodesInLoop++;
    }
    ListNode *ahead = head;
    for (int i = 0; i < nodesInLoop; ++i)
        ahead = ahead->m_next;
    ListNode *behind = head;
    while (behind != ahead) {
        ahead = ahead->m_next;
        behind = behind->m_next;
    }
    return behind;
}

int main()
{
    return 1;
}
