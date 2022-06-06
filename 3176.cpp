// URL: https://www.acmicpc.net/problem/3176
// REF: https://m.blog.naver.com/kks227/220820773477 (LCA)
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
#define INF 1000001

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
    int N, K;
    cin >> N;
    vector<vector<pii>> adj(N, vector<pii>());
    vvi parent(N, vi());   // parent[i][t]: i's 2**t th parent // parent[i][t+1] = parent[parent[i][t]][t]
    vvi smallWay(N, vi()); // smallWay[i][t]: shortest length between i and i's 2**t th parent
    vvi bigWay(N, vi());
    vector<Node *> nodes(N, nullptr);
    REP(i, 0, N) {
        Node *newNode = new Node(i);
        nodes[i] = newNode;
    }

    int n1, n2, f;
    REP(i, 1, N) {
        cin >> n1 >> n2 >> f;
        n1--, n2--;
        adj[n1].push_back({n2, f});
        adj[n2].push_back({n1, f});
    }

    queue<int> q;
    vi visited(N, 0);
    int index, d, ai;
    q.push(0);
    visited[0] = 1;
    parent[0].push_back(-1);
    smallWay[0].push_back(-1);
    bigWay[0].push_back(-1);
    while (!q.empty()) {
        index = q.front();
        d = nodes[index]->depth;
        FOREACH(it, adj[index]) {
            ai = (*it).first;
            f = (*it).second;
            if (visited[ai] == 0) {
                nodes[index]->childs.push_back(nodes[ai]);
                nodes[ai]->depth = d + 1;
                nodes[ai]->value = f;
                parent[ai].push_back(index);
                smallWay[ai].push_back(f);
                bigWay[ai].push_back(f);
                visited[ai] = 1;
                q.push(ai);
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
                smallWay[i].push_back(-1);
                bigWay[i].push_back(-1);
            } else if (parent[parent[i][t]][t] == -1) {
                parent[i].push_back(-1);
                smallWay[i].push_back(-1);
                bigWay[i].push_back(-1);
            } else {
                chk = false;
                parent[i].push_back(parent[parent[i][t]][t]);
                smallWay[i].push_back(min(smallWay[i][t], smallWay[parent[i][t]][t]));
                bigWay[i].push_back(max(bigWay[i][t], bigWay[parent[i][t]][t]));
            }
        }
        t++;
    }

    cin >> K;
    int d1, d2, dif, k;
    int minL, maxL;
    REP(i, 0, K) {
        cin >> n1 >> n2;
        n1--, n2--;
        d1 = nodes[n1]->depth, d2 = nodes[n2]->depth;
        if (d1 < d2) {
            swap(n1, n2);
            swap(d1, d2);
        }
        minL = INF, maxL = -1;

        // make d1 == d2
        while (d1 > d2) {
            dif = d1 - d2;
            k = 0;
            while (dif != 1) {
                dif >>= 1;
                k++;
            }
            minL = min(minL, smallWay[n1][k]);
            maxL = max(maxL, bigWay[n1][k]);
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
            minL = min(minL, smallWay[n1][k]);
            maxL = max(maxL, bigWay[n1][k]);
            n1 = parent[n1][k];
            minL = min(minL, smallWay[n2][k]);
            maxL = max(maxL, bigWay[n2][k]);
            n2 = parent[n2][k];
        }
        cout << minL << ' ' << maxL << endl;
    }

    delete nodes[0];

    return 0;
}