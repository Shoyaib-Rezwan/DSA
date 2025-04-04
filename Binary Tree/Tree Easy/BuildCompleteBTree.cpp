// you are given an array of integers. Now build a complete binary tree from it.
#include <iostream>
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
BinNode *insert(BinNode *root, int data)
{
    BinNode *newNode = new BinNode(data);
    if (!root)
        return newNode;
    queue<BinNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BinNode *temp = q.front(); // you must use a temporary Node to store the queue values
        q.pop();
        if (!temp->left)
        {
            temp->left = newNode;
            break;
        }
        else
        {
            q.push(temp->left);
        }
        if (!temp->right)
        {
            temp->right = newNode;
            break;
        }
        else
        {
            q.push(temp->right);
        }
    }
    return root;
}
void inorderTraversal(BinNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << ' ';
    inorderTraversal(root->right);
}
BinNode *BuildCompleteBTree(int *arr, int n)
{
    BinNode *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BinNode *root = BuildCompleteBTree(arr, n);
    inorderTraversal(root);
}