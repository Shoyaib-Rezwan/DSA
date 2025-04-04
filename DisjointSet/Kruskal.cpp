// suppose you are given an weighted connected undirected graph. Find the minimum spanning tree. You have to return the cost of the minimum spanning tree.
/*
Input:
vertex: 4
Edges(u,v,weight):
6
1 2 10
0 1 1
1 3 2
0 3 10
3 2 3
0 2 5
Output:
6
**************************************************************
Input:
vertex: 9
Edges(u,v,weight):
14
2 3 7
8 2 2
3 4 9
6 5 2
7 6 1
0 1 4
1 2 8
5 4 10
2 5 4
8 6 6
3 5 14
7 8 7
1 7 11
0 7 8
Output:
37
*/
#include <bits/stdc++.h>
using namespace std;
// a temporary struct for holding each edge
struct Edge
{
    int u, v, w;
};
// comparator for sorting Edge array
struct comparator
{
    bool operator()(Edge &a, Edge &b)
    {
        return a.w < b.w;
    }
};
// data structure for disjoint set
class Disjoint_Set
{
    int *parent;
    int *rank;
    int n; // number of elements

public:
    Disjoint_Set(int n)
    {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // set each elements parent to itself
            rank[i] = 0;   // initialize rank with 0;
        }
    }
    // FindSet with path compression!!!
    int findSet(int x)
    {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }
    // Union by rank
    void unionSet(int x, int y)
    {
        int parentx = findSet(x);
        int parenty = findSet(y);
        if (rank[parentx] > rank[parenty])
            parent[parenty] = parentx;
        else
            parent[parentx] = parenty;
        if (rank[parentx] == rank[parenty])
            rank[parenty]++;
    }
};
int minimumSpanningTreeWeight(int V, int E, Edge *edges)
{
    int cost = 0;
    // sort the edges in monotonically increasing order by the weights
    sort(edges, edges + E, comparator());
    Disjoint_Set obj(V);
    for (int i = 0; i < E; i++)
    {
        if (obj.findSet(edges[i].u) != obj.findSet(edges[i].v))
        {
            cost += edges[i].w;
            obj.unionSet(edges[i].u, edges[i].v);
        }
    }
    return cost;
}
int main()
{
    int V, E;
    cout << "Vertex: ";
    cin >> V;
    cout << "Edges(u,v,weight): ";
    cin >> E;
    Edge *edges = new Edge[E];
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].w >> edges[i].u >> edges[i].v;
    }
    cout << minimumSpanningTreeWeight(V, E, edges);
}