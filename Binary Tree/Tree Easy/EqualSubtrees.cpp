// suppose you have a bianry tree. check whether it contains two equal subtrees or not. Subtrees must be of size 2 or larger.That means a single leaf won't be considered as a subtree
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
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
// use inorder traversal to store the path sequence of a tree inside a vector
void inOrderTraversal(BinNode *root, vector<int> &path)
{
    if (!root)
        return;
    inOrderTraversal(root->left, path);
    path.push_back(root->data);
    inOrderTraversal(root->right, path);
}
// convert the vector into a string
string toString(vector<int> &path)
{
    string str;
    char *ch = new char[10];
    for (int i = 0; i < path.size(); i++)
    {
        str = str + itoa(path.at(i), ch, 10) + '/';
    }
    return str;
}
// check whether a node is leaf or not
bool isLeaf(BinNode *node)
{
    return !node->left && !node->right;
}
bool equalSubtrees(BinNode *root)
{
    unordered_map<string, int> m; // we can't use map because it doesn't allow multiple key with same value
    // use BFS/level order traversal to traverse all the nodes
    queue<BinNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BinNode *current = q.front();
        q.pop();
        vector<int> path;
        inOrderTraversal(current, path); // contain the traversal of the subtree rooetd at current into path
        string pathStr = toString(path); // convert the path to string
        // check whether pathStr is already in the map
        if (m[pathStr])
            return true;
        else
            m[pathStr]++; // the value for a certain key in an unordered map is initialized to 0
        // don't track the leaves, we don't need them
        if (current->left && !isLeaf(current->left))
            q.push(current->left);
        if (current->right && !isLeaf(current->right))
            q.push(current->right);
    }
    return false;
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
    cout << equalSubtrees(root);
}