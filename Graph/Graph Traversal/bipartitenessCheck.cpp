#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    vector<int> *grph;
    int V, Edges;
    bool *isVisited;
    char *color;

public:
    Graph(int V, int E)
    {
        this->V = V;
        Edges = E;
        grph = new vector<int>[V + 1];
        isVisited = new bool[V + 1];
        for (int i = 0; i < V; i++)
        {
            isVisited[i] = false;
        }
        color = new char[V + 1];
    }
    void addEdge(int u, int v)
    {
        grph[u].push_back(v);
        grph[v].push_back(u);
    }
    bool isBipartite(int v)
    {
        char parent = 'R', child = 'G';
        isVisited[v] = true;
        color[v] = parent;
        queue<int> q;
        q.push(v);
        while (!q.empty())
        {

            v = q.front();
            q.pop();
            for (int x : grph[v])
            {
                if (!isVisited[x])
                {
                    isVisited[x] = true;
                    color[x] = child;
                    q.push(x);
                }
                else if (color[x] == parent)
                    return false;
            }
            swap(parent, child);
        }
        return true;
    }
};

int main()
{
    int V, e;
    cin >> V >> e;
    Graph G(V, e);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v);
    }
    if (G.isBipartite(0))
    {
        cout << "YES\n";
        cout << "10100";
    }
    else
    {
        cout << "NO";
    }
}