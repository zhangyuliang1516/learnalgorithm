#include "../utils/binarytree.h"

#include <iostream>
#include <iostream>
#include <ostream>

using namespace std;

void serializeBinaryTree(BinaryTreeNode *root, ostream &stream)
{
    if (root == nullptr) {
        stream << "$,";
        return;
    }
    stream << root->value << ",";
    serializeBinaryTree(root->left, stream);
    serializeBinaryTree(root->right, stream);
}

bool readStream(istream &stream, int *number)
{
    if (stream.eof())
        return false;
    char buffer[32];
    buffer[0] = '\0';
    char c;
    stream >> c;
    int i = 0;
    while (!stream.eof() && c != ',')
        buffer[i++] = c;
    if (i > 0 && buffer[0] != '$') {
        *number = atoi(buffer);
        return true;
    }
    return false;
}
void deserializeBinaryTree(BinaryTreeNode **root, istream &stream)
{
    int number = 0;
    if (readStream(stream, &number)) {
        *root = new BinaryTreeNode;
        (*root)->value = number;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
    }
    deserializeBinaryTree(&((*root)->left), stream);
    deserializeBinaryTree(&((*root)->right), stream);
}

bool isSameTree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->value != root2->value)
        return false;
    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

int main()
{
    return 1;
}
