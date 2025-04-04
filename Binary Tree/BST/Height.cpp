// find the height and depth of the tree as well as height and depth of a certain key
#include <iostream>
#include <queue>
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
    if (key < root->key)
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
    if (root->right || root->left)
    {
        cout << "(";
        print(root->left);
        cout << ",";
        print(root->right);
        cout << ")";
    }
}
ostream &operator<<(ostream &stream, Node *root)
{
    stream << '(';
    print(root);
    stream << ')';
    return stream;
}
void findDepthrec(Node *root, int &depth)
{
    static int level = -1;
    if (!root)
        return;
    level++;
    findDepthrec(root->left, depth);
    findDepthrec(root->right, depth);
    depth = max(depth, level);
    level--;
}
// overload
void findDepthrec(Node *root, int &depth, int key)
{
    static int level = -1;
    if (!root)
        return;
    level++;
    // only adjust depth when the root contains the key
    if (root->key == key)
        depth = level;
    findDepthrec(root->left, depth, key);
    findDepthrec(root->right, depth, key);
    level--;
}

int findDepth(Node *root)
{
    int depth = -1;
    findDepthrec(root, depth);
    return depth;
}
int findDepth(Node *root, int key)
{
    int depth = -1;
    findDepthrec(root, depth, key);
    if (depth == -1)
        cout << "Not present\n";
    else
    {
        cout << depth << '\n';
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
    cout << findDepth(root) << '\n';
    findDepth(root, 8);
}