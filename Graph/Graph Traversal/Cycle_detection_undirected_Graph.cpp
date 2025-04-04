// the main concept of this algorithm is that in an connected component of the graph, the graph is either a tree or it is a cyclic graph.
//  if the connected component has n edges and more than n-1 edges then the connected component must contain a cycle
#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    vector<int> *adj;
    int V, E;
    bool *isVisted;

private:
    bool isCyclicComponent(int start);
    void DFS(int start, vector<int> &path);

public:
    Graph(int V, int E);
    void addUnEdge(int u, int v);
    bool isCyclic();
};
Graph::Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    adj = new vector<int>[V];
    isVisted = new bool[V];
    for (int i = 0; i < V; i++)
    {
        isVisted[i] = false;
    }
}
void Graph::addUnEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool Graph::isCyclic()
{
    for (int i = 0; i < V; i++)
    {
        if (!isVisted[i] && isCyclicComponent(i))
            return true;
    }
    return false;
}
bool Graph::isCyclicComponent(int start)
{
    vector<int> path;
    DFS(start, path);
    int edgeCount = 0, vertexCount = path.size();
    for (int x : path)
    {
        for (int y : adj[x])
        {
            edgeCount++;
        }
    }
    edgeCount /= 2;
    if (edgeCount == vertexCount - 1)
        return false;
    return true;
}
void Graph::DFS(int start, vector<int> &path)
{
    isVisted[start] = true;
    path.push_back(start);
    for (int x : adj[start])
    {
        if (!isVisted[x])
            DFS(x, path);
    }
}
int main()
{
    int V, E;
    cin >> V >> E;
    Graph g(V, E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addUnEdge(u, v);
    }
    cout << g.isCyclic();
}