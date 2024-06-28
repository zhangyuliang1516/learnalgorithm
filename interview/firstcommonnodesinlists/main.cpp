#include "list.h"

#include <iostream>
#include <exception>

using namespace std;

int getListLength(ListNode *head)
{
    int length = 0;
    ListNode *node = head;
    while (node) {
        length++;
        node = node->m_next;
    }
    return length;
}
ListNode *firstCommonNodesInLists(ListNode *head1, ListNode *head2)
{
    int length1 = getListLength(head1);
    int length2 = getListLength(head2);
    int diff = length1 - length2;
    ListNode *longer = head1;
    ListNode *shorter = head2;
    if (length2 > length1) {
        longer = head2;
        shorter = head1;
        diff = length2 - length1;
    }
    for (int i = 0; i < diff; ++i)
        longer = longer->m_next;
    while (longer != nullptr && shorter != nullptr && longer != shorter) {
        longer = longer->m_next;
        shorter = shorter->m_next;
    }
    return longer;
}

int main()
{
    return 0;
}
