#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int V = 6;         // No. of vertices
vector<bool> visited(V); // it will be initialized to false
vector<vector<int>>
initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
    }
    return adj;
}
void DisplayAdjList(vector<vector<int>> adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (auto &&j : adj[i])
        {
            cout << "-> " << j << " ";
        }
        cout << "\n";
    }
}
void dfs(vector<vector<int>> adj, int initialNode)
{
    if (visited[initialNode] == true)
        return;
    else
    {
        visited[initialNode] = true;
        cout << initialNode << " ";
        for (auto &&i : adj[initialNode])
        {
            dfs(adj, i);
        }
    }
}
int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 1}, {2, 5}, {3, 0}, {4, 1}, {4, 5}, {5, 2}, {5, 4}};
    vector<vector<int>> adj = initGraph(V, edges);
    DisplayAdjList(adj);
    dfs(adj, 0);
}