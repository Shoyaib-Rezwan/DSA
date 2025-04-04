/*Find all possible MST of a given graph.
Input
The first line contains two integers n and m — the number of the graph's vertices and edges,
correspondingly. Then follow m lines, each of them contains three integers — the description of the
graph's edges as "ai bi wi" where ai and bi are the numbers of vertices connected by the i-th edge,
wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or
multiple edges.
Output

Print All the edges for each possible MST.
Examples

Input Output
5 10
0 1 1
2 4 1
1 2 2
0 4 2
3 4 3
0 3 5
1 4 6
2 3 8
0 2 9
1 3 9

MSTs:
1 : [[0, 1, 1], [2, 4, 1], [1, 2, 2], [3, 4, 3]]
2 : [[0, 1, 1], [2, 4, 1], [0, 4, 2], [3, 4, 3]]


7 12
3 4 1
1 5 1
1 4 1
0 6 4
2 3 8
4 5 8
2 6 10
0 5 10
3 6 10
1 6 10
1 3 12
3 5 12

MSTs:
1 : [[3, 4, 1], [1, 5, 1], [1, 4, 1], [0, 6, 4], [2, 3, 8], [2, 6, 10]]
2 : [[3, 4, 1], [1, 5, 1], [1, 4, 1], [0, 6, 4], [2, 3, 8], [0, 5, 10]]
3 : [[3, 4, 1], [1, 5, 1], [1, 4, 1], [0, 6, 4], [2, 3, 8], [3, 6, 10]]
4 : [[3, 4, 1], [1, 5, 1], [1, 4, 1], [0, 6, 4], [2, 3, 8], [1, 6, 10]]*/
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define pii pair<int, int>
struct edge
{
    int u, v, w;
};
void findAllMST(vector<vector<int>> &parent, vector<int> &key, int V, int index, vector<vector<edge>> &allMST, vector<edge> &currentMST)
{
    if (index == V)
    {
        if (currentMST.size() == V - 1)
            allMST.push_back(currentMST);
        return;
    }
    for (int x : parent[index])
    {
        vector<edge> tempMST = currentMST;
        edge e;
        e.u = x;
        e.v = index;
        e.w = key[index];
        tempMST.push_back(e);
        findAllMST(parent, key, V, index + 1, allMST, tempMST);
    }
}
vector<vector<edge>> generateAllMST(vector<vector<pii>> &graph)
{
    int V = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(V, false);
    vector<int> key(V, INF);
    vector<vector<int>> parent(V);
    key[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int v = pq.top().second;
        pq.pop();
        if (inMST[v])
            continue;
        inMST[v] = true;
        for (pii x : graph[v])
        {
            int u = x.first, w = x.second;
            if (!inMST[u])
            {
                if (key[u] > w)
                {
                    parent[u].clear();
                    parent[u].push_back(v);
                    key[u] = w;
                    pq.push({w, u});
                }
                else if (key[u] == w)
                {
                    parent[u].push_back(v);
                }
            }
        }
    }
    vector<vector<edge>> allMST;
    vector<edge> currentMST;
    findAllMST(parent, key, V, 1, allMST, currentMST);
    return allMST;
}
int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pii>> graph(V);
    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<vector<edge>> allMST = generateAllMST(graph);
    int i = 1;
    for (vector<edge> mst : allMST)
    {
        cout << i << ":[ ";
        for (edge e : mst)
        {
            cout << "[" << e.u << " " << e.v << " " << e.w << "] ";
        }
        cout << "]\n";
        i++;
    }
}