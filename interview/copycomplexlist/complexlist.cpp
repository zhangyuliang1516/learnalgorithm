#include "complexlist.h"

#include <iostream>

using namespace std;

ComplexListNode *createNode(int value)
{
    ComplexListNode *node = new ComplexListNode;
    node->value = value;
    node->next = nullptr;
    node->sibling = nullptr;
    return node;
}

void buildNodes(ComplexListNode *node, ComplexListNode *next, ComplexListNode *sibling)
{
    if (node != nullptr) {
        node->next = next;
        node->sibling = sibling;
    }
}

void printList(ComplexListNode *head)
{
    ComplexListNode *node = head;
    while (node) {
        cout << "value if node: " << node->value << endl;
        if (node->sibling)
            cout << "value of sibling node: " << node->sibling->value << endl;
        else
            cout << "sibling of node is nullptr" << endl;
        node = node->next;
    }
}
