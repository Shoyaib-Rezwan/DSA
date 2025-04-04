// to do this first learn about threaded binary tree
// source:: https://www.geeksforgeeks.org/threaded-binary-tree/
// after that learn about preorder traversal without reccursion or stack
// source:: https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

// this is 90% similar like the morris traversal for inorder.
// the difference is in inorder traversal if you find that the node has a left child then you try to find
//  it's pedecessor.If the predesessor is not connected to the current node then you establish a connection but don't print the current node.Otherwise you print the current node and demolish the relation with it's predecessor.
//  in case of preorder traversal it's kind of opposite.if you find that the node has a left child then you try to findit's pedecessor.If the predesessor is not connected to the current node then you establish a connection and print the node.Otherwise you do the same but don't print the node
#include <iostream>
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
void morrisTraversalPreorder(BinNode *root)
{
    if (root == nullptr)
        return;
    BinNode *current = root;
    BinNode *pre;
    while (current)
    {
        if (current->left)
        {
            pre = current->left;
            while (pre->right != nullptr && pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == nullptr)
            {
                pre->right = current;
                cout << current->data << '\t';
                current = current->left;
            }
            else
            {
                current = current->right;
                pre->right = nullptr;
            }
        }
        else
        {
            cout << current->data << '\t';
            current = current->right;
        }
    }
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
    morrisTraversalPreorder(root);
}