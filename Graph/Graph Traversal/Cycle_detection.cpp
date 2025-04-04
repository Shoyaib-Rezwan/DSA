// ques:: suppose you have a directed graph. You have to find out if there exists a cycle in the graph or not source::https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// video:: https://youtu.be/joqmqvHC_Bo?list=PLqM7alHXFySEaZgcg7uRYJFBnYMLti-nh
// why do we need to maintain a recursion stack in cycle detection in a directed graph?
// draw the directed graph in your khata 0->1, 2->3, 3->4, 4->5, 5->1
// here the graph is disconnected and acyclic.In one connected component we will get dfs 1->2 and in other connected component we will get 2->3->4->5 after 5 it comes one which is visited alreadj. If we only rely on the visited nodes then after going from 5 to previously visited node we have to say that the graph is cyclic but that is not true
#include <iostream>
#include <list>
using namespace std;
class Graph
{
    int V;
    list<int> *adj; // array of list to contain the graph
public:
    Graph(int V);                                                    // constructor
    void addEdge(int V1, int V2);                                    // ads the edge{V1,V2} to the graph
    bool isCyclicComponent(int Node, bool *visited, bool *recstack); // checks whether a disconnected component of starting from the Node contains a cycle or not
    bool isCyclic();                                                 // checks presence of cycle in each component
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int V1, int V2)
{
    adj[V1].push_back(V2);
}
bool Graph::isCyclicComponent(int Node, bool *visited, bool *recstack)
{
    if (visited[Node] == false)
    {
        visited[Node] = true;
        recstack[Node] = true;
        for (int x : adj[Node])
        {
            if (!visited[x] && isCyclicComponent(x, visited, recstack))
                return true;
            else if (recstack[x])
                return true;
        }
    }
    recstack[Node] = false;
    return false;
}
bool Graph::isCyclic()
{
    bool *visited = new bool[V];
    bool *recstack = new bool[V];
    int i;
    for (i = 0; i < V; i++)
    {
        visited[i] = recstack[i] = false;
    }
    for (i = 0; i < V; i++)
    {
        if (isCyclicComponent(i, visited, recstack))
            return true;
    }
    return false;
}
int main()
{
    // Create a graph
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    // g.addEdge(3, 0);

    // Function call
    if (g.isCyclic())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;
}