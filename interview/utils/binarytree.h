#pragma once

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

_declspec(dllexport) BinaryTreeNode *createBinaryTreeNode(int value);
_declspec(dllexport) void connectBinaryTreeNode(BinaryTreeNode *parent, BinaryTreeNode *left,
                                                BinaryTreeNode *right);
_declspec(dllexport) void printBinaryTreeNode(const BinaryTreeNode *current);
_declspec(dllexport) void printBinaryTree(const BinaryTreeNode *root);
_declspec(dllexport) void destroyBinaryTree(BinaryTreeNode *root);
