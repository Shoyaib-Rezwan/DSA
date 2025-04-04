// suppose there is a binary tree. You have to find that whether there exists an edge or not whose removal wil create two trees with equal number of nodes
// https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr)
    {
    }
};
class Solution
{
    map<Node *, int> memo;

public:
    int countNodes(Node *root)
    {
        if (!root)
            return 0;
        if (memo.find(root) != memo.end())
        {
            return memo[root];
        }
        int nodeCount = 1 + countNodes(root->left) + countNodes(root->right);
        memo.insert({root, nodeCount});
        return nodeCount;
    }
    bool isDivisible(Node *root)
    {
        int totalNodes = countNodes(root);
        for (auto x : memo)
        {
            if (2 * x.second == totalNodes)
                return true;
        }
        return false;
    }
};
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->right = new Node(5);
    Solution obj;
    cout << obj.isDivisible(root);
}