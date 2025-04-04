#include <iostream>
using namespace std;
class BinNode
{
public:
    int data;
    BinNode *left;
    BinNode *right;
    BinNode(int data, BinNode *left = nullptr, BinNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
void preorderTraversal(BinNode *root)
{
    if (!root)
        return;
    cout << root->data << '\t';
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    BinNode *root = new BinNode(5);
    root->left = new BinNode(6);
    root->right = new BinNode(8);
    root->left->left = new BinNode(12);
    root->left->right = new BinNode(15);
    root->left->right->left = new BinNode(17);
    root->left->right->right = new BinNode(21);
    root->right->right = new BinNode(2);
    preorderTraversal(root);
}