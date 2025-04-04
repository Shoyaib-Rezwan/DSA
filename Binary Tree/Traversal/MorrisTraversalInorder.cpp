// to do this first learn about threaded binary tree
// source:: https://www.geeksforgeeks.org/threaded-binary-tree/
// after that learn about inorder traversal without reccursion or stack
// source:: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/
#include <iostream>
#include <stack>
using namespace std;
#define node(data) new BinNode(data)
class BinNode
{
public:
    int data;
    BinNode *left;
    BinNode *right;
    BinNode(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};
void MorrisTraversal(BinNode *root)
{
    if (!root)
        return;
    BinNode *current = root;
    BinNode *pre = nullptr; // track the predecessors
    while (current)
    {
        // if current has no left child then print it and move it to right
        if (!current->left)
        {
            cout << current->data << '\t';
            current = current->right;
        }
        // if current has a left child then move predecessor pointer pre to that
        // child
        else
        {
            pre = current->left;
            // now find the rightmost child. It will be predecessor of current
            // but if we have done it before then the rightmost child is already
            // connected to the current node
            while (pre->right && pre->right != current)
            {
                pre = pre->right;
            }
            // add predecessor with its successor current if it's already not and current left
            if (pre->right == nullptr)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                // print current and move to the successor
                cout << current->data << '\t';
                current = current->right;
            }
        }
    }
}
void inorderTraversal(BinNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}
int main()
{
    BinNode *root = node(1);
    root->left = node(2);
    root->right = node(6);
    root->left->left = node(3);
    root->left->right = node(5);
    root->left->left->left = node(4);
    root->right->right = node(7);
    root->right->right->left = node(8);
    MorrisTraversal(root);
}