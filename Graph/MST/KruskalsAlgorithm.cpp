// you are given a weighted, connected, undirected graph. Find the minimum spanning tree of it. That is return a new adjoint list of the tree. As well as the total weight of the MST.
// solve this problem using kruskal's algorithm
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
class DisjointSet
{
    int *parent;
    int *rank;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findSet(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findSet(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y)
    {
        int parentx = parent[x], parenty = parent[y];
        if (rank[parentx] > rank[parenty])
            parent[y] = parentx;
        else
            parent[x] = parenty;
        if (rank[parentx] == rank[parenty])
            rank[parenty]++;
    }
};
// will return minimum cost and an adjoint list
pair<int, vector<vector<int>>> MSTKruskal(int V, vector<pair<int, pair<int, int>>> &edges)
{
    int minCost = 0;
    vector<vector<int>> adjList(V);
    DisjointSet dsu(V);
    sort(edges.begin(), edges.end());
    for (pair<int, pair<int, int>> x : edges)
    {
        int w = x.first, u = x.second.first, v = x.second.second;
        if (dsu.findSet(u) != dsu.findSet(v))
        {
            dsu.unionSet(u, v);
            minCost += w;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    return {minCost, adjList};
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, pair<int, int>>> edges(E); // edges stores {weight,u,v}
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].first = w;
        edges[i].second.first = u;
        edges[i].second.second = v;
    }
    pair<int, vector<vector<int>>> result = MSTKruskal(V, edges);
    cout << "Minimum cost: " << result.first << "\nThe adjoint list of the tree: \n";
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int x : result.second[i])
        {
            cout << " ->" << x << " ";
        }
        cout << '\n';
    }
}
