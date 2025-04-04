// details anotti laaksonen 7.1.2
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> initGraph(int V, vector<pair<int, int>> &edges) // V=no. of edges
{
    vector<vector<int>> adj(V);
    // adding edges to the list
    int noOfEdges = edges.size(), i;
    for (i = 0; i < noOfEdges; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    return adj;
}
void DisplayAdjacencyList(vector<vector<int>> adj)
{
    int V = adj.size(), i;
    for (i = 0; i < V; i++)
    {
        cout << i << " ";
        for (auto j : adj[i])
        {
            cout << "-> " << j << ' ';
        }
        cout << "\n";
    }
}
int main()
{
    int V = 4;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 3}, {3, 0}};
    vector<vector<int>> adj(V);
    adj = initGraph(V, edges);
    DisplayAdjacencyList(adj);
}