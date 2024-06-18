#include "../utils/list.h"

#include <iostream>
#include <exception>

using namespace std;

void deleteNode(ListNode **head, ListNode *toBeDeleted)
{
    if (head == nullptr || *head == nullptr || toBeDeleted == nullptr)
        return;
    if (toBeDeleted->m_next) {
        ListNode *next = toBeDeleted->m_next;
        toBeDeleted->m_value = next->m_value;
        toBeDeleted->m_next = next->m_next;
        delete next;
        next = nullptr;
    } else if (*head == toBeDeleted) {
        delete toBeDeleted;
        toBeDeleted = nullptr;
        head = nullptr;
    } else {
        ListNode *node = *head;
        while (node->m_next != toBeDeleted)
            node = node->m_next;
        node->m_next = nullptr;
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
}

int main()
{
    return 0;
}
