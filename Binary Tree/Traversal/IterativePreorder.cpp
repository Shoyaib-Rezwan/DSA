
#include <bits/stdc++.h>
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
void iterativePostorder(BinNode *root)
{
    if (!root)
        return;
    stack<BinNode *> s;
    s.push(root);
    BinNode *current = new BinNode(0);
    while (!s.empty())
    {
        current = s.top();
        cout << current->data << '\t'; // print the stack's topmost data
        s.pop();
        if (current->right) // put the right children at 1st and then the left. After that left child will be at the top
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}
int main()
{
    BinNode *root = new BinNode(1);
    root->left = new BinNode(5);
    root->right = new BinNode(7);
    root->left->left = new BinNode(24);
    root->left->right = new BinNode(3);
    root->right->left = new BinNode(8);
    root->right->right = new BinNode(4);
    root->left->left->left = new BinNode(2);
    root->right->left->right = new BinNode(9);
    root->right->left->right->left = new BinNode(90);
    iterativePostorder(root);
}
