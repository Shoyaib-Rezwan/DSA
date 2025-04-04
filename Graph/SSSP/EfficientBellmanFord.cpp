// You are given a weighted dag. It may contain negative edges as well. Write an efficient Bellman-Ford algo that solves the problem using only one pass.
/*
Input:
3 3 0
0 1 2
1 2 3
0 2 4
Output:
0 (distance 0): [ 0 ]
1 (distance 2): [ 0 1 ]
2 (distance 4): [ 0 2 ]

Input:Cormen 22.1
5 10 0
0 1 6
1 2 5
2 1 -2
0 3 7
1 3 8
3 4 9
4 2 7
3 2 -3
1 4 -4
4 0 2
Output:
0 (distance 0): [ 0 ]
1 (distance 2): [ 0 3 2 1 ]
2 (distance 4): [ 0 3 2 ]
3 (distance 7): [ 0 3 ]
4 (distance -2): [ 0 3 2 1 4 ]

Input:
5 4 0
0 1 2
0 3 4
1 3 3
2 4 8
Output:
0 (distance 0): [ 0 ]
1 (distance 2): [ 0 1 ]
2 (distance 2147483647): [ No path exists]
3 (distance 4): [ 0 3 ]
4 (distance 2147483647): [ No path exists]

Input: Cormen 22.2
6 10 1
0 1 5
0 2 3
1 2 2
1 3 6
2 3 7
2 4 4
2 5 2
3 4 -1
3 5 1
4 5 -2

Output:
0 (distance 2147483647): [ No path exists]
1 (distance 0): [ 1 ]
2 (distance 2): [ 1 2 ]
3 (distance 6): [ 1 3 ]
4 (distance 5): [ 1 3 4 ]
5 (distance 3): [ 1 3 4 5 ]
*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX
#define pii pair<int, int>
struct Edge
{
    int u, v, w;
};
class Solution
{
public:
    vector<int> parent, estimate;
    stack<int> vertexOrder;
    vector<bool> visited;
    void DFS(vector<vector<pii>> &graph, int v)
    {
        visited[v] = true;
        for (pii x : graph[v])
        {
            if (!visited[x.first])
                DFS(graph, x.first);
        }
        vertexOrder.push(v);
    }
    void BellmanFord(vector<vector<pii>> &graph, int s)
    {
        // Initialize Single Source
        int V = graph.size();
        parent.resize(V, -1);
        estimate.resize(V, INF);
        estimate[s] = 0;
        // Topologically sort the vertices
        visited.resize(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                DFS(graph, i);
        }
        // Relax all the edges based on the ordering of the topological sorted vertices
        while (!vertexOrder.empty())
        {
            int u = vertexOrder.top();
            vertexOrder.pop();
            for (pii x : graph[u])
            {
                int v = x.first, w = x.second;
                if (estimate[u] != INF && estimate[v] > estimate[u] + w)
                {
                    estimate[v] = estimate[u] + w;
                    parent[v] = u;
                }
            }
        }
    }
    void printPath(int s, int v)
    {
        if (s == v)
        {
            cout << v << ' ';
        }
        else if (parent[v] == -1)
        {
            cout << "No path exists";
        }
        else
        {
            printPath(s, parent[v]);
            cout << v << ' ';
        }
    }
    void printSSSP(int V, int s)
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " (distance " << estimate[i] << "): " << "[ ";
            printPath(s, i);
            cout << "]\n";
        }
    }
};
int main()
{
    int V, E, s;
    cin >> V >> E >> s;
    vector<vector<pii>> graph(V);
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    Solution sol;
    sol.BellmanFord(graph, s);
    sol.printSSSP(V, s);
}