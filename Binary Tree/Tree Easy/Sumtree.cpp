// suppose you have a binary tree. Check whether its a sum tree or not. A sum tree is binary tree in which each of the node is the sum of all nodes present in its left and right subtrees
#include <iostream>
#include <stack>
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
int sum(BinNode *root)
{
    if (!root)
        return 0;
    else
        return root->data + sum(root->left) + sum(root->right);
}
bool isLeaf(BinNode *node)
{
    if (node->left || node->right)
        return false;
    else
        return true;
}
bool isSumTree(BinNode *root)
{
    // use iterative inorder traversal and justify sum tree for each internal nodes
    if (root == nullptr)
        return false;
    stack<BinNode *> s;
    s.push(root);
    BinNode *current = root->left;
    while (!s.empty() || current)
    {
        while (current)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        if (!isLeaf(current) && 2 * current->data != sum(current))
            return false;
        current = current->right;
    }
    return true;
}
int main()
{
    BinNode *root = new BinNode(26);
    root->left = new BinNode(10);
    root->right = new BinNode(3);
    root->left->left = new BinNode(4);
    root->left->right = new BinNode(6);
    root->right->right = new BinNode(3);
    cout << isSumTree(root);
}
