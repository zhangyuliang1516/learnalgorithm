#include "../utils/binarytree.h"

#include <iostream>

using namespace std;

void convertNodes(BinaryTreeNode *node, BinaryTreeNode **last)
{
    if (node == nullptr)
        return;

    BinaryTreeNode *current = node;

    if (current->left)
        convertNodes(current->left, last);

    current->left = *last;
    if (*last)
        (*last)->right = current;

    *last = current;

    if (current->right)
        convertNodes(current->right, last);
}
BinaryTreeNode *convertBinarySearchTree(BinaryTreeNode *root)
{
    BinaryTreeNode *last = nullptr;
    convertNodes(root, &last);
    BinaryTreeNode *node = last;
    while (node && node->left)
        node = node->left;
    return node;
}

int main()
{
    return 0;
}
