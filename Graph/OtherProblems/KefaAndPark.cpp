// https://codeforces.com/problemset/problem/580/C
#include <bits/stdc++.h>
using namespace std;
// we will solve this problem by considering the tree as graph.
// here tree contains directed edges from each parent to its direct children
class Graph
{
public:
    int n, m;
    vector<int> *adj;
    vector<bool> isVisited;
    vector<int> catNodes;
    vector<bool> isLeaf;

    int count;

public:
    Graph(int n, int m)
    {
        this->m = m;
        this->n = n;
        adj = new vector<int>[n + 1];
        isVisited.resize(n + 1, false);
        catNodes.resize(n + 1);
        isLeaf.resize(n + 1, false);
        count = 0;
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // this function finds the leaves of a undirected graph
    void findLeaves(int currentNode, int parent)
    {
        static vector<bool> tempVisited(n + 1, false);
        tempVisited[currentNode] = true;
        if (adj[currentNode].size() == 1 && adj[currentNode][0] == parent)
            isLeaf[currentNode] = true;
        for (int x : adj[currentNode])
        {
            if (!tempVisited[x])
            {
                findLeaves(x, currentNode);
            }
        }
    }
    void addCats(int i, int u)
    {
        catNodes[i] = u;
    }
    void DFS(int currentm, int i)
    {
        isVisited[i] = true;
        if (catNodes[i])
            currentm++;
        // if it's not consecutive then clear currentm
        else
            currentm = 0;
        for (int x : adj[i])
        {
            // you can't have more than m consecutive cats in your path
            int nextm = (catNodes[x]) ? currentm + 1 : currentm;
            if (nextm <= m && !isVisited[x])
            {
                DFS(currentm, x);
            }
        }
        if (catNodes[i])
            currentm--;
        if (isLeaf[i])
            count++;
    }
};
int main()
{
    int V, M;
    cin >> V >> M;
    Graph g(V, M);
    for (int i = 1; i <= V; i++)
    {
        int u;
        cin >> u;
        g.addCats(i, u);
    }
    for (int i = 1; i <= V - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.findLeaves(1, 0);
    // for (int i = 0; i < V; i++)
    // {
    //     cout << g.isLeaf[i];
    // }

    g.DFS(0, 1);
    cout << g.count;
}