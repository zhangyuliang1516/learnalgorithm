#include "../utils/binarytree.h"

#include <iostream>
#include <stack>

using namespace std;

bool isSymmetrical(BinaryTreeNode *left, BinaryTreeNode *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr || right == nullptr)
        return false;
    if (left->value != right->value)
        return false;
    return isSymmetrical(left->left, right->left) && isSymmetrical(left->right, right->right);
}
bool isSymmetrical(BinaryTreeNode *root)
{
    if (root == nullptr)
        return true;
    return isSymmetrical(root->left, root->right);
}

int main()
{
    return 1;
}
