/*January 2024, CSE 106
Online on Greedy Algorithms
Time: 40 Minutes
You are given an array of points representing integer coordinates of some points on a 2D plane.
The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance
between them |𝑥 , where denotes the absolute value of val.
𝑖 − 𝑥
𝑗
| + |𝑦
𝑖 − 𝑦
𝑗
| |𝑣𝑎𝑙|
Return the minimum total cost to connect all the points. All points are connected if there is at
least one simple path between any two points.
Input/Output:
The first input line will contain an integer n that indicates the number of given points. The
following n lines contain the x and y coordinates of the corresponding points.
The output should be a single line containing the minimum total cost to connect all the points.
Sample Input Sample Output
5
0 0
2 2
3 10
5 2
7 0
20
3
3 12
-2 5
-4 1
18
Explanation: In the first sample input, we can connect [0, 0] with [2, 2] with cost 4. Similarly, we
connect the pairs of points ([2,2], [3, 10]), ([2,2], [5, 2]), and ([5,2], [7, 0]) with costs 9, 3, and 4
respectively. The total cost of connecting all the points is 20.
*/
// obviously this problem can be solved by using the concept of MST. The best method to use would be the Prim's algorithm but for consistency we will use Kruskal's algorithm for MST over here
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    int *parent;
    int *rank;
    int n;

public:
    DisjointSet(int n)
    {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findSet(int x)
    {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }
    void unionSet(int x, int y)
    {
        int parentx = findSet(x);
        int parenty = findSet(y);
        if (parentx == parenty)
            return;
        if (rank[parentx] > rank[parenty])
            parent[y] = x;
        else
            parent[x] = y;
        if (rank[parentx] == rank[parenty])
            rank[parenty]++;
    }
};
// function for finding Manhattan distance
int distance(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int findMinCost(vector<pair<int, int>> &points)
{
    // find all possible distance between two points
    vector<pair<int, pair<int, int>>> distances; //{distance,{u,v}}
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        {
            distances.push_back({distance(points[i], points[j]), {i, j}});
        }
    }
    // sort the distances in ascending order based on the 1st values of the pairs
    sort(distances.begin(), distances.end());
    DisjointSet dsu(points.size());
    int minCost = 0;
    for (pair<int, pair<int, int>> x : distances)
    {
        int cost = x.first, u = x.second.first, v = x.second.second;
        if (dsu.findSet(u) != dsu.findSet(v))
        {
            minCost += cost;
            dsu.unionSet(u, v);
        }
    }
    return minCost;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    cout << findMinCost(points);
}