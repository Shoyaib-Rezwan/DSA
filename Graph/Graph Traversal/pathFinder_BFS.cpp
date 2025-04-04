// Find if there exists a path from a vertex to another vertex. If exists then print the path along with it length.
// source F:\shoyaib\BUET\Level1 Term2\Level1 Term2 Mehmud Azad Vaia\CSE 106\CSE-106\Offline\2105014_graph_offline\t1.cpp
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;
    bool *visited;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
    }
    void addDirectedEdge(int u, int v) // u->v
    {
        adj[u].push_back(v);
    }
    void addUndirectedEdge(int u, int v) // u-v
    {
        adj[u].push_back(v); // u->v
        adj[v].push_back(u); // v->u
    }
    void displayList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "-> ";
            for (int x : adj[i])
            {
                cout << x << '\t';
            }
            cout << '\n';
        }
    }
    bool pathBFS(int start, int target, vector<int> &path)
    {
        vector<int> parent(V, -1); // this will track the parent node of each nodes(initially its all -1)
        visited[start] = true;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            start = q.front();
            q.pop();
            for (int x : adj[start])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    q.push(x);
                    parent[x] = start;
                }
            }
        }
        if (parent[target] == -1) // if target doesn't have any parent then return false
        {
            return false;
        }
        else
        {
            int current = target;
            while (current != -1)
            {
                path.push_back(current);
                current = parent[current];
            }
            reverse(path.begin(), path.end());
            return true;
        }
    }
};
int main()
{
    Graph g(5);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 4);
    g.addDirectedEdge(4, 0);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 3);
    g.displayList();
    vector<int> path;
    if (g.pathBFS(0, 4, path))
    {
        cout << path.size() - 1 << endl; // printing the size of path excluding the starting node
        for (int i = 0; i < path.size(); i++)
        {
            cout << path.at(i) << "\t";
        }
    }
    else
    {
        cout << "There exists no path.";
    }
}