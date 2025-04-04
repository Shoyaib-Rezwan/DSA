// You are given a matrix grid where grid[i] is either a 0(representing water) or 1(representing land).

// An island is defined as a group of 1's connected horizontally
// or vertically.You may assume all four edges of the grid are surrounded by water.

// The area of an island is defined as the number of cells within the island.

// Return the maximum area of an island in grid.If no island exists,
// return 0.

// // Input: grid = [
//   [0,1,1,0,1],
//   [1,0,1,0,1],
//   [0,1,1,0,1],
//   [0,1,0,0,1]
// ]

// Output: 6
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int **mat;
    bool **isVisited;
    int row, col;
    int di[4], dj[4];

private:
    void DFS(int x, int y, int &length);

public:
    Graph(int V, int E);
    void input();
    int maxArea();
};
Graph::Graph(int row, int col)
{
    this->row = row;
    this->col = col;
    mat = new int *[row];
    isVisited = new bool *[row];
    for (int i = 0; i < row; i++)
    {
        mat[i] = new int[col];
        isVisited[i] = new bool[col];
        for (int j = 0; j < col; j++)
        {
            isVisited[i][j] = false;
        }
    }
    di[0] = 1;
    di[1] = -1;
    di[2] = 0;
    di[3] = 0;
    dj[0] = 0;
    dj[1] = 0;
    dj[2] = -1;
    dj[3] = 1;
}
void Graph::input()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
}
int Graph::maxArea()
{
    int maxA = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!isVisited[i][j] && mat[i][j] == 1)
            {
                DFS(i, j, maxA);
            }
        }
    }
    return maxA;
}
void Graph::DFS(int i, int j, int &length)
{
    static int currentLength = 0;
    isVisited[i][j] = true;
    currentLength++;
    for (int k = 0; k < 4; k++)
    {
        int newi = i + di[k], newj = j + dj[k];
        if (newi >= 0 && newi < row && newj >= 0 && newj < col)
        {
            if (!isVisited[newi][newj] && mat[newi][newj] == 1)
            {
                DFS(newi, newj, length);
            }
        }
    }
    length = max(length, currentLength);
    currentLength--;
}
int main()
{
    int row, col;
    cin >> row >> col;
    Graph g(row, col);
    g.input();
    cout << g.maxArea();
}