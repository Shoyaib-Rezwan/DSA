#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
void reverseLevelOrder(BinNode *root)
{
    if (!root)
        return;
    vector<int> path;
    queue<BinNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BinNode *temp = q.front();
        q.pop();
        path.push_back(temp->data);
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
    reverse(path.begin(), path.end());
    for (auto &&i : path)
    {
        cout << i << '\t';
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
    reverseLevelOrder(root);
}