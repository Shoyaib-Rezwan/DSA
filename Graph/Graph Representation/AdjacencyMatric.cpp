#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;
// here we will use a vector of vectors to represent a matrix
vector<vector<int>> initGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> mat(V, vector<int>(V)); // initializing a V*V matrix
    int noOfEdges = edges.size(), i;
    for (i = 0; i < noOfEdges; i++)
    {
        mat[edges[i].first][edges[i].second] = 1;
    }
    return mat;
}
void displayAdjMatrix(vector<vector<int>> mat)
{
    int V = mat.size();
    for (int i = 0; i < V; i++)
    {
        for (auto j : mat[i])
        {
            cout << setw(2) << j << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    int V = 5;
    vector<pair<int, int>> edges = {{0, 1}, {1, 0}, {0, 2}, {2, 0}, {0, 3}, {3, 0}, {1, 3}, {3, 1}, {1, 4}, {4, 1}, {2, 3}, {3, 2}, {3, 4}, {4, 3}};
    vector<vector<int>> mat = initGraph(V, edges);
    displayAdjMatrix(mat);
}