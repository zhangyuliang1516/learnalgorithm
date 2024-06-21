#include "../utils/binarytree.h"

#include <iostream>
#include <stack>

using namespace std;

void mirrorRecursively(BinaryTreeNode *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;
    BinaryTreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left)
        mirrorRecursively(root->left);
    if (root->right)
        mirrorRecursively(root->right);
}
void mirrorIteratively(BinaryTreeNode *root)
{
    if (root == nullptr)
        return;
    stack<BinaryTreeNode *> nodes;
    nodes.push(root);
    while (nodes.size() > 0) {
        BinaryTreeNode *node = nodes.top();
        nodes.pop();
        BinaryTreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left)
            nodes.push(node->left);
        if (node->right)
            nodes.push(node->right);
    }
}

int main()
{
    return 1;
}
