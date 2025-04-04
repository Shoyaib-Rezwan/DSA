// https://codeforces.com/problemset/problem/1093/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// function for calculating (b^n) mod m
int modularExponentiation(int b, int n, int m)
{
    ll x = 1;
    ll power = b % m;
    for (int i = 0; i < 32; i++)
    {
        if ((n >> i) & 1)
            x = (power * x) % m;
        power = (power * power) % m;
    }
    return x;
}
class Graph
{
    int V, E;
    vector<int> *adj;
    vector<bool> isVisited;
    vector<char> color;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        adj = new vector<int>[V + 1];
        isVisited.resize(V + 1, false);
        color.resize(V + 1);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // this function returns all possible combination for a connected component of the graph
    int isBipartiteUtility(int i)
    {
        int red = 1, green = 0; // this will divide the bipartite graph into two halves
        isVisited[i] = true;
        color[i] = 'R';
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            i = q.front();
            q.pop();
            char parentColor = color[i];
            char childColor = (color[i] == 'R') ? 'G' : 'R';
            for (int x : adj[i])
            {
                if (!isVisited[x])
                {
                    isVisited[x] = true;
                    color[x] = childColor;
                    q.push(x);
                    if (color[x] == 'R')
                        red++;
                    else
                        green++;
                }
                else
                {
                    if (color[x] == parentColor)
                        return 0;
                }
            }
        }
        return (modularExponentiation(2, red, 998244353) + modularExponentiation(2, green, 998244353)) % 998244353; //(2^red+2^green) mod m;
    }
    int isBipartite()
    {
        ll result = 1;
        for (int i = 1; i <= V; i++)
        {
            if (!isVisited[i])
            {
                result = (result * isBipartiteUtility(i)) % 998244353;
            }
        }
        return result; // result is the product of all combinations of seperate connected components
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        Graph g(V, E);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        cout << g.isBipartite() << '\n';
    }
}