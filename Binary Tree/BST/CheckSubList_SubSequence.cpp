// suppose you are given a BST and a list in form of an array.The list is ensured to be sorted. Now you have to
// check whether the given list is a subarray or subsequence of the inorder traversal of the BST.
// restrictions: You can't store the inorder traversal sequence into any array/other data structures
// time complexity: O(n)
#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};
Node *Insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    else if (root->key > key)
    {
        root->left = Insert(root->left, key);
    }
    else
    {
        root->right = Insert(root->right, key);
    }
    return root;
}
void print(Node *root)
{
    if (!root)
        return;
    cout << root->key;
    if (root->left || root->right)
    {
        cout << '(';
        print(root->left);
        cout << ',';
        print(root->right);
        cout << ')';
    }
}
ostream &operator<<(ostream &stream, Node *root)
{
    stream << "(";
    print(root);
    stream << ")";
    return stream;
}
void inOrder(Node *root, bool &isSublist, int *arr, int n, int &index)
{
    if (index >= n || !root)
        return;
    static bool isFoundFirst = false;
    inOrder(root->left, isSublist, arr, n, index);
    if (root->key == arr[index])
    {
        if (!isFoundFirst)
        {
            isFoundFirst = true;
        }
        index++;
    }
    else if (isFoundFirst)
    {
        isSublist = false;
    }
    inOrder(root->right, isSublist, arr, n, index);
}
void checkList(Node *root, int *arr, int n)
{
    bool isSublist = true;
    int index = 0;
    inOrder(root, isSublist, arr, n, index);
    if (index != n)
        cout << "Nothing\n";
    else
    {
        if (isSublist)
            cout << "Sublist";
        else
            cout << "Subsequence";
    }
}
int main()
{
    Node *root = nullptr;
    int n;
    cin >> n;
    int data;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = Insert(root, data);
    }
    cout << root << '\n';
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    checkList(root, arr, n);
}