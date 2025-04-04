// https://youtu.be/Toe0UQMWhjM
// diameter of a tree is the maximum distance between 2 leaf nodes
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};
int height(Node *root)
{
    int ht = -1;
    if (!root)
        return ht;
    ht = 1 + max(height(root->left), height(root->right));
    return ht;
}
int diameter(Node *root)
{
    if (!root)
        return -1;
    int d = max(diameter(root->left), diameter(root->right));
    d = max(d, height(root->left) + height(root->right) + 2);
    return d;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(4);
    root->left->left = new Node(5);
    root->left->left->left = new Node(7);
    root->left->left->left->left = new Node(8);
    root->left->left->left->left->right = new Node(11);
    root->left->left->right = new Node(6);
    root->left->left->right->right = new Node(9);
    root->left->left->right->right->right = new Node(10);
    root->right = new Node(12);
    root->right->left = new Node(12);
    cout << diameter(root);
}