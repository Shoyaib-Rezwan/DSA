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
void iterativeInorder(BinNode *root)
{
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
        // currnt is null
        current = s.top();
        cout << current->data << '\t';
        s.pop();
        // this is a crucial part.
        current = current->right;
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
    iterativeInorder(root);
}
