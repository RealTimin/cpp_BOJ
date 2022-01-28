#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1991

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Node
{
public:
    Node(char v, Node *l = nullptr, Node *r = nullptr) : value(v), left(l), right(r){};
    char value;
    Node *left;
    Node *right;
};

void preorder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->value;
    preorder(node->left);
    preorder(node->right);
    return;
}
void inorder(Node *node)
{
    if (node == nullptr)
        return;
    inorder(node->left);
    cout << node->value;
    inorder(node->right);
    return;
}
void postorder(Node *node)
{
    if (node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    vector<Node *> nodes;
    Node *newNode = nullptr;
    char v = 'A';
    char l, r, A;
    int index;
    REP(i, 0, N)
    {
        newNode = new Node(v);
        nodes.push_back(newNode);
        v++;
    }
    A = 'A';
    REP(i, 0, N)
    {
        cin >> v >> l >> r;
        index = (int)(v - A);
        if (l != '.')
            nodes[index]->left = nodes[(int)(l - A)];
        if (r != '.')
            nodes[index]->right = nodes[(int)(r - A)];
    }
    preorder(nodes[0]);
    cout << endl;
    inorder(nodes[0]);
    cout << endl;
    postorder(nodes[0]);
    cout << endl;

    return 0;
}
