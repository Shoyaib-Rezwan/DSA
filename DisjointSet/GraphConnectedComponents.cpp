#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ElementObject *> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ElementObject(i + 1);
    }
    int e;
    cin >> e;
    vector<pair<ElementObject *, ElementObject *>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({arr[u - 1], arr[v - 1]});
    }
    for (int i = 0; i < n; i++)
    {
        MakeSet(arr[i]);
    }
    for (int i = 0; i < e; i++)
    {
        ElementObject *u = edges[i].first;
        ElementObject *v = edges[i].second;
        if (FindSet(u) != FindSet(v))
            Union(u, v);
    }
    cout << "\n Enter 2 vertices:: ";
    int u, v;
    cin >> u >> v;
    if (FindSet(arr[u - 1]) == FindSet(arr[v - 1]))
        cout << "Is in same componet!";
    else
        cout << "Not in same component!";
}