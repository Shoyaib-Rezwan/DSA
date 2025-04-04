// Given a binary tree, find out if the tree can be folded or not .A tree can be folded if the left and right subtrees of the tree are structure - wise mirror images of each other.An empty tree is considered foldable.
#include <iostream>
#include <queue>
using namespace std;
class BinNode
{
public:
    int data;
    BinNode *left;
    BinNode *right;
    BinNode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
bool isFoldable(BinNode *root1, BinNode *root2)
{

    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return isFoldable(root1->left, root2->right) && isFoldable(root1->right, root2->left);
}
int main()
{
    BinNode *root = new BinNode(10);
    root->left = new BinNode(7);
    root->right = new BinNode(15);
    root->left->left = new BinNode(8);
    root->left->right = new BinNode(9);
    root->right->left = new BinNode(11);
    root->left->left->right = new BinNode(12);
    root->right->right = new BinNode(10);
    root->right->right->left = new BinNode(13);
    cout << isFoldable(root->left, root->right);
}