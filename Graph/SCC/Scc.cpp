#include <iostream>
#include <vector>
#include <list>
using namespace std;
list<int> lst;
vector<int> path;
bool *isVisited;
void DFS(list<int> *adj, int V)
{
    isVisited[V] = true;
    path.push_back(V);
    for (int x : adj[V])
    {
        if (!isVisited[x])
        {
            DFS(adj, x);
        }
    }
}
void Traverse(list<int> *adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            DFS(adj, i);
            int size = path.size();
            while (size)
            {
                lst.push_front(path[--size]);
                path.pop_back();
            }
        }
    }
}
void findSCC(list<int> *adjrev, int V)
{
    for (int i = 0; i < V; i++)
    {
        isVisited[i] = false;
    }
    for (int x : lst)
    {
        if (!isVisited[x])
        {
            DFS(adjrev, x);
            for (int y : path)
            {
                cout << y << "\t";
            }
            path.clear();
            cout << "\n";
        }
    }
}
int main()
{
    int V, edge, u, v;
    cin >> V >> edge;
    isVisited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        isVisited[i] = false;
    }

    list<int> *adj = new list<int>[V];
    list<int> *adjrev = new list<int>[V];
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adjrev[v].push_back(u);
    }
    Traverse(adj, V);
    findSCC(adjrev, V);
}