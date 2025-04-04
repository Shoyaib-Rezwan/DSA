#include <bits/stdc++.h>
using namespace std;
void DFS_Using_Stack(vector<vector<int>> &adj, vector<bool> &isVisited, int start)
{
    stack<int> nodes;
    isVisited[start] = true;
    nodes.push(start);
    while (!nodes.empty())
    {
        int currentNode = nodes.top();
        nodes.pop();
        cout << currentNode << ' ';
        for (int x : adj[currentNode])
        {
            if (!isVisited[x])
            {
                isVisited[x] = true;
                nodes.push(x);
            }
        }
    }
    cout << '\n';
}
int main()
{
    int n, m; // vertices,edges
    cin >> n >> m;
    vector<vector<int>> adj(n + 1); // adj. list
    vector<bool> isVisited(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int u, v; //(u,v) directed edges
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            DFS_Using_Stack(adj, isVisited, i);
        }
    }
}