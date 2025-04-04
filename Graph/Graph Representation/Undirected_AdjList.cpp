#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V); // intializing adjacency list
    int noOfEdges = edges.size(), i;
    for (i = 0; i < noOfEdges; i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    return adj;
}
void DisplayList(vector<vector<int>> adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (auto j : adj[i])
        {
            cout << "-> " << j << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1},
                                    {1, 0},
                                    {0, 2},
                                    {2, 0},
                                    {0, 3},
                                    {3, 0},
                                    {2, 3},
                                    {3, 2},
                                    {1, 4},
                                    {4, 1},
                                    {4, 3},
                                    {3, 4},
                                    {1, 3},
                                    {3, 1}};
    vector<vector<int>> adj(V);
    adj = initGraph(V, edges);
    DisplayList(adj);
}