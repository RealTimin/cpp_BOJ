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
    list<pair<Node *, int>> anodes; // first: adjacent node, second: edge weight
};

class WeightedGraph
{
public:
    WeightedGraph() : nodeCount(0), edgeCount(0), directed(false) { nodes.clear(); }
    WeightedGraph(int _nc, bool _d = false) : nodeCount(_nc), edgeCount(0), directed(_d)
    {
        nodes.clear();
        for (int i = 0; i < nodeCount; i++)
        {
            Node *newNode = new Node(i);
            nodes.push_back(newNode);
        }
    }

    ~WeightedGraph()
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
    void InsertNode(int index);
    void InsertEdge(int i1, int i2, int weight);
    bool isConnected(int i1, int i2) { return false; }

    void Dijkstra(int startIndex);
    void Dijkstra_pq(int startIndex);

    void Prim(int startIndex);
    void Prim_pq(int startIndex);

private:
    vector<Node *> nodes;
    bool directed;
    int nodeCount;
    int edgeCount;
};

void WeightedGraph::InsertNode()
{
    int index;
    for (index = 0; index < nodes.size() && nodes[index] != nullptr; index++)
        ;
    InsertNode(index);
}

void WeightedGraph::InsertNode(int index)
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

void WeightedGraph::InsertEdge(int i1, int i2, int weight)
{
    InsertNode(i1);
    InsertNode(i2);
    if (i1 >= 0 && i2 >= 0)
    {
        if (directed)
        {
            nodes[i1]->anodes.push_back(pair<Node *, int>(nodes[i2], weight));
            edgeCount++;
        }
        else
        {
            nodes[i2]->anodes.push_back(pair<Node *, int>(nodes[i1], weight));
            nodes[i1]->anodes.push_back(pair<Node *, int>(nodes[i2], weight));
            edgeCount += 2;
        }
    }
}

void WeightedGraph::Dijkstra(int startIndex)
{
    struct NodeInfo
    {
        /* data */
        // int index;
        int distance = __INT_MAX__;
        bool visited = false;
        Node *prevNode = nullptr;
    };

    int min_distance;
    int min_index = 0;
    bool min_found;
    int neighbor_index;
    int size = nodes.size();
    NodeInfo *nodeInfo = new NodeInfo[size];

    if (startIndex >= 0 && startIndex < size && nodes[startIndex] != nullptr)
    {
        nodeInfo[startIndex].distance = 0;
    }

    while (1)
    {
        // find unvisited, min distance node N. if all unvisited node is infinity distance, stop loop.

        min_distance = __INT_MAX__;
        min_index = 0;
        min_found = false;
        for (int i = 0; i < size; i++)
        {
            if (nodes[i] != nullptr && !nodeInfo[i].visited && nodeInfo[i].distance < min_distance)
            {
                min_distance = nodeInfo[i].distance;
                min_index = i;
                min_found = true;
            }
        }
        if (!min_found)
            break;

        // update N's neighbor
        // if N's neighbor is unvisited & distance is smaller, distance update & prevNode update
        for (auto it = nodes[min_index]->anodes.begin(); it != nodes[min_index]->anodes.end(); it++)
        {
            neighbor_index = (*it).first->index;
            if (nodes[neighbor_index] != nullptr && !nodeInfo[neighbor_index].visited && min_distance + (*it).second < nodeInfo[neighbor_index].distance)
            {
                nodeInfo[neighbor_index].distance = min_distance + (*it).second;
                nodeInfo[neighbor_index].prevNode = nodes[min_index];
            }
        }
        // N is visited
        nodeInfo[min_index].visited = true;
    }
    // print nodeInfo
    for (int i = 1; i < size; i++)
    {
        if (nodeInfo[i].distance == __INT_MAX__)
            cout << "INF" << '\n';
        else
            cout << nodeInfo[i].distance << '\n';
    }
    // print nodeInfo
    // Node *prevNode = nullptr;
    // for (int i = 0; i < size; i++)
    // {
    //     if (nodes[i] != nullptr)
    //     {
    //         cout << "Node " << i;
    //         cout << " - visited: " << nodeInfo[i].visited << ", distance from Node " << startIndex << ": " << nodeInfo[i].distance << endl;
    //         cout << "path from Node " << i << " to " << startIndex << ": " << i;
    //         prevNode = nodeInfo[i].prevNode;
    //         while (prevNode != nullptr)
    //         {
    //             cout << " -> " << prevNode->index;
    //             prevNode = nodeInfo[prevNode->index].prevNode;
    //         }
    //         cout << endl;
    //     }
    // }
    delete[] nodeInfo;
    return;
}

void WeightedGraph::Dijkstra_pq(int startIndex)
{
    struct NodeInfo
    {
        /* data */
        int index;
        int distance = __INT_MAX__;
        bool visited = false;
        Node *prevNode = nullptr;
    };
    struct compare
    {
        bool operator()(NodeInfo n1, NodeInfo n2)
        {
            return n1.distance > n2.distance; // greater -> min heap
        }
    };
    int min_distance;
    int min_index;
    Node *min_prevNode;
    int neighbor_index;
    int size = nodes.size();
    NodeInfo *nodeInfo = new NodeInfo[size];

    priority_queue<NodeInfo, vector<NodeInfo>, compare> pq;

    if (startIndex >= 0 && startIndex < size && nodes[startIndex] != nullptr)
    {
        nodeInfo[startIndex].distance = 0;
    }

    for (int i = 0; i < size; i++)
    {
        nodeInfo[i].index = i;
        if (nodes[i] != nullptr)
            pq.push(nodeInfo[i]);
    }

    while (1)
    {
        // find unvisited, min distance node N.
        // if all unvisited node is infinity distance, stop loop.
        if (pq.empty())
            break;
        min_distance = pq.top().distance;
        min_index = pq.top().index;
        min_prevNode = pq.top().prevNode;
        pq.pop();
        if (min_distance == __INT_MAX__)
            break;
        // if N is not visited, update nodeInfo. else erase
        if (!nodeInfo[min_index].visited)
        {
            nodeInfo[min_index].distance = min_distance;
            nodeInfo[min_index].prevNode = min_prevNode;
            nodeInfo[min_index].visited = true;
        }
        else
            continue;

        // update N's neighbor
        // if N's neighbor is unvisited & distance is smaller, distance update & prevNode update
        for (auto it = nodes[min_index]->anodes.begin(); it != nodes[min_index]->anodes.end(); it++)
        {
            neighbor_index = (*it).first->index;
            if (nodes[neighbor_index] != nullptr && !nodeInfo[neighbor_index].visited && min_distance + (*it).second < nodeInfo[neighbor_index].distance)
            {
                nodeInfo[neighbor_index].distance = min_distance + (*it).second;
                nodeInfo[neighbor_index].prevNode = nodes[min_index];
                pq.push(nodeInfo[neighbor_index]);
            }
        }
    }
    // print nodeInfo
    for (int i = 1; i < size; i++)
    {
        if (nodeInfo[i].distance == __INT_MAX__)
            cout << "INF" << '\n';
        else
            cout << nodeInfo[i].distance << '\n';
    }

    // print nodeInfo
    // Node *prevNode = nullptr;
    // for (int i = 0; i < size; i++)
    // {
    //     if (nodes[i] != nullptr)
    //     {
    //         cout << "Node " << i;
    //         cout << " - visited: " << nodeInfo[i].visited << ", distance from Node " << startIndex << ": " << nodeInfo[i].distance << endl;
    //         cout << "path from Node " << i << " to " << startIndex << ": " << i;
    //         prevNode = nodeInfo[i].prevNode;
    //         while (prevNode != nullptr)
    //         {
    //             cout << " -> " << prevNode->index;
    //             prevNode = nodeInfo[prevNode->index].prevNode;
    //         }
    //         cout << endl;
    //     }
    // }
    delete[] nodeInfo;
    return;
}

void WeightedGraph::Prim(int startIndex)
{
    struct NodeInfo
    {
        /* data */
        // int index;
        int distance = __INT_MAX__;
        bool visited = false;
        Node *prevNode = nullptr;
    };

    int min_distance;
    int min_index = 0;
    bool min_found;
    int neighbor_index;
    int size = nodes.size();
    NodeInfo *nodeInfo = new NodeInfo[size];

    if (startIndex >= 0 && startIndex < size && nodes[startIndex] != nullptr)
    {
        nodeInfo[startIndex].distance = 0;
    }

    while (1)
    {
        // find unvisited, min distance node N. if all unvisited node is infinity distance, stop loop.

        min_distance = __INT_MAX__;
        min_index = 0;
        min_found = false;
        for (int i = 0; i < size; i++)
        {
            if (nodes[i] != nullptr && !nodeInfo[i].visited && nodeInfo[i].distance < min_distance)
            {
                min_distance = nodeInfo[i].distance;
                min_index = i;
                min_found = true;
            }
        }
        if (!min_found)
            break;

        // N is visited
        nodeInfo[min_index].visited = true;

        // update N's neighbor
        // if N's neighbor is unvisited & distance is smaller, distance update & prevNode update
        for (auto it = nodes[min_index]->anodes.begin(); it != nodes[min_index]->anodes.end(); it++)
        {
            neighbor_index = (*it).first->index;
            if (nodes[neighbor_index] != nullptr && !nodeInfo[neighbor_index].visited && (*it).second < nodeInfo[neighbor_index].distance)
            {
                nodeInfo[neighbor_index].distance = (*it).second;
                nodeInfo[neighbor_index].prevNode = nodes[min_index];
            }
        }
    }

    // print nodeInfo
    Node *prevNode = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (nodes[i] != nullptr)
        {
            prevNode = nodeInfo[i].prevNode;
            cout << "Node " << i;
            cout << " - visited: " << nodeInfo[i].visited << ", parent node: ";
            if (prevNode)
                cout << prevNode->index;
            else
                cout << "null";
            cout << ", distance from parent Node: " << nodeInfo[i].distance << endl;
            cout << "path from Node " << i << " to " << startIndex << ": " << i;
            while (prevNode != nullptr)
            {
                cout << " -> " << prevNode->index;
                prevNode = nodeInfo[prevNode->index].prevNode;
            }
            cout << endl;
        }
    }
    delete[] nodeInfo;
    return;
}

void WeightedGraph::Prim_pq(int startIndex)
{
    struct NodeInfo
    {
        /* data */
        int index;
        int distance = __INT_MAX__;
        bool visited = false;
        Node *prevNode = nullptr;
    };
    struct compare
    {
        bool operator()(NodeInfo n1, NodeInfo n2)
        {
            return n1.distance > n2.distance; // greater -> min heap
        }
    };
    int min_distance;
    int min_index;
    Node *min_prevNode;
    int neighbor_index;
    int size = nodes.size();
    NodeInfo *nodeInfo = new NodeInfo[size];

    priority_queue<NodeInfo, vector<NodeInfo>, compare> pq;

    if (startIndex >= 0 && startIndex < size && nodes[startIndex] != nullptr)
    {
        nodeInfo[startIndex].distance = 0;
    }

    for (int i = 0; i < size; i++)
    {
        nodeInfo[i].index = i;
        if (nodes[i] != nullptr)
            pq.push(nodeInfo[i]);
    }

    while (1)
    {
        // find unvisited, min distance node N.
        // if all unvisited node is infinity distance, stop loop.
        if (pq.empty())
            break;
        min_distance = pq.top().distance;
        min_index = pq.top().index;
        min_prevNode = pq.top().prevNode;
        pq.pop();
        if (min_distance == __INT_MAX__)
            break;
        // if N is not visited, update nodeInfo. else erase
        if (!nodeInfo[min_index].visited)
        {
            nodeInfo[min_index].distance = min_distance;
            nodeInfo[min_index].prevNode = min_prevNode;
            nodeInfo[min_index].visited = true;
        }
        else
            continue;

        // update N's neighbor
        // if N's neighbor is unvisited & distance is smaller, distance update & prevNode update
        for (auto it = nodes[min_index]->anodes.begin(); it != nodes[min_index]->anodes.end(); it++)
        {
            neighbor_index = (*it).first->index;
            if (nodes[neighbor_index] != nullptr && !nodeInfo[neighbor_index].visited && (*it).second < nodeInfo[neighbor_index].distance)
            {
                nodeInfo[neighbor_index].distance = (*it).second;
                nodeInfo[neighbor_index].prevNode = nodes[min_index];
                pq.push(nodeInfo[neighbor_index]);
            }
        }
    }

    // print nodeInfo
    Node *prevNode = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (nodes[i] != nullptr)
        {
            cout << "Node " << i;
            cout << " - visited: " << nodeInfo[i].visited << ", distance from Node " << startIndex << ": " << nodeInfo[i].distance << endl;
            cout << "path from Node " << i << " to " << startIndex << ": " << i;
            prevNode = nodeInfo[i].prevNode;
            while (prevNode != nullptr)
            {
                cout << " -> " << prevNode->index;
                prevNode = nodeInfo[prevNode->index].prevNode;
            }
            cout << endl;
        }
    }
    delete[] nodeInfo;
    return;
}

int main()
{
    int V;
    int E;
    int startV; 
    int u, v, w;
    cin >> V >> E;
    cin >> startV;
    WeightedGraph g(V, true);
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        g.InsertEdge(u, v, w);
    }
    g.Dijkstra(startV);
    return 0;
}