// it's more efficient because int consumes sapce for 2 stacks
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
void SpiralLevelTraversal(BinNode *root)
{
    stack<BinNode *> s1;               // stack for nodes to print left to right
    stack<BinNode *> s2;               // stack for nodes to print right to left
    s2.push(root);                     // you have to consider that the root is in the reverse order level
    while (!s1.empty() || !s2.empty()) // continue until both stacks are empty
    {
        while (!s1.empty()) // empty the s1 stack and push their children in s2 stack
        {
            BinNode *temp = s1.top(); // hold the topmost node
            s1.pop();                 // remove the topmost node
            cout << temp->data << '\t';
            // push the children in actual order then they will be stored in the stack2 in reverse order
            if (temp->left)
                s2.push(temp->left);
            if (temp->right)
                s2.push(temp->right);
        }
        while (!s2.empty())
        {
            BinNode *temp = s2.top(); // hold the topmost node
            s2.pop();                 // remove the topmost node
            cout << temp->data << '\t';
            // push the children in reverse order then they will be stored in the stack i n reverse order
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }
}
int main()
{
    BinNode *root = new BinNode(1);
    root->left = new BinNode(5);
    root->right = new BinNode(7);
    root->left->left = new BinNode(24);
    root->left->right = new BinNode(3);
    root->right->left = new BinNode(8);
    root->right->right = new BinNode(4);
    root->left->left->left = new BinNode(2);
    root->right->left->right = new BinNode(9);
    root->right->left->right->left = new BinNode(90);
    SpiralLevelTraversal(root);
}