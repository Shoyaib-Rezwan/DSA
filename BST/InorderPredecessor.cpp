// don't use recursion
#include <bits/stdc++.h>
#include "BST.h"
int inorderPredecessor(Node<int> *root, int target)
{
    if (!root)
    {
        return -1;
    }
    int pred = -2;
    while (root)
    {
        if (root->data == target)
        {
            if (!root->left)
            {
                // it has two meanings
                // either the node is the smallest one so it doesn't have any predecessor
                // otherwise it is a leaf so it doesn't have any left child
                // so you must track predecessor by an arbitary variable
                return pred;
                // if -2 is returned that means though the target is in the BST but its the samllest and hence doesn't have any predecessor
            }
            root = root->left;
            while (root->right)
            {
                root = root->right;
            }
            return root->data;
        }
        else if (root->data < target)
        {
            // root->data be a potential predecessor
            pred = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }
    return -1;
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
    int target;
    cin >> target;
    target = inorderPredecessor(root, target);
    cout << target << '\n';
}