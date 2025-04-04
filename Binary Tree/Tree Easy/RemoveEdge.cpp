// suppose you have a binary tree. Now whether thier exists an edge on removal of which will divide the tree into two subtrees with equal nodes
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
int Nodes(BinNode *root) // calculate number of nodes present in the binary tree rooted at root
{
    // I will use iterative preorder trversal
    int count = 0;
    stack<BinNode *> s;
    s.push(root);
    BinNode *current;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        count++;
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
    return count;
}
bool divisionPossible(BinNode *root) // it will check whether exists such an edge or not
{
    if (!root)
        return false;
    int totalNodes = Nodes(root); // store total nodes
    // traverse all nodes using iterative preorder traversal
    stack<BinNode *> s;
    s.push(root);
    BinNode *current;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        int count = Nodes(current); // count all nodes rooted at the current node
        // return true if count is also the number present at the remaining subtree
        if (2 * count == totalNodes)
            return true;
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
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
    cout << divisionPossible(root);
}
// more easy method!! if the tree contains even number of nodes then its divisible.So
// counting nodes will be enough and it will be in O(n) time and space complexity