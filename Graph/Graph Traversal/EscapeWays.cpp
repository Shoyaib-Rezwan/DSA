/*
A prisoner is attempting to escape from a prison represented as an N*M grid. Each cell in the
grid can be one of the following:
● .: an empty cell the prisoner can move through
● #: an obstacle the prisoner cannot pass through
● S: the prisoner's starting position (there is only one starting point)
● E: an exit point (there can be multiple exits)
The prisoner can move up, down, left, or right to an adjacent cell, but cannot move diagonally or
pass through obstacles. Your task is to determine the number of distinct exit points the prisoner
can reach starting from S.

Input::
● The first line contains two integers N and M , the dimensions of the grid.
● The next N lines contain M characters each, representing the prison layout with cells as
described above.


Output
Print "Yes" if there is a cycle (circular dependency) in the project, and "No" otherwise.


Input               Output
5 5                 3
S....
.###E
.#..#
...E.
E.#..

Input               Output
6 6                 1
S.#..E
.#.##.
..#..#
.##..E
.#....
E.#.##
*/
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &mat, pair<int, int> start, int &escapeWays)
{
    int i = start.first, j = start.second;
    if (mat[i][j] == 'E')
        escapeWays++;
    mat[i][j] = '#';
    if (i + 1 < mat.size() && mat[i + 1][j] != '#')
    {
        DFS(mat, {i + 1, j}, escapeWays);
    }
    if (j + 1 < mat[0].size() && mat[i][j + 1] != '#')
    {
        DFS(mat, {i, j + 1}, escapeWays);
    }
    if (i - 1 >= 0 && mat[i - 1][j] != '#')
    {
        DFS(mat, {i - 1, j}, escapeWays);
    }
    if (j - 1 >= 0 && mat[i][j - 1] != '#')
    {
        DFS(mat, {i, j - 1}, escapeWays);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m));
    pair<int, int> startingPosition;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'S')
                startingPosition = {i, j};
        }
    }
    int escapeWays = 0;
    DFS(mat, startingPosition, escapeWays);
    cout << escapeWays;
}