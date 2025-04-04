// you are given level and inorder representation of a tree. Now build a tree from that
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
class BinNode
{
public:
    int key;
    int record;
    BinNode *left;
    BinNode *right;
    BinNode(int key, int record = 0)
    {
        this->key = key;
        this->record = record;
        left = right = nullptr;
    }
};
void inOrder(BinNode *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->key << '\t';
    inOrder(root->right);
}
BinNode *buildTreeRec(BinNode *root, vector<int> &in, vector<int> &level, int startin, int endin)
{

    if (endin < startin)
        return nullptr;

    else if (endin == startin)
        return new BinNode(in.at(startin));

    int i, j;
    for (i = 0; i < level.size(); i++)
    {
        for (j = startin; j < endin; j++)
        {
            if (in.at(j) == level.at(i))
            {
                root = new BinNode(in.at(j));
                break;
            }
        }
        if (in.at(j) == level.at(i))
            break;
    }

    root->left = buildTreeRec(root->left, in, level, startin, j - 1);
    root->right = buildTreeRec(root->right, in, level, j + 1, endin);
    return root;
}
BinNode *buildTree(vector<int> &in, vector<int> &level)
{
    BinNode *root = nullptr;
    int index = 0;
    return buildTreeRec(root, in, level, 0, in.size() - 1);
}

int main()
{
    BinNode *root = nullptr;
    int n;
    cin >> n;
    vector<int> in(n), level(n);
    for (int i = 0; i < n; i++)
    {
        cin >> in.at(i);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> level.at(i);
    }
    root = buildTree(in, level);
    inOrder(root);
}