// you are given a BST and a target key. You have to find the key's successor key (if it exists)
// hint: if you print inorder tarversal of nodes of a bst then you will see them in sorted non decreasing order
// so inorder successor of a node is the nearest larget element of that node data
#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
int inorderSuccesor(Node<int> *root, int target)
{
    if (!root)
    {
        return -1; // assuming that only positive numbers will be in the BST
    }
    if (root->data == target)
    {
        // now find its successor
        if (!root->right)
        {
            return -2; // that means target is the largest value in the BST
        }
        root = root->right;
        while (root->left)
        {
            root = root->left;
        }
        return root->data;
    }
    if (root->data > target)
    {
        return inorderSuccesor(root->left, target);
    }
    else
        return inorderSuccesor(root->right, target);
}
int main()
{
    Node<int> *root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    int target;
    cin >> target;
    target = inorderSuccesor(root, target);
    if (target == -1)
    {
        cout << "Target not found!";
    }
    else if (target == -2)
    {
        cout << "Target doesn't have any successor!";
    }
    else
        cout << target;
}