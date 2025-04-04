/*
In a software project, there are N modules, numbered from 1 to N . Certain modules depend on
the completion of others before they can begin, represented by directed edges. An edge from
module A to module B means module A must be compiled before module B starts compiling.
Your task is to determine if there is a circular dependency (cycle) in the project dependencies. A
cycle would indicate a deadlock, making it impossible to complete all modules.

Input::
● The first line contains two integers N and M, the number of modules and the number of
dependencies.
● The next M lines each contain two integers A and B, indicating that module A must be
compiled before module B.

Output::
Print "Yes" if there is a cycle (circular dependency) in the project, and "No" otherwise.

Sample Input:                     Output:
4 4                               YES
1 2
2 3
3 4
4 2

Sample Output:                    Output:
5 3                               No
1 2
2 3
4 5

*/
// solve: It's obvious that we have to find that if there is a cycle or not in our graph. To do so we will at first color all the nodes WHITE. Whenever an unvisited node is encountered we will make that GRAY an whwnever all the decendents of a node is visited we will simply make the node BLACK. We can prove that in DFS whwenver we encounter an edge from GRAY to GRAY that will ensure that the graph contains a cycle

#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adj, int start, bool &isCyclic, vector<char> &colors)
{
    colors[start] = 'G';
    for (int x : adj[start])
    {
        if (colors[x] == 'W')
        {
            DFS(adj, x, isCyclic, colors);
        }
        else if (colors[x] == 'G')
        {
            isCyclic = true;
        }
    }
    colors[start] = 'B';
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<char> colors(n + 1, 'W');
    bool isCyclic = false;
    for (int i = 1; i < n + 1; i++)
    {
        if (colors[i] == 'W')
        {
            DFS(adj, i, isCyclic, colors);
            if (isCyclic)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}