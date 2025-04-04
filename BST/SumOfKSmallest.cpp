#include <bits/stdc++.h>
#include "BST.h"
using namespace std;
int findSum(Node<int> *root, int &count, int k)
{
    if (!root)
        return 0;
    int sum = findSum(root->left, count, k);
    if (count < k)
    {
        count++;
        return sum + root->data + findSum(root->right, count, k);
    }
    return sum;
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
    cout << findSum(root, count, 3);
}