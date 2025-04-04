/*
    You are given a weighted DAG and a source vertex. Find the minimum distance from the source vertex to each other vertices

    Input:
    3 3 0
    0 1 2
    1 2 3
    0 2 4
    Output:
    0 (distance: 0): [ 0 ]
    1 (distance: 2): [ 0 1 ]
    2 (distance: 4): [ 0 2 ]

    Input:Cormen 22.3
    5 10 0
    0 1 10
    0 3 5
    1 2 1
    1 3 2
    2 4 4
    3 1 3
    3 2 9
    3 4 2
    4 0 7
    4 2 6
    Output:
    0 (distance: 0): [ 0 ]
    1 (distance: 8): [ 0 3 1 ]
    2 (distance: 9): [ 0 3 1 2 ]
    3 (distance: 5): [ 0 3 ]
    4 (distance: 7): [ 0 3 4 ]
*/
#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF INT32_MAX
using namespace std;
class Solution
{
    vector<int> parent, estimate;
    void printPath(int s, int v)
    {
        if (s == v)
            cout << v << ' ';
        else if (parent[v] == -1)
            cout << "No path exists!";
        else
        {
            printPath(s, parent[v]);
            cout << v << ' ';
        }
    }

public:
    void Dijkstra(vector<vector<pii>> &graph, int s)
    {
        int V = graph.size();
        // Initialize single source
        parent.resize(V, -1);
        estimate.resize(V, INF);
        estimate[s] = 0;
        // create priority queue and a tracker of the vertices of which the shortest path have been determined
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        minHeap.push({0, s});
        while (!minHeap.empty())
        {
            int u = minHeap.top().second;
            minHeap.pop();

            for (pii x : graph[u])
            {
                int v = x.first;
                int w = x.second;
                if (estimate[v] > estimate[u] + w)
                {
                    estimate[v] = estimate[u] + w;
                    parent[v] = u;
                    minHeap.push({estimate[v], v});
                }
            }
        }
    }
    void printSSSP(int V, int s)
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " (distance: ";
            if (estimate[i] == INF)
            {
                cout << "INF";
            }
            else
            {
                cout << estimate[i];
            }
            cout << "): [ ";
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
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    Solution sol;
    sol.Dijkstra(graph, s);
    sol.printSSSP(V, s);
}