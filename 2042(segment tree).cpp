// URL: https://www.acmicpc.net/problem/2042
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

vector<ll> nums;

class Node {
  public:
    ll value;
    int s, e;
    Node *left;
    Node *right;
    Node(int _s, int _e, ll v = -1) : s(_s), e(_e), value(v), left(nullptr), right(nullptr){};
    void DeleteNode() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
        return;
    }
    ~Node() { DeleteNode(); }
};

ll MakeSumSeg(Node *node) {
    int s = node->s;
    int e = node->e;
    if (s == e) {
        node->value = nums[s];
    } else {
        int mid = s + (e - s) / 2;
        ll n1, n2;
        node->left = new Node(s, mid);
        n1 = MakeSumSeg(node->left);
        node->right = new Node(mid + 1, e);
        n2 = MakeSumSeg(node->right);
        node->value = n1 + n2;
    }
    return node->value;
}

ll FindSum(Node *node, int s, int e) {
    if (s == e) {
        return nums[s];
    }
    int mid = node->left->e;
    if (s == node->s && e == node->e) {
        return node->value;
    } else if (e <= mid) {
        return FindSum(node->left, s, e);
    } else if (s > mid) {
        return FindSum(node->right, s, e);
    } else {
        ll sumValue = FindSum(node->left, s, mid);
        sumValue += FindSum(node->right, mid + 1, e);
        return sumValue;
    }
}

ll ChangeSum(Node *node, int idx, ll num) {
    int s = node->s;
    int e = node->e;
    ll dif;
    if (s == e) {
        dif = num - nums[idx];
        nums[idx] += dif;
        node->value += dif;
        return dif;
    }
    int mid = node->left->e;
    if (idx <= mid) {
        dif = ChangeSum(node->left, idx, num);
    } else if (idx > mid) {
        dif = ChangeSum(node->right, idx, num);
    }
    node->value += dif;
    return dif;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M, K;
    ll f, s, e;
    cin >> N >> M >> K;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    // make segment tree
    Node *sumSegRoot = new Node(0, N - 1);
    MakeSumSeg(sumSegRoot);

    // query
    REP(i, 0, M + K) {
        cin >> f >> s >> e;
        if (f == 1) {
            // change sums
            ChangeSum(sumSegRoot, s - 1, e);
        } else {
            cout << FindSum(sumSegRoot, s - 1, e - 1) << endl;
        }
    }
    delete sumSegRoot;
    return 0;
}