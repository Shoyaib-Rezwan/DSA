// you are given a BST. Make it balanced.
// this time you cant't sort the elements rather you have to make the tree balance in place
#include <bits/stdc++.h>
#include "BST.h"
void sortElements(Node<int> *root, vector<int> &nums)
{
    if (!root)
        return;
    sortElements(root->left, nums);
    nums.push_back(root->data);
    sortElements(root->right, nums);
}
Node<int> *rightRotate(Node<int> *root)
{
    Node<int> *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}
Node<int> *leftRotate(Node<int> *root)
{
    Node<int> *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}
// this will faltten the BST that is BST will be converted to a singly linked list where only the right pointers will be connected to other node
// as the tree is a BST this flatten tree will be in sorted order
void treeToVain(Node<int> *&root)
{
    Node<int> *tempRoot = root; // this will track the root
    Node<int> *current = root;  // this pointer will traverse through the whole BST
    Node<int> *prev = nullptr;  // this will keep track of the prev node of the BST if current is not the tempRoot
    bool rootFixed = false;     // to identify whether root has been fixed or not
    while (current)
    {
        if (current->left)
        {
            current = rightRotate(current);
            // if root is not fixed then current will be the root. Otherwise add current with prev node
            if (!rootFixed)
                tempRoot = current;
            else
                prev->right = current;
        }
        else
        {
            rootFixed = true;
            prev = current;
            current = current->right;
            // we can move right only when we have made the root fixed because only left nodes can be a root
        }
    }
    root = tempRoot;
}
void deleteBST(Node<int> *root)
{
    if (!root)
        return;
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}
Node<int> *makeBST(vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int mid = l + (r - l) / 2; // this will handle (l+r) from getting overflown
    Node<int> *root = new Node<int>(nums[mid]);
    root->left = makeBST(nums, l, mid - 1);
    root->right = makeBST(nums, mid + 1, r);
    return root;
}
Node<int> *makeBalanced(Node<int> *root)
{
    vector<int> nums;
    sortElements(root, nums);
    int n = nums.size();
    deleteBST(root);
    root = nullptr;
    root = makeBST(nums, 0, n - 1);
    return root;
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
    cout << root << '\n';
    treeToVain(root);
    cout << root;
}