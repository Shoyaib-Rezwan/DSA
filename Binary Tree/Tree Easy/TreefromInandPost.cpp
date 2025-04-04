// you are given an inorder and postorder traversal of a binary tree.Build the tree and write the preorder traversal
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
// we will use iterative preorder traversal
void preorder(BinNode *root)
{
    if (!root)
        return;
    stack<BinNode *> s;
    s.push(root);
    BinNode *current;
    while (!s.empty())
    {
        current = s.top();
        s.pop();
        cout << current->data << '\t';
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}
BinNode *TreeBuildRec(BinNode *root, int *in, int *post, int firstin, int lastin, int size)
{
    if (firstin > lastin)
        return nullptr;
    if (firstin == lastin)
    {
        return new BinNode(in[firstin]);
    }
    int i, j;
    for (i = size - 1; i >= 0; i--)
    {
        for (j = firstin; j <= lastin; j++)
        {
            if (in[j] == post[i])
            {
                root = new BinNode(in[j]);
                break;
            }
        }
        if (j <= lastin && in[j] == post[i]) // j looks from 1stin to lastin inclusive. So it's possible for j to overrun the lastin boudary after increament
            break;
    }
    root->left = TreeBuildRec(root->left, in, post, firstin, j - 1, size);
    root->right = TreeBuildRec(root->right, in, post, j + 1, lastin, size);
    return root;
}
BinNode *TreeBuild(int *in, int *post, int size)
{
    BinNode *root = nullptr;
    return TreeBuildRec(root, in, post, 0, size - 1, size);
}
int main()
{
    int n;
    cin >> n;
    int *in = new int[n];
    int *post = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    preorder(TreeBuild(in, post, n));
}