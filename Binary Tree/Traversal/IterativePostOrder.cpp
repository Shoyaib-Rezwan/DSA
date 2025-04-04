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
    stack<BinNode *> s2;
    s.push(root);
    BinNode *current = root;
    while (!s.empty())
    {
        current = s.top();
        s2.push(current);
        s.pop();
        if (current->left)
            s.push(current->left);
        if (current->right)
            s.push(current->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << '\t';
        s2.pop();
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
