//time and space complexity O(n)
//but it uses an extra function called DFS() which consumes O(n) recursive space
#include <iostream>
#include <vector>
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
void DFS(BinNode *root, vector<int> &count)
{
    static int level = -1;
    if (!root)
        return;
    level++;
    if (count.size() == level)
    {
        count.push_back(1);
    }
    else
    {
        count.at(level)++;
    }
    DFS(root->left, count);
    DFS(root->right, count);
    level--;
}
void SpiralLevelTraversal(BinNode *root)
{
    if (root == nullptr)
        return;
    vector<int> count;
    DFS(root, count);              // count how many nodes are there in each levels
    int levels = count.size() - 1; // levels are started from 0
    vector<BinNode *> path;        // vector to contain the nodes in required order
    path.push_back(root);
    for (int i = 1; i <= levels; i++) // we are not counting the level 0 because we have pushed the root manually
    {
        int j = path.size() - 1; // moving the pointer at the end index of path
        while (count[i - 1]--)   // count[i-1] is the number of parents of the nodes present in the ith level
        {
            // in odd levels, nodes are stored in forward order and even levels, nodes will be in reverse order
            // please implement it in your note khata for better understanding
            if (i % 2)
            {
                if (path[j]->left)
                    path.push_back(path[j]->left);
                if (path[j]->right)
                    path.push_back(path[j]->right);
            }
            else
            {
                if (path[j]->right)
                    path.push_back(path[j]->right);
                if (path[j]->left)
                    path.push_back(path[j]->left);
            }
            j--;
        }
    }
    for (auto &&i : path)
    {
        cout << i->data << '\t';
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
    // vector<int> count;
    // DFS(root, count);
    // for (auto &&i : count)
    // {
    //     cout << i << '\t';
    // }
}