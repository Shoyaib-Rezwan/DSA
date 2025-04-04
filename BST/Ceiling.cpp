// its similar to floor.cpp . This time you will find ceiling value by recursion.
#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
int findCeil(Node<int> *root, int x, int ceilVal = INT32_MAX)
{
    if (!root)
    {
        return ceilVal;
    }
    if (root->data == x)
    {
        ceilVal = x;
        return ceilVal;
    }
    if (root->data > x)
    {
        ceilVal = min(ceilVal, root->data);
        return findCeil(root->left, x, ceilVal);
    }
    else
    {
        return findCeil(root->right, x, ceilVal);
    }
}
int main()
{
    Node<int> *root;
    root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        root = insert(root, data);
    }
    int x;
    cin >> x;
    int ceilVal = findCeil(root, x);
    if (ceilVal == INT32_MAX)
    {
        cout << "No ceiling Value found!";
    }
    else
    {
        cout << ceilVal;
    }
}