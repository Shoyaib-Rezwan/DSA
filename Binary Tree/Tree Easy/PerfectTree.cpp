// a binary tree is called perfect if all the internal nodes contain 2 children and all the leaves are in the same level
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
// we will use level order travesal
bool isPerfect(BinNode *root)
{
    queue<BinNode *> q;
    q.push(root);
    bool childrenlevelFound = false; // this variable will check whether the 1st child is found.After that no internal nodes can't be pushed
    while (!q.empty())
    {
        BinNode *current = q.front();
        q.pop();
        // check it has only one child or not
        if ((current->left && !current->right) || (!current->left && current->right))
            return false;
        // check if its an perfect internal node and if we can push any internal nodes or not
        else if (current->left && current->right)
        {
            // return false if the internal node is coming after finding the child level
            if (childrenlevelFound)
                return false;
            q.push(current->left);
            q.push(current->right);
        }
        // else the node must be child
        else
        {
            childrenlevelFound = true;
        }
    }
    return true;
}
int main()
{
    BinNode *root = new BinNode(26);
    root->left = new BinNode(10);
    root->right = new BinNode(10);
    root->left->left = new BinNode(4);
    root->left->right = new BinNode(6);
    root->right->right = new BinNode(6);
    root->right->left = new BinNode(4);
    cout << isPerfect(root);
}