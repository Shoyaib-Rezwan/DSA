#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector<vector<int>> initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> mat(V, vector<int>(V));
    for (auto x : edges)
    {
        mat[x.first][x.second] = 1;
    }
    return mat;
}
void displayMat(vector<vector<int>> mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int x : mat[i])
        {
            cout << x << "\t";
        }
        cout << "\n";
    }
}
void BFS(vector<vector<int>> mat, int startNode)
{
    int V = mat.size(), i;
    vector<bool> visited(V);
    visited[startNode] = true;
    queue<int> q;
    q.push(startNode);
    while (q.empty() == false)
    {
        int n = q.front();
        q.pop();
        cout << n << " ";
        for (i = 0; i < V; i++)
        {
            if (mat[n][i] && visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    int V = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 1}, {2, 5}, {3, 0}, {4, 1}, {4, 5}, {5, 2}, {5, 4}};
    vector<vector<int>> mat = initGraph(V, edges);
    displayMat(mat);
    BFS(mat, 0);
}