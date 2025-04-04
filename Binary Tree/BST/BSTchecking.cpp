// you are given a binary tree. Check whether its a BST or not
// clue:: inorder traversal of a BST is always sorted
// use the morris traversal
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
// we will use morris traversal for inorder traversal
// usually when we attempt to print a data in case os normal traversal,
// we will now compare the corresponding data with its right child
bool isBST(Node *root)
{
    if (!root)
        return true; // we can consider that an empty tree is a BST
    Node *current = root;
    Node *prev = nullptr;
    while (current)
    {

        if (current->left)
        {
            prev = current->left;
            while (prev->right != nullptr && prev->right != current)
            {
                prev = prev->right;
            }
            if (prev->right == nullptr)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = nullptr;
                if (current->right && current->data >= current->right->data)
                    return false;
                current = current->right;
            }
        }
        else
        {
            if (current->right && current->data >= current->right->data)
                return false;
            current = current->right;
        }
    }
    return true;
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(5);
    root->left->right = new Node(2);
    root->right->left = new Node(4);
    // root->left->right = new Node(1); it will be false
    cout << isBST(root);
}