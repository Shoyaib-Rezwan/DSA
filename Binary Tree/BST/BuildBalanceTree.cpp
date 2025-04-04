// suppose you are given a binary tree which is either balanced or not. Now you have to make it balanced.
// Balanced binary tree:: A binary tree with minimum height
#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};
// first traverse the given tree in inorder and then store the path in an array
void inOrder(Node *root, vector<int> &path)
{
    if (!root)
        return;
    inOrder(root->left, path);
    path.push_back(root->key);
    inOrder(root->right, path);
}
// this is a utility function to build a balanced tree from the given sorted
// array
Node *BSTBalance(vector<int> &path, int l, int r, Node *root)
{
    if (l > r)
        return nullptr;
    // find the moddle of the path
    int mid = (l + r) / 2;
    root = new Node(path.at(mid));
    // then divide the remaining path in to left and right halves
    root->left = BSTBalance(path, l, mid - 1, root->left);
    root->right = BSTBalance(path, mid + 1, r, root->right);
    return root;
}
Node *makeBalanced(Node *root)
{

    vector<int> path;
    inOrder(root, path);
    if (!path.size())
        return nullptr;
    else
    {
        Node *a = nullptr;
        a = BSTBalance(path, 0, path.size() - 1, a);
        return a;
    }
}
void print(Node *root)
{
    if (!root)
        return;
    cout << root->key;
    if (root->left || root->right)
    {
        cout << '(';
        print(root->left);
        cout << ',';
        print(root->right);
        cout << ')';
    }
}
int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    root->right->right->right->right = new Node(5);
    print(root);
    cout << '\n';
    root = makeBalanced(root);
    print(root);
}