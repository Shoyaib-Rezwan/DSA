// ques:: suppose you have an adjacency matrix of a weighted directed graph.You have to convert it to a adjacency list representation
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<vector<pair<int, int>>> conversion(vector<vector<int>> mat)
{
    int V = mat.size();
    vector<vector<pair<int, int>>> adj(V);
    // traverse the matrix and fill up the list
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j])
            {
                adj[i].push_back({j, mat[i][j]});
            }
        }
    }
    return adj;
}
void displayList(vector<vector<pair<int, int>>> adj)
{
    int V = adj.size();
    for (int i = 0; i < V; i++)
    {
        cout << i << " ";
        for (auto &&j : adj[i])
        {
            cout << "-> " << j.first << "(" << j.second << ") ";
        }
        cout << "\n";
    }
}
int main()
{
    vector<vector<int>> mat = {{0, 5, 0, 0}, {0, 0, 7, 5}, {0, 0, 0, 5}, {2, 0, 0, 0}};
    displayList(conversion(mat));
}