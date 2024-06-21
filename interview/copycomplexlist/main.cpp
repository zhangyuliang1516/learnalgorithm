#include "complexlist.h"

#include <iostream>
#include <stack>

using namespace std;

void cloneNodes(ComplexListNode *head)
{
    ComplexListNode *node = head;
    while (node) {
        ComplexListNode *cloned = new ComplexListNode;
        cloned->value = node->value;
        cloned->sibling = nullptr;

        cloned->next = node->next;
        node->next = cloned;

        node = cloned->next;
    }
}
void connectSiblingNodes(ComplexListNode *head)
{
    ComplexListNode *node = head;
    while (node) {
        ComplexListNode *cloned = node->next;
        if (node->sibling)
            cloned->sibling = node->sibling->next;
        node = cloned->next;
    }
}
ComplexListNode *reconnectNodes(ComplexListNode *head)
{
    ComplexListNode *node = head;
    ComplexListNode *clonedHead = nullptr;
    ComplexListNode *clonedNode = nullptr;
    if (node) {
        clonedHead = node->next;
        clonedNode = node->next;
        node->next = clonedNode->next;
        node = node->next;
    }
    while (node) {
        clonedNode->next = node->next;
        clonedNode = clonedNode->next;

        node->next = clonedNode->next;
        node = node->next;
    }
    return clonedHead;
}

ComplexListNode *copyComplexList(ComplexListNode *head)
{
    cloneNodes(head);
    connectSiblingNodes(head);
    return reconnectNodes(head);
}

int main()
{
    return 0;
}
