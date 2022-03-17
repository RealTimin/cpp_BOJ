// URL: https://www.acmicpc.net/problem/1761
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

class Node {
  public:
    Node(int v = 0) : value(v) { childs.clear(); }
    ~Node() {
        FOREACH(it, childs) { delete (*it); }
    }
    int value;
    int depth = 0;
    vector<Node *> childs;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    cin >> N;
    vector<vector<pii>> adj(N, vector<pii>());
    vi distance(N, 0);
    vvi parent(N, vi()); // parent[i][t]: i's 2**t th parent // parent[i][t+1] = parent[parent[i][t]][t]
    vector<Node *> nodes(N, nullptr);
    REP(i, 0, N) {
        Node *newNode = new Node(i);
        nodes[i] = newNode;
    }

    int n1, n2, w;
    REP(i, 1, N) {
        cin >> n1 >> n2 >> w;
        n1--, n2--;
        adj[n1].push_back({n2, w});
        adj[n2].push_back({n1, w});
    }

    queue<int> q;
    vi visited(N, 0);
    int index, d, ai;
    q.push(0);
    visited[0] = 1;
    parent[0].push_back(-1);
    while (!q.empty()) {
        index = q.front();
        visited[index] = 1;
        d = nodes[index]->depth;
        FOREACH(it, adj[index]) {
            ai = (*it).first;
            w = (*it).second;
            if (visited[ai] == 0) {
                visited[ai] = 1;
                nodes[index]->childs.push_back(nodes[ai]);
                nodes[ai]->depth = d + 1;
                parent[ai].push_back(index);
                q.push(ai);
                distance[ai] = distance[index] + w;
            }
        }
        q.pop();
    }

    bool chk = false;
    int t = 0;
    while (!chk) {
        chk = true;
        REP(i, 0, N) {
            if (parent[i][t] == -1) {
                parent[i].push_back(-1);
            } else if (parent[parent[i][t]][t] == -1) {
                parent[i].push_back(-1);
            } else {
                chk = false;
                parent[i].push_back(parent[parent[i][t]][t]);
            }
        }
        t++;
    }

    cin >> M;
    int d1, d2, dif, k, result;
    REP(i, 0, M) {
        cin >> n1 >> n2;
        n1--, n2--;
        d1 = nodes[n1]->depth, d2 = nodes[n2]->depth;
        result = distance[n1] + distance[n2];
        if (d1 < d2) {
            swap(n1, n2);
            swap(d1, d2);
        }

        // make d1 == d2
        while (d1 > d2) {
            dif = d1 - d2;
            k = 0;
            while (dif != 1) {
                dif >>= 1;
                k++;
            }
            n1 = parent[n1][k];
            d1 = nodes[n1]->depth;
        }

        // find LCA
        while (n1 != n2) {
            k = 0;
            while (parent[n1][k] != parent[n2][k])
                k++;
            if (k != 0) {
                k--;
            }
            n1 = parent[n1][k];
            n2 = parent[n2][k];
        }

        result -= 2 * distance[n1];
        cout << result << endl;
    }

    delete nodes[0];

    return 0;
}