#include "list.h"

#include <iostream>

using namespace std;

ListNode *createListNode(int value)
{
    ListNode *node = new ListNode;
    node->m_value = value;
    node->m_next = nullptr;
    return node;
}

void connectListNode(ListNode *current, ListNode *next)
{
    if (!current) {
        cout << "Error to connect tow nodes" << endl;
        return;
    }
    current->m_next = next;
}

void printListNode(ListNode *current)
{
    if (current)
        cout << "The key in node is: " << current->m_value << endl;
    else
        cout << "The node is nullptr";
}

void printList(ListNode *head)
{
    cout << "Start printing list" << endl;
    ListNode *next = head;
    while (next) {
        cout << next->m_value << "\t";
        next = next->m_next;
    }
    cout << "Print list finished" << endl;
}

void destroyList(ListNode *head)
{
    ListNode *next = head;
    while (head) {
        head = head->m_next;
        delete next;
        next = head;
    }
}

void addToTail(ListNode **head, int value)
{
    ListNode *node = new ListNode;
    node->m_value = value;
    node->m_next = nullptr;
    if (*head) {
        ListNode *next = *head;
        while (next->m_next)
            next = next->m_next;
        next->m_next = node;
    } else {
        *head = node;
    }
}

void removeNode(ListNode **head, int value)
{
    if (head == nullptr || *head == nullptr)
        return;
    ListNode *toBeDeleted = nullptr;
    if ((*head)->m_value == value) {
        toBeDeleted = *head;
        *head = (*head)->m_next;
    } else {
        ListNode *node = *head;
        while (node->m_next && node->m_next->m_value != value)
            node = node->m_next;
        if (node->m_next && node->m_next->m_value == value) {
            toBeDeleted = node->m_next;
            node->m_next = node->m_next->m_next;
        }
    }
    if (toBeDeleted) {
        delete toBeDeleted;
        toBeDeleted = nullptr;
    }
}
