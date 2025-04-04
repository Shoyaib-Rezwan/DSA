#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<int> path;
void DFS(list<int> *graph, int start, vector<int> &process)
{
    process[start] = 1;
    path.push_back(start);
    for (int x : graph[start])
    {
        if (process[x] == 1)
            throw out_of_range("There exsists a cycle");
        else if (process[x] == 0)
        {
            DFS(graph, x, process);
        }
    }
}
list<int> enlist(vector<int> &process, list<int> &lst)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
    {
        int x = *(path.end() - 1);
        path.pop_back();
        lst.push_front(x);
        process[x] = 2;
    }
    return lst;
}
list<int> TraverseAll(list<int> *graph, int V, vector<int> &process)
{
    list<int> lst;
    for (int i = 0; i < V; i++)
    {
        if (process[i] == 0)
        {
            DFS(graph, i, process);
            lst = enlist(process, lst);
                }
    }
    return lst;
}
int main()
{
    int V, edges;
    cin >> V >> edges;
    list<int> *graph = new list<int>[V];
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> process(V, 0);
    list<int> lst = TraverseAll(graph, V, process);
    for (int x : lst)
    {
        cout << x << '\t';
    }
    cout << "\n";
}