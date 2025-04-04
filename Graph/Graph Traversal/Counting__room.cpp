// cses problem set:Graph Algorithm ->Counting Rooms
// problem source:: https://cses.fi/problemset/task/1192
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <utility>
using namespace std;
class Graph
{
    int m, n;
    char **mat;
    bool **isVisited;

public:
    Graph(int n, int m)
    {
        this->m = m;
        this->n = n;
        mat = new char *[n];
        isVisited = new bool *[n];
        for (int i = 0; i < n; i++)
        {
            mat[i] = new char[m];
            isVisited[i] = new bool[m];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                isVisited[i][j] = false;
            }
        }
    }
    void takeInput()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void BFS(int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        isVisited[i][j] = true;
        while (!q.empty())
        {

            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (i + 1 < n && mat[i + 1][j] == '.' && !isVisited[i + 1][j])
            {

                isVisited[i + 1][j] = true;
                q.push({i + 1, j});
            }
            if (i - 1 >= 0 && mat[i - 1][j] == '.' && !isVisited[i - 1][j])
            {

                isVisited[i - 1][j] = true;
                q.push({i - 1, j});
            }
            if (j + 1 < m && mat[i][j + 1] == '.' && !isVisited[i][j + 1])
            {

                isVisited[i][j + 1] = true;
                q.push({i, j + 1});
            }
            if (j - 1 >= 0 && mat[i][j - 1] == '.' && !isVisited[i][j - 1])
            {

                isVisited[i][j - 1] = true;
                q.push({i, j - 1});
            }
        }
    }
    int CountConnecteds()
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == '.' && isVisited[i][j] == false)
                {
                    BFS(i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
    int m, n;
    cin >> n >> m;
    Graph G(n, m);
    G.takeInput();
    cout << G.CountConnecteds();
}