#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11724

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

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
    void DFS(int startIndex);
    bool isConnected(int i1, int i2);
    bool hasCycle();
    int connectedComponent();

private:
    vector<Node *> nodes;
    int nodeCount;
    int edgeCount;
    bool directed;
    void DFSTraversal(bool *visited, int index);
    bool hasCycleHelper_directed(int *visited, int *finished, int *parent, int index);
    bool hasCycleHelper_indirected(int *visited, int *finished, int *parent, int index);
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
            edgeCount++;
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

void Graph::DFS(int startIndex)
{
    bool *visited = new bool[nodes.size()];
    for (int i = 0; i < nodes.size(); i++)
        visited[i] = false;
    if (startIndex >= 0 && startIndex < nodes.size() && nodes[startIndex] != nullptr)
        DFSTraversal(visited, startIndex);
    delete[] visited;
    return;
}

void Graph::DFSTraversal(bool *visited, int index)
{
    visited[index] = true;
    // cout << nodes[index]->index << ' ';
    int ni;
    for (auto it = nodes[index]->anodes.begin(); it != nodes[index]->anodes.end(); it++)
    {
        ni = (*it)->index;
        if (visited[ni] == false)
            DFSTraversal(visited, ni);
    }
    return;
}

bool Graph::hasCycle()
{
    int size = nodes.size();
    bool cycle = false;
    int *visited = new int[size];
    int *finished = new int[size];
    int *parent = new int[size];
    int si;
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        finished[i] = false;
        parent[i] = i;
    }
    if (directed)
    {
        // DFS based cycle detection
        // using visited, finished, parent(parent is just for printing cycle)
        int *in_Degree = new int[size];
        bool allChecked = false;
        int zi;
        for (auto it = nodes.begin(); it != nodes.end(); it++)
        {
            for (auto a_it = (*it)->anodes.begin(); a_it != (*it)->anodes.end(); a_it++)
            {
                in_Degree[(*a_it)->index]++;
            }
        }

        // DFS based cycle detection
        while (!allChecked)
        {
            zi = -1;
            si = -1;
            for (int i = 0; i < size; i++)
            {
                if (!visited[i])
                {
                    si = i;
                    if (in_Degree[i] == 0)
                        zi = i;
                }
            }
            if (si == -1)
                break;
            if (zi == -1)
                cycle = true; // there is a cycle.
            else
                si = zi;
            if (hasCycleHelper_directed(visited, finished, parent, si)) // else, start DFS from si.
                cycle = true;
            allChecked = true;
            for (int i = 0; i < size; i++)
            {
                if (!visited[i])
                    allChecked = false;
            }
        }

        delete[] in_Degree;
    }
    else
    {
        // indirected graph -> only tree edge & back edge

        bool allChecked = false;
        // DFS based cycle detection
        while (!allChecked)
        {
            si = -1;
            for (int i = 0; i < size; i++)
                if (!visited[i])
                    si = i;
            if (si == -1)
                break;
            if (hasCycleHelper_indirected(visited, finished, parent, si))
                cycle = true;
            allChecked = true;
            for (int i = 0; i < size; i++)
                if (!visited[i])
                    allChecked = false;
        }
    }
    delete[] visited, finished, parent;
    return cycle;
}

bool Graph::hasCycleHelper_directed(int *visited, int *finished, int *parent, int index)
{
    visited[index] = true;
    int a_index;
    bool cycle = false;
    for (auto a_it = nodes[index]->anodes.begin(); a_it != nodes[index]->anodes.end(); a_it++)
    {
        a_index = (*a_it)->index;
        if (!visited[a_index])
        {
            // WHITE vertex
            parent[a_index] = index; // set parent index
            if (hasCycleHelper_directed(visited, finished, parent, a_index))
                cycle = true;
        }
        else if (!finished[a_index])
        {
            // GREY vertex
            cycle = true;
            // TODO: print cycle
            int cycleIndex = index;
            cout << "Node index in a cycle: ";
            while (cycleIndex != a_index)
            {
                cout << cycleIndex << ' ';
                cycleIndex = parent[cycleIndex];
            }
            cout << a_index << ' ' << index << endl;
        }
        else
        {
            // BLACK vertex
        }
    }
    finished[index] = true;
    return cycle;
}

bool Graph::hasCycleHelper_indirected(int *visited, int *finished, int *parent, int index)
{
    visited[index] = true;
    int a_index;
    bool cycle = false;
    for (auto a_it = nodes[index]->anodes.begin(); a_it != nodes[index]->anodes.end(); a_it++)
    {
        a_index = (*a_it)->index;
        if (!visited[a_index])
        {
            // WHITE vertex
            parent[a_index] = index; // set parent index
            if (hasCycleHelper_indirected(visited, finished, parent, a_index))
                cycle = true;
        }
        else if (!finished[a_index])
        {
            if (parent[index] != a_index) // if adjacent node is not my parent node
            {
                // GREY vertex
                cycle = true;
                // TODO: print cycle
                int cycleIndex = index;
                cout << "Node index in a cycle: ";
                while (cycleIndex != a_index)
                {
                    cout << cycleIndex << ' ';
                    cycleIndex = parent[cycleIndex];
                }
                cout << a_index << ' ' << index << endl;
            }
        }
        else
        {
            // BLACK vertex. Zero possibility in indirected graph.
        }
    }
    finished[index] = true;
    return cycle;
}

int Graph::connectedComponent()
{
    int size = nodes.size();
    bool cycle = false;
    bool *visited = new bool[size];
    int si;
    bool allChecked = false;
    int cc = 0;
    for (int i = 0; i < size; i++)
        visited[i] = 0;
    // DFS based connected component find
    while (1)
    {
        si = -1;
        for (int i = 0; i < size; i++)
            if (!visited[i])
                si = i;
        if (si == -1)
            break;
        DFSTraversal(visited, si);
        cc++;
    }
    delete[] visited;
    return cc;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int n1, n2;
    cin >> N >> M;
    Graph g(N);
    REP(i, 0, M)
    {
        cin >> n1 >> n2;
        g.InsertEdge(n1 - 1, n2 - 1);
    }
    cout << g.connectedComponent();

    return 0;
}