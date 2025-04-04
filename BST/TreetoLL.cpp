// suppose you are given a bst. Now you have to make it a Doubly LL
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data = 0)
    {
        this->data = data;
        left = right = nullptr;
    }
};
void treeToLL(Node *&root)
{
    if (root == nullptr)
        return;
    while (root->left)
    {
        Node *temp = root;
        root = root->left;
        temp->left = root->right;
        root->right = temp;
    }
     treeToLL(root->right);
}
void printLL(Node *root)
{
    while (root)
    {
        cout << root->data << ' ';
        root = root->right;
    }
}

int main()
{
    Node *root = new Node(12);
    root->left = new Node(6);
    root->left->right = new Node(10);
    root->right = new Node(18);
    treeToLL(root);
    printLL(root);
}