// you are given a binary tree. You have to convert it to a BST without
// changing the tree's structure
// clue:: inorderly traverse the binary tree and store the values in
// a vector. Then sort the vector. This vector indicates the inorder
// traversal of the BST. So, for the second time traverse the Binary tree
// in inorder and modify the values of the nodes
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
// this inorder traversal function stores the values inside a vector
void inOrderTraversal(Node *root, vector<int> &path)
{
    if (!root)
        return;
    inOrderTraversal(root->left, path);
    path.push_back(root->data);
    inOrderTraversal(root->right, path);
}
// this inorder traversal function modifies the values of node according
// to the sorted vector
void inOrderTraversal(Node *root, vector<int> &path, int &index)
{
    if (!root)
        return;
    inOrderTraversal(root->left, path, index);
    root->data = path.at(index++);
    inOrderTraversal(root->right, path, index);
}
// the driver function
void convertBST(Node *root)
{
    vector<int> path;
    inOrderTraversal(root, path);
    // sort the path
    sort(path.begin(), path.end());
    int index = 0;
    inOrderTraversal(root, path, index);
}
// printing function
void inOrderTraversal(Node *root)
{
    if (!root)
        return;
    inOrderTraversal(root->left);
    cout << root->data << '\t';
    inOrderTraversal(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    convertBST(root);
    inOrderTraversal(root);
}