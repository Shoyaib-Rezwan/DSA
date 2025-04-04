// source anotti laaksonen
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
vector<list<int>> initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<list<int>> adj(V);
    for (auto &&i : edges)
    {
        adj[i.first].push_back(i.second);
    }
    return adj;
}
void displayList(vector<list<int>> adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << "-> ";
        for (auto &&i : adj[i])
        {
            cout << i << '\t';
        }
        cout << "\n";
    }
}
void BFS(vector<list<int>> adj, int startNode)
{
    vector<bool> visited(adj.size()); // initializing the visited vector to false and its size is same as the no. of nodes
    visited[startNode] = true;
    queue<int> q;
    q.push(startNode);
    int n;
    while (!q.empty())
    {
        n = q.front();
        q.pop();
        cout << n << " ";
        for (auto &&i : adj[n])
        {
            if (visited[i])
                continue;
            else
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
int main()
{
    int V = 6;
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 1}, {2, 5}, {3, 0}, {4, 1}, {4, 5}, {5, 2}, {5, 4}};
    vector<list<int>> adj = initGraph(V, edges);
    displayList(adj);
    BFS(adj, 0);
}