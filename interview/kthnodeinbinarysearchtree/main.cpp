#include "binarytree.h"

#include <iostream>
#include <exception>

using namespace std;

const BinaryTreeNode *kthNodeCore(BinaryTreeNode *root, unsigned int k)
{
    const BinaryTreeNode *target = nullptr;
    if (root->left)
        target = kthNodeCore(root->left, k);
    if (target == nullptr) {
        if (k == 1)
            target = root;
        k--;
    }
    if (target == nullptr && root->right)
        target = kthNodeCore(root->right, k);
    return target;
}
const BinaryTreeNode *kthNodeInBinarySearchTree(BinaryTreeNode *root, unsigned int k)
{
    if (root == nullptr || k == 0)
        return nullptr;
    return kthNodeCore(root, k);
}

int main()
{
    return 0;
}
