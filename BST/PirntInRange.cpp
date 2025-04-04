// suppose you are given a BST. You have to print its keys in inorder within a given range
// use morris inoder traversal to solve it
#include <bits/stdc++.h>
#include "BST.h"
void printInRange(Node<int> *root, int n1, int n2)
{
    if (!root)
        return;
    Node<int> *current = root;
    Node<int> *pred = nullptr;
    while (current)
    {
        if (!current->left)
        {
            if (current->data >= n1 && current->data <= n2)
                cout << current->data << ' ';
            else if (current->data > n2)
                break;
            current = current->right;
        }
        else
        {
            pred = current->left;
            while (pred->right && pred->right != current)
            {
                pred = pred->right;
            }
            if (!pred->right)
            {
                pred->right = current;
                current = current->left;
            }
            else
            {
                pred->right = nullptr;
                if (current->data >= n1 && current->data <= n2)
                    cout << current->data << ' ';
                else if (current->data > n2)
                    break;
                current = current->right;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    Node<int> *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    int n1, n2;
    cin >> n1 >> n2;
    printInRange(root, n1, n2);
}