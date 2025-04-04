#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
int find2ndLargest(Node<int> *root, int &count)
{
    if (!root)
        return -1;

    // Search in the right subtree first (to find the largest elements first)
    int val = find2ndLargest(root->right, count);
    if (val != -1)
        return val; // If second largest is found in right subtree, return it

    // Increment count for the current node
    count++;
    if (count == 2)
        return root->data; // If this is the second largest node, return its value

    // Continue to the left subtree if no result found so far
    return find2ndLargest(root->left, count);
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
    int count = 0;
    cout << find2ndLargest(root, count);
}