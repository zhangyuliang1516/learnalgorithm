#include "../utils/binarytree.h"

#include <iostream>

using namespace std;

BinaryTreeNode *constructCore(int *startPreorder, int *endPreorder, int *startInorder,
                              int *endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = createBinaryTreeNode(rootValue);
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        else
            throw exception("Invalid input!");
    }
    int *rootInorder = startInorder;
    while (rootInorder < endInorder && *rootInorder != rootValue)
        rootInorder++;
    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw exception("Invalid input!");
    int leftLength = rootInorder - startInorder;
    int *endLeftPreorder = startPreorder + leftLength;
    if (leftLength > 0) {
        root->left =
            constructCore(startPreorder + 1, endLeftPreorder, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->right = constructCore(endLeftPreorder + 1, endPreorder, rootInorder + 1, endInorder);
    }
    return root;
}

BinaryTreeNode *construct(int *preorder, int *inorder, int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    return constructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void test(const char *testName, int *preorder, int *inorder, int length)
{
    if (testName)
        cout << testName << " begin:" << endl;
    cout << "preorder is: ";
    for (int i = 0; i < length; ++i)
        cout << preorder[i] << " ";
    cout << endl;
    cout << "inorder is: ";
    for (int i = 0; i < length; ++i)
        cout << inorder[i] << " ";
    cout << endl;
    try {
        BinaryTreeNode *root = construct(preorder, inorder, length);
        printBinaryTree(root);
        destroyBinaryTree(root);
    } catch (exception &e) {
        cout << e.what() << endl;
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void test1()
{
    int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    test("Test1", preorder, inorder, 8);
}

// 所有结点都没有右子结点
//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
void test2()
{
    int preorder[] = { 1, 2, 3, 4, 5 };
    int inorder[] = { 5, 4, 3, 2, 1 };
    test("Test2", preorder, inorder, 5);
}

// 所有结点都没有左子结点
//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//                   \
//                    5
void test3()
{
    int preorder[] = { 1, 2, 3, 4, 5 };
    int inorder[] = { 1, 2, 3, 4, 5 };
    test("Test3", preorder, inorder, 5);
}

void test4()
{
    int preorder[] = { 1 };
    int inorder[] = { 1 };
    test("Test4", preorder, inorder, 1);
}

// 完全二叉树
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
void test5()
{
    int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
    int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
    test("Test5", preorder, inorder, 7);
}

void test6()
{
    test("Test6", nullptr, nullptr, 0);
}

void test7()
{
    int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
    int inorder[] = { 4, 2, 8, 1, 6, 3, 7 };
    test("Test7", preorder, inorder, 7);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
