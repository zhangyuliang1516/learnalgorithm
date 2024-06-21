#pragma once

struct ComplexListNode
{
    int value;
    ComplexListNode *next;
    ComplexListNode *sibling;
};

ComplexListNode *createNode(int value);
void buildNodes(ComplexListNode *node, ComplexListNode *next, ComplexListNode *sibling);
void printList(ComplexListNode *head);
