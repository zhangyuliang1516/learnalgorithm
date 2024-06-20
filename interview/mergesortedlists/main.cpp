#include "../utils/list.h"

#include <iostream>

using namespace std;

ListNode *mergeSortedLists(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    ListNode *head = nullptr;
    if (head1->m_value > head2->m_value) {
        head = head2;
        head->m_next = mergeSortedLists(head1, head2->m_next);
    } else {
        head = head1;
        head->m_next = mergeSortedLists(head1->m_next, head2);
    }
    return head;
}
ListNode *mergeSortedLists2(ListNode *head1, ListNode *head2)
{
    ListNode *tmp = new ListNode;
    ListNode *node = tmp;
    while (head1 && head2) {
        if (head1->m_value <= head2->m_value) {
            node->m_next = head1;
            node = node->m_next;
            head1 = head1->m_next;
        } else {
            node->m_next = head2;
            node = node->m_next;
            head2 = head2->m_next;
        }
        node->m_next = (head1 == nullptr) ? head2 : head1;
    }
    ListNode *head = tmp->m_next;
    delete tmp;
    return head;
}

int main()
{
    return 1;
}
