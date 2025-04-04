// https://codeforces.com/problemset/problem/1144/F
// example of bipartiteness checking
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    vector<int> *adj;
    vector<bool> isVisited;
    int V, E;
    vector<char> colors;

public:
    Graph(int V, int E)
    {
        this->E = E;
        this->V = V;
        adj = new vector<int>[V + 1];
        isVisited.resize(V + 1, false);
        colors.resize(V + 1, 'N');
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isBipartite()
    {
        isVisited[1] = true;
        queue<int> q;
        q.push(1);
        colors[1] = 'R';
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int parentColor = colors[x];
            int childColor = (parentColor == 'G') ? 'R' : 'G';
            for (int y : adj[x])
            {
                if (!isVisited[y])
                {
                    isVisited[y] = true;
                    colors[y] = childColor;
                    q.push(y);
                }
                else if (colors[y] == parentColor)
                {
                    return false;
                }
            }
        }
        return true;
    }
    void printString(vector<pair<int, int>> &edges)
    {
        for (pair<int, int> p : edges)
        {
            if (colors[p.first] == 'R')
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
    }
};
int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> edges;
    Graph g(V, E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
        edges.push_back(make_pair(u, v));
    }
    if (g.isBipartite())
    {
        cout << "YES\n";
        g.printString(edges);
    }
    else
    {
        cout << "NO";
    }
}