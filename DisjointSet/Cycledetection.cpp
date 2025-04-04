// you are given a graph with its adjoint list represenation. Determine whether there is a cycle or not
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
        int parentx = findSet(x), parenty = findSet(y);
        if (rank[parentx] > rank[parenty])
        {
            parent[y] = parentx;
        }
        else
            parent[x] = parenty;
        if (rank[parentx] == rank[parenty])
            rank[parenty]++;
    }
};
bool isCyclic(int V, vector<pair<int, int>> &edges)
{
    DisjointSet obj(V);
    for (pair<int, int> x : edges)
    {
        if (obj.findSet(x.first) == obj.findSet(x.second))
            return true;
        else
            obj.unionSet(x.first, x.second);
    }
    return false;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    cout << isCyclic(V, edges);
}