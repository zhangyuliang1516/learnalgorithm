#include "../utils/binarytree.h"

#include <iostream>
#include <stack>

using namespace std;

void printBinaryTreeInZigzag(BinaryTreeNode *root)
{
    if (root == nullptr)
        return;
    stack<BinaryTreeNode *> nodes[2];
    int current = 0;
    int next = 1;
    nodes[current].push(root);
    while (nodes[0].size() > 0 || nodes[1].size() > 0) {
        BinaryTreeNode *node = nodes[current].top();
        nodes[current].pop();
        cout << node->value << " ";
        if (current == 0) {
            if (node->right)
                nodes[next].push(node->right);
            if (node->left)
                nodes[next].push(node->left);
        } else {
            if (node->left)
                nodes[next].push(node->left);
            if (node->right)
                nodes[next].push(node->right);
        }
        if (nodes[current].size() == 0) {
            cout << endl;
            current = 1 - current;
            next = 1 - next;
        }
    }
}

int main()
{
    return 0;
}
