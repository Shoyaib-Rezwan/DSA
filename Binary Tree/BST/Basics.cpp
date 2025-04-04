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
// insert a key inside the BST
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    // if the key is smaller then the key will be in the left subtree
    if (root->key > key)
    {
        root->left = insert(root->left, key);
    }
    // otherwise the key is either equal or larger. In both cases they will be in the right
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}
// this function doesn't print the opening and ending brackets
void printrec(Node *root)
{
    if (!root)
        return;
    cout << root->key;
    if (root->left || root->right)
    {
        cout << '(';
        printrec(root->left);
        cout << ',';
        printrec(root->right);
        cout << ')';
    }
}
// if there is no node then '()' will be printed
ostream &operator<<(ostream &stream, Node *root)
{
    stream << '(';
    printrec(root);
    stream << ')';
    return stream;
}
// deletes the node with minimum key
Node *deleteMin(Node *root)
{
    if (!root->left)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    Node *parent;
    Node *current = root;
    while (current->left)
    {
        parent = current;
        current = current->left;
    }
    parent->left = current->right;
    delete current;
    return root;
}
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr; // suppose the key is at the root
    if (root->key == key)
    {
        // the tree has only right child
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // the tree has only left child
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // the tree has both children
        else
        {
            // find the inorder successor
            Node *current = root->right;
            Node *parent = root;
            while (current->left)
            {
                parent = current;
                current = current->left;
            }
            // store the value of the current in the root
            root->key = current->key;
            // current is the inorder successor
            // Notice that current doesn't have any letf child
            root->right = deleteNode(root->right, current->key); // current-key is occurred twice so delete it
            // we have write the previous line because the inorder successor of the root is at the right
            // we can only delete nodes with no or single child
            return root;
        }
    } // if the key is smaller then search in the left subtree
    else if (root->key > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }
    return root;
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
        root = insert(root, data);
    }
    cout << root << '\n';
    root = deleteNode(root, 12);
    cout << root;
}