// the idea is to do level order traversal.If we find a node with an empty left child first then we will insert the node their.Otherwise, if we find a node with an empty right child first then we will insert the node their.
#include <iostream>
#include <queue>
using namespace std;
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
void insert(BinNode *root, int data)
{
    if (root == nullptr)
    {
        root->data = data;
        return;
    }
    queue<BinNode *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (!root->left)
        {
            root->left = new BinNode(data);
            return;
        }
        else if (!root->right)
        {
            root->right = new BinNode(data);
            return;
        }
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
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
    BinNode *root = new BinNode(5);
    root->left = new BinNode(6);
    root->right = new BinNode(8);
    root->left->left = new BinNode(12);
    root->left->right = new BinNode(15);
    root->left->right->left = new BinNode(17);
    root->left->right->right = new BinNode(21);
    root->right->right = new BinNode(2);
    insert(root, -20);
    inorderTraversal(root);
}