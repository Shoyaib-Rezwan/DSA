#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;
vector<vector<pair<int, int>>> initGraph(int V, vector<tuple<int, int, int>> &edges)
{
    vector<vector<pair<int, int>>> adj(V); // intializing node-> adjacentNode(weight)
    int noOfEdges = edges.size(), i;
    // insrting the edges with weights
    for (i = 0; i < noOfEdges; i++)
    {
        adj[get<0>(edges[i])].push_back({get<1>(edges[i]), get<2>(edges[i])});
    }
    return adj;
}
void DisplayAdjacencyList(vector<vector<pair<int, int>>> adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (auto j : adj[i])
        {
            cout << "-> " << j.first << "(" << j.second << ") ";
        }
        cout << "\n";
    }
}
int main()
{
    int V = 4;
    vector<tuple<int, int, int>> edges = {{0, 1, 5}, {1, 2, 7}, {2, 3, 5}, {1, 3, 6}, {3, 0, 2}};
    vector<vector<pair<int, int>>> adj(V);
    adj = initGraph(V, edges);
    DisplayAdjacencyList(adj);
}