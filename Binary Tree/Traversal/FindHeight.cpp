#include <iostream>
using namespace std;
class BinNode
{
public:
    int data;
    BinNode *left;
    BinNode *right;
    BinNode(int data, BinNode *left = nullptr, BinNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
void FindHeight(BinNode *root, int &height) // it's actually a DFS algorithm
{
    static int count = 0;
    if (!root)
    {
        return;
    }
    count++; // add a valid node
    FindHeight(root->left, height);
    FindHeight(root->right, height);
    height = max(height, count);
    count--; // reduce the number of node at the time of backtracking
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
    root->left->right->right->right = new BinNode(21);
    root->right->right = new BinNode(2);
    int height = INT32_MIN;
    FindHeight(root, height);
    cout << height;
}