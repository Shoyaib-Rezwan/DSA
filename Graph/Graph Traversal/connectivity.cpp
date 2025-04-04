// suppose you have an adjacency list of a graph. Determine whether it is connected or not
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
bool isConnected(vector<vector<int>> adj)
{
    int V = adj.size(); // no. of vertices
    vector<bool> visited(V);
    int node = 0, i;
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while (q.empty() == false)
    {
        node = q.front();
        q.pop();
        // cout << node << " ";
        for (int j : adj[node])
        {
            if (visited[j])
                continue;
            else
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    for (i = 0; i < V; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
}
int main()
{
    vector<vector<int>> adj = {{2, 3}, {4}, {3}, {}, {}};
    cout << isConnected(adj);
}