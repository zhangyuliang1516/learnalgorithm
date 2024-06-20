#include "../utils/binarytree.h"

#include <iostream>

using namespace std;

bool haveSubTree1(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root2 == nullptr)
        return true;
    if (root1 == nullptr)
        return false;
    if (root1->value != root2->value)
        return false;
    return haveSubTree1(root1->left, root2->left) && haveSubTree1(root1->right, root2->right);
}

bool haveSubTree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root1 == nullptr || root2 == nullptr)
        return false;
    bool ret = haveSubTree1(root1, root2);
    if (ret)
        return true;
    ret = haveSubTree(root1->left, root2);
    if (ret)
        return true;
    ret = haveSubTree(root1->right, root2);
    return ret;
}

int main()
{
    return 1;
}
