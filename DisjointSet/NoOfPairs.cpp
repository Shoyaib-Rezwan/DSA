/*
The director of your college is planning to send 2 people to the ICPC regionals. He wants them to be from different branches. You will be given a list of pairs of student ids. Each pair is made of students from the same branch. Determine how many pairs of students from different branches they can choose from.

Example 1:
Input:
N=5
P=3
pairs[]={{0,1},
         {2,3},
         {0,4}}
Output:
6
Explanation:
Their are total five studets 0,1,2,3,4.
Students [0,1,4] are from same bracnh while
[2,3] are from a different one.So we can choose
different pairs like: [0,2],[0,3],[1,2],[1,3],
[4,2],[4,3]

Example 2:
Input:
N=4
P=1
pairs[]={{0,2}}
Output:
5
Explanation:
[0,1],[0,3],[2,1],[2,3] and [1,3] are all possible
pairs because [0,2],[1] and [3] all belongs to
different branches.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)



Constraint:
1<=N<=105
1<=P<=104
0<=P[i][0],P[i][1]
*/
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
        if (rank[parentx] > rank[parenty])
            parent[y] = parentx;
        else
            parent[x] = parenty;
        if (rank[parentx] == rank[parenty])
            rank[parenty]++;
    }
};
int findNoOfPairs(int N, vector<pair<int, int>> &pairs)
{
    DisjointSet obj(N);
    for (pair<int, int> x : pairs)
    {
        if (obj.findSet(x.first) != obj.findSet(x.second))
        {
            obj.unionSet(x.first, x.second);
        }
    }
    // at first assume there are intotal N diffrent branches and each student belongs to a separate branch
    vector<int> branches(N, 0);
    for (int i = 0; i < N; i++)
    {
        branches[obj.findSet(i)]++; // this calculates how many students are there in each separate banch
    }
    int pairCount = (N * (N - 1)) / 2; // if there are N students then we can form in total of NC2 different pairs
    for (int i = 0; i < N; i++)
    {
        pairCount -= (branches[i] * (branches[i] - 1)) / 2;
        // if i-th branch have branch[i] students then total pairs that can be formed using this students are branch[i]C2;
    }
    return pairCount;
}
using namespace std;
int main()
{
    int N, P;
    cin >> N >> P;
    vector<pair<int, int>> pairs(P);
    for (int i = 0; i < P; i++)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }
    cout << findNoOfPairs(N, pairs);
}