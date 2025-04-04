#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int V = 6;
vector<bool> visited(V);
vector<vector<int>> initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> mat(V, vector<int>(V)); // don't forget to initialize the matrix
    for (auto i : edges)
    {
        mat[i.first][i.second] = 1;
    }
    return mat;
}
void displayAdjMat(vector<vector<int>> mat)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}
void dfs(vector<vector<int>> mat, int startNode)
{
    if (visited[startNode] == true)
        return;
    else
    {
        visited[startNode] = true;
        cout << startNode << " ";
        for (int i = 0; i < V; i++)
        {
            if (mat[startNode][i])
            {
                dfs(mat, i);
            }
        }
    }
}
int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 1}, {2, 5}, {3, 0}, {4, 1}, {4, 5}, {5, 2}, {5, 4}};
    vector<vector<int>> mat = initGraph(V, edges);
    displayAdjMat(mat);
    dfs(mat, 0);
}