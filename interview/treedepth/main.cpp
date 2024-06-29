#include "binarytree.h"

#include <iostream>
#include <exception>

using namespace std;

int treeDepth(BinaryTreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = treeDepth(root->left);
    int right = treeDepth(root->right);
    return (left > right) ? (left + 1) : (right + 1);
}

bool isBalanced(BinaryTreeNode *root, int *depth)
{
    if (root == nullptr)
    {
        *depth = 0;
        return 0;
    }
    int left = 0;
    int right = 0;
    if (isBalanced(root->left, &left) && isBalanced(root->right, &right)) {
        int diff = left - right;
        if (diff >= -1 && diff <= 1) {
            *depth = 1 + ((left > right) ? left : right);
            return true;
        }
    }
    return false;
}
bool isBalanced(BinaryTreeNode *root)
{
    int depth = 0;
    return isBalanced(root, &depth);
}
int main()
{
    return 0;
}
