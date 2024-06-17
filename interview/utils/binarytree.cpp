#include "binarytree.h"

#include <iostream>

using namespace std;

BinaryTreeNode *createBinaryTreeNode(int value)
{
    BinaryTreeNode *node = new BinaryTreeNode;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void connectBinaryTreeNode(BinaryTreeNode *parent, BinaryTreeNode *left, BinaryTreeNode *right)
{
    if (parent) {
        parent->left = left;
        parent->right = right;
    }
}

void printBinaryTreeNode(const BinaryTreeNode *current)
{
    if (current) {
        cout << "value of this node is: " << current->value << endl;
        if (current->left)
            cout << "value of its left child is: " << current->left->value << endl;
        else
            cout << "left child is nullptr" << endl;
        if (current->right)
            cout << "value of its right child is: " << current->right->value << endl;
        else
            cout << "right child is nullptr" << endl;
    } else {
        cout << "this node is nullptr" << endl;
    }
}

void printBinaryTree(const BinaryTreeNode *root)
{
    printBinaryTreeNode(root);
    if (root) {
        if (root->left)
            printBinaryTree(root->left);
        if (root->right)
            printBinaryTree(root->right);
    }
}

void destroyBinaryTree(BinaryTreeNode *root)
{
    if (root) {
        BinaryTreeNode *left = root->left;
        BinaryTreeNode *right = root->right;
        delete root;
        root = nullptr;
        destroyBinaryTree(left);
        destroyBinaryTree(right);
    }
}
