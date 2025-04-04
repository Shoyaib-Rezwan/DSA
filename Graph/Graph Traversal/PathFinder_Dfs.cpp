// Find if there exists a path from a vertex to another vertex. If exists then print the path along with it length.
// source F:\shoyaib\BUET\Level1 Term2\Level1 Term2 Mehmud Azad Vaia\CSE 106\CSE-106\Offline\2105014_graph_offline\t2.cpp
#include <iostream>
#include <list>
#include <vector>
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
    bool pathDFS(int start, int target, vector<int> &path)
    {
        visited[start] = true;
        if (start == target)
        {
            path.push_back(start);
            return true;
        }
        else
        {
            for (int x : adj[start])
            {
                if (!visited[x])
                {
                    if (pathDFS(x, target, path))
                    {
                        path.push_back(start); // we are pushing start instead of x because if we don't do that then start node won't be inserted inside the path
                        return true;
                    }
                }
            }
        }

        return false;
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
    g.displayList();
    vector<int> path;
    if (g.pathDFS(0, 3, path))
    {
        cout << path.size() - 1 << endl; // printing the size of path excluding the starting node
        for (int i = 0; i < path.size(); i++)
        {
            cout << path.at(path.size() - 1 - i) << "\t"; // look cerefully at the pathDFS function then you can see that path is stored in reverse order
        }
    }
    else
    {
        cout << "There exists no path.";
    }
}