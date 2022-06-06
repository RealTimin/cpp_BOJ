// URL: https://www.acmicpc.net/problem/14438
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

ll MakeSeg(Node *node) {
    int s = node->s;
    int e = node->e;
    if (s == e) {
        node->value = nums[s];
    } else {
        int mid = s + (e - s) / 2;
        ll n1, n2;
        node->left = new Node(s, mid);
        n1 = MakeSeg(node->left);
        node->right = new Node(mid + 1, e);
        n2 = MakeSeg(node->right);
        node->value = min(n1, n2);
    }
    return node->value;
}

ll FindMin(Node *node, int s, int e) {
    if (s == e) {
        return nums[s];
    }
    int mid = node->left->e;
    if (s == node->s && e == node->e) {
        return node->value;
    } else if (e <= mid) {
        return FindMin(node->left, s, e);
    } else if (s > mid) {
        return FindMin(node->right, s, e);
    } else {
        ll minValue = FindMin(node->left, s, mid);
        minValue = min(minValue, FindMin(node->right, mid + 1, e));
        return minValue;
    }
}

ll ChangeMin(Node *node, int idx, ll num) {
    int s = node->s;
    int e = node->e;
    ll minValue;
    if (s == e) {
        nums[idx] = num;
        minValue = num;
        node->value = minValue;
        return minValue;
    }
    int mid = node->left->e;
    if (idx <= mid) {
        minValue = ChangeMin(node->left, idx, num);
        node->value = min(minValue, node->right->value);
    } else if (idx > mid) {
        minValue = ChangeMin(node->right, idx, num);
        node->value = min(minValue, node->left->value);
    }
    return node->value;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    ll f, s, e;
    cin >> N;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    // make segment tree
    Node *minSegRoot = new Node(0, N - 1);
    MakeSeg(minSegRoot);

    // query
    cin >> M;
    REP(i, 0, M) {
        cin >> f >> s >> e;
        if (f == 1) {
            // change sums
            ChangeMin(minSegRoot, s - 1, e);
        } else {
            cout << FindMin(minSegRoot, s - 1, e - 1) << endl;
        }
    }
    delete minSegRoot;
    return 0;
}