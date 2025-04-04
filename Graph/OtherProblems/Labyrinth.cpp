// https://cses.fi/problemset/task/1193

/*You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU  */
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
class Graph
{
    vector<char> *mat;
    vector<bool> *isVisited;
    int n, m;
    vector<pair<int, int>> *parents;
    int di[4] = {1, -1, 0, 0};
    int dj[4] = {0, 0, 1, -1};

private:
    // this funtion determines the position of(u2,v2) wrt (u1,v1)
    char findPosition(int u1, int v1, int u2, int v2) // we will not insert any iilegal points
    {
        if (v2 - v1 == -1)
            return 'L';
        else if (v2 - v1 == 1)
            return 'R';
        else if (u2 - u1 == -1)
            return 'U';
        else if (u2 - u1 == 1)
            return 'D';
    }
    // This BFS is similar to pathFinder function
    void BFS(int i, int j)
    {
        isVisited[i][j] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int newi = i + di[k], newj = j + dj[k];
                if (newi >= 0 && newi < n && newj >= 0 && newj < m && !isVisited[newi][newj])
                {
                    if (mat[newi][newj] == '.' || mat[newi][newj] == 'B')
                    {
                        isVisited[newi][newj] = true;
                        q.push(make_pair(newi, newj));
                        parents[newi][newj] = make_pair(i, j);
                    }
                }
            }
        }
    }

public:
    Graph(int n, int m)
    {
        this->n = n;
        this->m = m;
        mat = new vector<char>[n];
        isVisited = new vector<bool>[n];
        parents = new vector<pair<int, int>>[n];
        for (int i = 0; i < n; i++)
        {
            mat[i].resize(m);
            isVisited[i].resize(m, false);
            parents[i].resize(m, make_pair(-1, -1));
        }
    }
    void input()
    {
        fflush(stdin);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
            fflush(stdin);
        }
    }
    void showPath()
    {
        int Bi, Bj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'A')
                    BFS(i, j);
                if (mat[i][j] == 'B')
                {
                    Bi = i;
                    Bj = j;
                }
            }
        }
        if (parents[Bi][Bj].first == -1)
        {
            cout << "NO";
            return;
        }
        cout << "YES\n";
        int tempi, tempj, count = 0;
        string path;
        // loop through until you reached a point which doesn't have any parents
        while (parents[Bi][Bj].first != -1)
        {
            count++;
            tempi = parents[Bi][Bj].first;
            tempj = parents[Bi][Bj].second;
            path += findPosition(Bi, Bj, tempi, tempj);
            Bi = tempi;
            Bj = tempj;
        }
        cout << count << '\n';
        // The path we got contains a path from B to A so we have to find the correct path
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.length(); i++)
        {
            switch (path[i])
            {
            case 'L':
                cout << 'R';
                break;
            case 'R':
                cout << 'L';
                break;
            case 'U':
                cout << 'D';
                break;
            case 'D':
                cout << 'U';
                break;
            }
        }
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    g.input();
    g.showPath();
}