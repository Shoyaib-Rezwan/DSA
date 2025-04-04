#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;
vector<vector<int>> initGraph(int V, vector<tuple<int, int, int>> &edges)
{
    vector<vector<int>> mat(V, vector<int>(V));
    int noOfEdges = edges.size();
    for (int i = 0; i < noOfEdges; i++)
    {
        mat[get<0>(edges[i])][get<1>(edges[i])] = get<2>(edges[i]);
    }
    return mat;
}
void DispalyAdjMatrix(vector<vector<int>> mat)
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
    vector<tuple<int, int, int>> edges = {{0, 1, 10}, {1, 0, 10}, {0, 2, 60}, {2, 0, 60}, {0, 3, 70}, {3, 0, 70}, {1, 3, 30}, {3, 1, 30}, {1, 4, 20}, {4, 1, 20}, {2, 3, 50}, {3, 2, 50}, {3, 4, 40}, {4, 3, 40}};
    vector<vector<int>> mat = initGraph(V, edges);
    DispalyAdjMatrix(mat);
}