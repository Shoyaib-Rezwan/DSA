// https://youtu.be/nGNoTdav5bQ
// suppose you are given a binary tree.You have to convert it to a DLL which is in the same order of Inorder traversal. Use right as next pointer and left as prev pointer.
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
Node *tail = nullptr;
void treeToDLL(Node *root, Node *&head)
{
    if (!root)
        return;
    treeToDLL(root->left, head);
    if (!tail)
        head = root;
    else
    {
        tail->right = root;
        root->left = tail;
    }
    tail = root;
    treeToDLL(root->right, head);
}
void printDLL(Node *head)
{
    if (!head)
        return;
    while (head)
    {
        cout << head->val << ' ';
        head = head->right;
    }
    cout << '\n';
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(2);
    root->right->left = new Node(1);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(6);
    Node *head = nullptr;
    treeToDLL(root, head);
    printDLL(head);
}