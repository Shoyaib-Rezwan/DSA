// https://youtu.be/cOjLyASDJcc
//  You are given a binary tree and two nodes.Find the LCA of the 2 nodes.
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};
Node *LCA(Node *root, Node *a, Node *b)
{
    if (!root)
        return nullptr;
    if (root == a || root == b)
    {
        return root;
    }
    Node *l = LCA(root->left, a, b);
    Node *r = LCA(root->right, a, b);
    if (l && r)
    {
        return root;
    }
    if (l)
        return l;
    return r;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(2);
    root->right->left = new Node(1);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);
    cout << LCA(root, root->right->left->left, root->right->left->right)->val;
}