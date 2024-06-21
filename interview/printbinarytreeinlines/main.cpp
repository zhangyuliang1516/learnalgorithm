#include "../utils/binarytree.h"

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

void printBinaryTreeInLines(BinaryTreeNode *root)
{
    if (root == nullptr)
        return;
    deque<BinaryTreeNode *> nodes;
    nodes.push_back(root);
    int toBePrinted = 1;
    int nextLevel = 0;
    while (nodes.size() > 0) {
        BinaryTreeNode *node = nodes.front();
        nodes.pop_front();
        toBePrinted--;
        cout << node->value << " ";
        if (node->left) {
            nodes.push_back(node->left);
            nextLevel++;
        }
        if (node->right) {
            nodes.push_back(node->right);
            nextLevel++;
        }
        if (toBePrinted == 0) {
            cout << endl;
            toBePrinted = nextLevel;
            nextLevel = 0;
        }
    }
}

int main()
{
    return 0;
}
