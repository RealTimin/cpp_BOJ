#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/2606

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Node
{
public:
    Node(int _index) : index(_index) { anodes.clear(); }
    ~Node() { anodes.clear(); }
    int index;
    list<Node *> anodes;
};

class Graph
{

public:
    Graph() : nodeCount(0), edgeCount(0), directed(false) { nodes.clear(); }
    Graph(int _nc, bool _d = false) : nodeCount(_nc), edgeCount(0), directed(_d)
    {
        nodes.clear();
        for (int i = 0; i < nodeCount; i++)
        {
            Node *newNode = new Node(i);
            nodes.push_back(newNode);
        }
    }

    ~Graph()
    {
        for (auto it = nodes.begin(); it != nodes.end(); it++)
        {
            if (*it)
            {
                delete (*it);
                (*it) = nullptr;
            }
        }
        nodes.clear();
    }

    int GetNodeCount() const { return nodeCount; }
    int GetEdgeCount() const { return edgeCount; }
    void InsertNode();
    void InsertNode(int index);      // insert node of given index if the node is not already in the graph.
    void InsertEdge(int i1, int i2); // insert edge from i1 to i2 (if undirected, also add edge from i2 to i1)
    void BFS(int startIndex);
    int DFS(int startIndex);
    bool isConnected(int i1, int i2);

private:
    vector<Node *> nodes;
    int nodeCount;
    int edgeCount;
    bool directed;
    void DFSTraversal(bool *visited, int index);
};

void Graph::InsertNode()
{
    int index;
    for (index = 0; index < nodes.size() && nodes[index] != nullptr; index++)
        ;

    InsertNode(index);
}
void Graph::InsertNode(int index)
{
    if (nodes.size() < index + 1)
        nodes.resize(index + 1);
    if (index >= 0 && nodes[index] == nullptr)
    {
        Node *newNode = new Node(index);
        nodes[index] = newNode;
        nodeCount++;
    }
    return;
}

void Graph::InsertEdge(int i1, int i2)
{
    InsertNode(i1);
    InsertNode(i2);
    if (i1 >= 0 && i2 >= 0)
    {
        if (directed)
        {
            nodes[i1]->anodes.push_back(nodes[i2]);
            edgeCount++;
        }
        else
        {
            nodes[i2]->anodes.push_back(nodes[i1]);
            nodes[i1]->anodes.push_back(nodes[i2]);
            edgeCount += 2;
        }
    }
}

void Graph::BFS(int startIndex)
{
    bool *visited = new bool[nodes.size()];
    queue<Node *> d;
    int index;

    for (int i = 0; i < nodes.size(); i++)
        visited[i] = false;
    if (startIndex >= 0 && startIndex < nodes.size() && nodes[startIndex] != nullptr)
        d.push(nodes[startIndex]);
    while (!d.empty())
    {
        index = d.front()->index;
        if (!visited[index])
        {
            cout << nodes[index]->index << ' ';
            for (auto it = nodes[index]->anodes.begin(); it != nodes[index]->anodes.end(); it++)
            {
                d.push((*it));
            }
            visited[index] = true;
        }
        d.pop();
    }
    delete[] visited;
    return;
}

int Graph::DFS(int startIndex)
{
    bool *visited = new bool[nodes.size()];
    for (int i = 0; i < nodes.size(); i++)
        visited[i] = false;
    if (startIndex >= 0 && startIndex < nodes.size() && nodes[startIndex] != nullptr)
        DFSTraversal(visited, startIndex);
    int V = 0;
    REP(i, 0, nodes.size())
    {
        if (visited[i])
            V++;
    }
    delete[] visited;
    return V;
}

void Graph::DFSTraversal(bool *visited, int index)
{
    visited[index] = true;
    // cout << nodes[index]->index << ' ';
    int ni;
    int V = 0;
    for (auto it = nodes[index]->anodes.begin(); it != nodes[index]->anodes.end(); it++)
    {
        ni = (*it)->index;
        if (visited[ni] == false)
            DFSTraversal(visited, ni);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int V, E;
    int v1, v2;
    int result;
    cin >> V >> E;

    Graph g(V + 1); // start index 1, so add 0
    REP(i, 0, E)
    {
        cin >> v1 >> v2;
        g.InsertEdge(v1, v2);
    }
    result = g.DFS(1);
    cout << (result - 1);
    return 0;
}