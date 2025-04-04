// you are given a weighted, connected, undirected graph. Find the minimum spanning tree of it. That is return a new adjoint list of the tree. As well as the total weight of the MST.
// solve this problem using Prim's algorithm
/*
input:
6 9
3 0 1
3 1 20
0 1 2
1 4 3
0 4 10
1 2 4
4 2 30
4 5 20
5 2 5
output:
15
*/
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define INF INT32_MAX
pair<int, vector<vector<int>>> MSTPrim(vector<vector<pii>> &graph)
{
    int V = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq; // a min heap to store {key,vertex}
    vector<bool> inMST(V, false);                      // tracks which vertices are in the MST
    vector<int> parent(V, -1), key(V, INF);            // Initialize parent and key for each vertices
    key[0] = 0;                                        // we are starting building MST from the 0th node
    pq.push({0, 0});
    while (!pq.empty())
    {
        int v = pq.top().second; // just pop the vertex
        pq.pop();
        // if v is already in the mst then skip it
        if (inMST[v])
            continue;
        inMST[v] = true;
        // traverse v's adjacent list
        for (pii x : graph[v])
        {
            int u = x.first, w = x.second; // terminal vertex and weight of the edge
            // First check whether u has already been inside the MST
            // if the key of u is greater than the current edge's weight take the following actions...
            if (!inMST[u] && key[u] > w)
            {
                parent[u] = v;
                key[u] = w;
                pq.push({w, u});
            }
        }
    }
    int cost = 0;
    vector<vector<int>> adj(V);
    for (int i = 0; i < V; i++)
    {
        cost += key[i];
        if (parent[i] == -1)
            continue;
        adj[i].push_back(parent[i]);
        adj[parent[i]].push_back(i);
    }
    return {cost, adj};
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pii>> graph(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    pair<int, vector<vector<int>>> result = MSTPrim(graph);
    cout << result.first << '\n';
    vector<vector<int>> adj = result.second;
    for (int i = 0; i < V; i++)
    {
        cout << i << "-> ";
        for (int x : adj[i])
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}