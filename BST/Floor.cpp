// you are given a bst and a variable x.You have to find the florr value of x from the bst. A floor value of x is either equal or the nearest small value to x
// don't use recursion because it will cause O(h) recursion stack consumption.
#include "BST.h"
#include <bits/stdc++.h>
using namespace std;
int findFloor(Node<int> *root, int x)
{
    if (!root)
        return -1;
    int floor = INT32_MIN;
    while (root)
    {
        if (root->data == x)
        {
            floor = x;
            break;
        }
        if (root->data < x)
        {
            floor = max(floor, root->data);
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return floor;
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
    int floorVal = findFloor(root, x);
    if (floorVal == INT32_MIN)
    {
        cout << "No floor Value found!";
    }
    else
    {
        cout << floorVal;
    }
}