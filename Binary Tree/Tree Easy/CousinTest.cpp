// suppose you have a binary tree. Determine if two nodes are cousin or not.
// two nodes are called cousin if they are at the same level but they are not from the same parent
#include <iostream>
#include <stack>
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
bool isCousins(BinNode *root, int a, int b)
{
    if (!root)
        return false;
    // create two stacks to hold altenate levels' nodes
    stack<BinNode *> s1, s2;
    s1.push(root);
    // continue until both stacks are empty
    while (!s1.empty() || !s2.empty())
    {
        // track whether a and b are found or not
        bool afound = false;
        bool bfound = false;
        BinNode *sibling;
        // at a time either one of the stacks will contain nodes
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                BinNode *parent = s1.top();
                s1.pop();
                if (parent->left)
                {
                    s2.push(parent->left);
                    // if the left child contains either of a and b then mark the right child as its sibling because the sibling is not cousin.
                    if (parent->left->data == a)
                    {
                        afound = true;
                        sibling = parent->right;
                    }
                    else if (parent->left->data == b)
                    {
                        bfound = true;
                        sibling = parent->right;
                    }
                }
                if (parent->right)
                {
                    s2.push(parent->right);
                    if (parent->right->data == a)
                    {
                        afound = true;
                    }
                    else if (parent->right->data == b)
                    {
                        bfound = true;
                    }
                }
            }
        }
        // continue the same procedure if the stack 2 is not empty
        else
        {
            while (!s2.empty())
            {
                BinNode *parent = s2.top();
                s2.pop();
                if (parent->left)
                {
                    s1.push(parent->left);
                    // if the left child contains either of a and b then mark the right child as its sibling because the sibling is not cousin.
                    if (parent->left->data == a)
                    {
                        afound = true;
                        sibling = parent->right;
                    }
                    else if (parent->left->data == b)
                    {
                        bfound = true;
                        sibling = parent->right;
                    }
                }
                if (parent->right)
                {
                    s2.push(parent->right);
                    if (parent->right->data == a)
                    {
                        afound = true;
                    }
                    else if (parent->right->data == b)
                    {
                        bfound = true;
                    }
                }
            }
        }
        // if both a and b are found and neither of their value equals to its sibling's value
        if (afound && bfound && ((sibling && sibling->data != a && sibling->data != b) || !sibling))
            return true;
    }
    return false;
}
int main()
{
    BinNode *root = new BinNode(26);
    root->left = new BinNode(10);
    root->right = new BinNode(3);
    root->left->left = new BinNode(4);
    root->left->right = new BinNode(6);
    root->right->right = new BinNode(8);
    // cout << isSumTree(root);
    cout << isCousins(root, 10, 3);
}