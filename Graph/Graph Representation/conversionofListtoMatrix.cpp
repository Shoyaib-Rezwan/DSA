// ques:: Suppose you have an adjacency list of unweighted graph. You have to convert it to adjacency matrix representation
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
using namespace std;
vector<vector<int>> Conversion(vector<vector<int>> adj)
{
    int V = adj.size();
    // initialize the matrix
    vector<vector<int>> mat(V, vector<int>(V));
    // traverse the list and fill up the matrix
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            mat[i][j] = 1;
        }
    }
    return mat;
}
void displayAdjMatrix(vector<vector<int>> mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    vector<vector<int>> adj = {{1}, {2, 3}, {3}, {0}};
    adj = Conversion(adj);
    displayAdjMatrix(adj);
}