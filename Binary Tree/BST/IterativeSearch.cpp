// you are given a bianry tree. You have to search a key without any recursion or extra memory
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
Node *find(Node *root, int key)
{
    while (root)
    {
        if (root->key == key)
            return root;
        else if (root->key > key)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
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
    Node *temp = find(root, 41);
    if (temp)
    {
        cout << "Found!!";
    }
    else
    {
        cout << "Not found!!";
    }
}