#include <bits/stdc++.h>
using namespace std;
template <typename X>
class Node
{
public:
    X data;
    Node *left;
    Node *right;
    Node(X data, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
template <typename X>
Node<X> *insert(Node<X> *root, X data)
{
    if (!root)
    {
        root = new Node<X>(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
        root->right = insert(root->right, data);
}
template <typename X>
ostream &operator<<(ostream &stream, Node<X> *root)
{
    if (!root)
    {
        stream << "_";
        return stream;
    }
    stream << root->data;
    if (root->left || root->right)
    {
        stream << "(";
        operator<<(stream, root->left);
        stream << ",";
        operator<<(stream, root->right);
        stream << ")";
    }
    return stream;
}
template <typename X>
Node<X> *deleteNode(Node<X> *root, X data)
{
    if (!root)
        return root;
    if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (!root->left)
        {
            Node<X> *temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right)
        {
            Node<X> *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node<X> *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
