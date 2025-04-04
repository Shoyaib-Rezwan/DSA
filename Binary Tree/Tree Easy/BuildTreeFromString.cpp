// you are given a string of level order traversal of a binary tree.Build a tree from it
// source::https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/
// ex:: 4(2(3)(1))(6(5))
#include <iostream>
#include <string>
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
void preOrder(BinNode *root)
{
    if (!root)
        return;
    cout << root->data << '\t';
    preOrder(root->left);
    preOrder(root->right);
}
BinNode *buildTree(BinNode *root, string str, int &start)
{
    // initial condition
    if (str.size() == 0 || start >= str.size())
        return nullptr;
    // find the number from the string
    int num = 0;
    while (str[start] != '(' && str[start] != ')')
    {
        num = num * 10 + str[start] - '0';
        start++;
    }
    // for now we are just considering that our tree won't contain 0
    if (num)
        root = new BinNode(num);
    // if you encounter the 1st '(' then start to build the left subtree
    if (start < str.size() && str[start] == '(') // if you don't check start
    // then it may overrun the boundary and throw an error
    {
        start++;
        root->left = buildTree(root->left, str, start);
    }
    // if you encounter the 1st ')' then stop building the left subtree
    if (start < str.size() && str[start] == ')')
    {
        start++;
    }
    // if you encounter the 2nd '(' then build the right subtree
    if (start < str.size() && str[start] == '(')
    {
        start++;
        root->right = buildTree(root->right, str, start);
    }
    return root;
}
int main()
{
    string str;
    cin >> str;
    BinNode *root = nullptr;
    int start = 0;
    root = buildTree(root, str, start);
    preOrder(root);
}