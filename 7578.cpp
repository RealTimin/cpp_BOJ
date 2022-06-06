// URL: https://www.acmicpc.net/problem/7578
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
#define MAXN 500000
#define MAXNUM 1000001

int order[MAXNUM] = {0};
int N;

class Node {
  public:
    Node(int _s, int _e) : left(nullptr), right(nullptr), s(_s), e(_e), m((_s + _e) / 2), total(0){};
    ~Node() {
        delete left;
        delete right;
    }
    void MakeSegTree() {
        if (s == e)
            return;
        left = new Node(s, m);
        left->MakeSegTree();
        right = new Node(m + 1, e);
        right->MakeSegTree();
    }
    ll Update(int n) {
        ll count = 0;
        if (s == e) {
            // s == n
            count = 0;
        } else if (n <= m) {
            count += left->Update(n);
        } else {
            count += left->total;
            count += right->Update(n);
        }
        total++;
        return count;
    }
    Node *left;
    Node *right;
    int s;
    int e;
    int m;
    ll total;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;
    vi firstLine(N, 0);
    vi secondLine(N, 0);
    vi match(N, 0);
    ll result = 0, temp;
    REP(i, 0, N) { cin >> firstLine[i]; }
    REP(i, 0, N) { cin >> secondLine[i]; }
    REP(i, 0, N) { order[secondLine[i]] = i; }
    REP(i, 0, N) { match[i] = (order[firstLine[i]]); }
    Node *root = new Node(0, N - 1);
    root->MakeSegTree();
    REP(i, 0, N) {
        temp = match[i] - root->Update(match[i]);
        result += temp;
    }
    cout << result;

    return 0;
}