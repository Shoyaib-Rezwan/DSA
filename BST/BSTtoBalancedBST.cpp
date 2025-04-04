// you are given a BST. Make it balanced.
// sort the elements in the array and then recursively find the middle to build the bst
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
    root = makeBalanced(root);
    cout << root;
}