// you arr given a preorder traversal string of a binary tree. Calculate its depth
// solution :: https://www.geeksforgeeks.org/calculate-depth-full-binary-tree-preorder/
#include <iostream>
using namespace std;
void findDepthRec(char str[], int n, int &index, int &depth)
{
    static int level = -1;
    if (index >= n || str[index] == 'l')
    {
        return;
    }
    level++;
    index++;
    findDepthRec(str, n, index, depth);
    index++;
    findDepthRec(str, n, index, depth);
    depth = max(level, depth);
    level--;
}
int findDepth(char str[], int n)
{
    int depth = INT32_MIN;
    int index = 0;
    findDepthRec(str, n, index, depth);
    return depth + 1;
}
int main()
{
    int n;
    cin >> n;
    char *str = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    int depth = findDepth(str, n);
    cout << depth;
}