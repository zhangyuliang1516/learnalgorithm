#include "../utils/binarytree.h"

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

void printBinaryTreeFromTopToBottom(BinaryTreeNode *root)
{
    if (root == nullptr)
        return;
    deque<BinaryTreeNode *> nodes;
    nodes.push_back(root);
    while (nodes.size() > 0) {
        BinaryTreeNode *node = nodes.front();
        nodes.pop_front();
        cout << node->value << " ";
        if (node->left)
            nodes.push_back(node->left);
        if (node->right)
            nodes.push_back(node->right);
    }
}

int main()
{
    return 0;
}
