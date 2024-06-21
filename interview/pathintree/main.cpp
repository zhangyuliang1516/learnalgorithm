#include "../utils/binarytree.h"

#include <iostream>
#include <vector>

using namespace std;

void findPath(BinaryTreeNode *root, int expectedSum, vector<int> &path, int currentSum)
{
    path.push_back(root->value);
    currentSum += root->value;
    bool isLeaf = (root->left == nullptr && root->right == nullptr);
    if (currentSum == expectedSum && isLeaf) {
        cout << "Find path: ";
        for (auto iter = path.begin(); iter != path.end(); ++iter)
            cout << *iter << " ";
        cout << endl;
    }
    if (root->left)
        findPath(root->left, expectedSum, path, currentSum);
    if (root->right)
        findPath(root->right, expectedSum, path, currentSum);
    path.pop_back();
    currentSum -= root->value;
}
void findPath(BinaryTreeNode *root, int expectedSum)
{
    if (root == nullptr)
        return;
    vector<int> path;
    int currentSum = 0;
    findPath(root, expectedSum, path, currentSum);
}

int main()
{
    return 0;
}
