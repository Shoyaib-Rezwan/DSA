// You are given a weighted directed, weights and a source vertex. Determine the shortest path distance from the source vertex along with their paths
// input: V E s//vertex, edge_no, source vertex
// after that there will be E lines in the format of u,v,w
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

Input:Cormen 22.1
8 11 0
0 1 3
0 5 2
0 3 5
1 2 -4
3 4 6
4 3 -3
5 6 3
6 5 -6
2 7 4
4 7 8
6 7 7
Output:
There exists a negative cycle

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
*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT32_MAX
struct Edge
{
    int u, v, w;
};
class Solution
{
public:
    vector<int> parent, estimate;
    bool bellmanFord(vector<Edge> &graph, int V, int s)
    {
        // initializing single source
        parent.resize(V, -1);
        estimate.resize(V, INF);
        estimate[s] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (Edge e : graph)
            {
                if (estimate[e.u] != INF && estimate[e.v] > estimate[e.u] + e.w)
                {
                    // relax(u,v,w)
                    estimate[e.v] = estimate[e.u] + e.w;
                    parent[e.v] = e.u;
                }
            }
        }
        // check for the presence of negative cycle
        for (Edge e : graph)
        {
            if (estimate[e.u] != INF && estimate[e.v] > estimate[e.u] + e.w)
            {
                return false;
            }
        }
        return true;
    }
    void printPath(int s, int v)
    {
        if (s == v)
        {
            cout << v << ' ';
            return;
        }
        if (parent[v] == -1)
        {
            cout << "No path exists";
            return;
        }
        printPath(s, parent[v]);
        cout << v << ' ';
    }
    void printSSSPs(int V, int s)
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
    vector<Edge> graph(E);
    for (int i = 0; i < E; i++)
    {
        cin >> graph[i].u >> graph[i].v >> graph[i].w;
    }
    Solution sol;
    if (sol.bellmanFord(graph, V, s) == false)
    {
        cout << "There exists a negative cycle\n";
    }
    else
    {
        sol.printSSSPs(V, s);
    }
}