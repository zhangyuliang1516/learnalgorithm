#include "../utils/list.h"

#include <iostream>
#include <stack>

using namespace std;

void printListReversingly_Iteratively(ListNode *head)
{
    stack<ListNode *> nodes;
    ListNode *next = head;
    while (next) {
        nodes.push(next);
        next = next->m_next;
    }
    while (!nodes.empty()) {
        ListNode *node = nodes.top();
        cout << node->m_value << "\t";
        nodes.pop();
    }
}

void printListReversingly_Recursively(ListNode *head)
{
    if (head) {
        if (head->m_next)
            printListReversingly_Recursively(head->m_next);
        cout << head->m_value << "\t";
    }
}

void test(const char *testName, ListNode *head)
{
    cout << testName << " begin:" << endl;
    printList(head);
    printListReversingly_Iteratively(head);
    cout << endl;
    printListReversingly_Recursively(head);
    cout << endl;
    cout << testName << " end" << endl;
}

void test1()
{
    ListNode *node1 = createListNode(1);
    ListNode *node2 = createListNode(2);
    ListNode *node3 = createListNode(3);
    ListNode *node4 = createListNode(4);
    ListNode *node5 = createListNode(5);
    connectListNode(node1, node2);
    connectListNode(node2, node3);
    connectListNode(node3, node4);
    connectListNode(node4, node5);
    test("Test1", node1);
    destroyList(node1);
}

void test2()
{
    ListNode *node1 = createListNode(1);
    test("Test2", node1);
    destroyList(node1);
}

void test3()
{
    test("Test3", nullptr);
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}
