/*
There are N courses numbered from 1 to N. Some courses have prerequisite requirements,
meaning you must complete certain courses before enrolling in them. These prerequisites are
represented as directed edges, where an edge from course A to course B indicates that course
A must be completed before course B.
You will receive multiple queries. Each query provides a specific course, and your task is to
determine the number of prerequisite courses that must be completed before enrolling in that
course.

    Input::

The first line contains two integers N and M, the number of courses and the number of
prerequisite relationships.
● The next M lines each contain two integers A and B, meaning that course A is a
prerequisite for course B.
● The following line contains an integer Q, the number of queries.
● The next Q lines each contain a single integer C, representing a course for which you
need to determine the prerequisite count.

    Output::

For each query, print a single integer, representing the number of prerequisite courses required
for the given course.

Sample input:
5 5
1 2
1 3
3 4
4 5
2 5
2
5
4

Output:
4
2
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(vector<vector<int>> &adj, int start, vector<bool> &isVisited, vector<int> &prerequisits)
{
    isVisited[start] = true;
    for (int x : adj[start])
    {
        if (!isVisited[x])
        {
            prerequisits[x]++;
            DFS(adj, x, isVisited, prerequisits);
        }
    }
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
    vector<int> prerequisits(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    for (int i = 1; i < n + 1; i++)
    {
        DFS(adj, i, isVisited, prerequisits);
        for (int i = 0; i < n + 1; i++)
        {
            isVisited[i] = false;
        }
    }
    int query;
    cin >> query;
    while (query--)
    {
        int q;
        cin >> q;
        cout << prerequisits[q] << '\n';
    }
}