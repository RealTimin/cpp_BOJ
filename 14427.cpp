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
        node->value = s;
    } else {
        int mid = s + (e - s) / 2;
        ll n1, n2;
        node->left = new Node(s, mid);
        n1 = MakeSeg(node->left);
        node->right = new Node(mid + 1, e);
        n2 = MakeSeg(node->right);
        node->value = nums[n1] <= nums[n2] ? n1 : n2;
    }
    return node->value;
}

ll FindMin(Node *node, int s, int e) {
    if (s == e) {
        return s;
    }
    int mid = node->left->e;
    if (s == node->s && e == node->e) {
        return node->value;
    } else if (e <= mid) {
        return FindMin(node->left, s, e);
    } else if (s > mid) {
        return FindMin(node->right, s, e);
    } else {
        ll n1 = FindMin(node->left, s, mid);
        ll n2 = FindMin(node->left, mid + 1, e);
        return nums[n1] <= nums[n2] ? n1 : n2;
    }
}

ll ChangeMin(Node *node, int idx, ll num) {
    int s = node->s;
    int e = node->e;
    ll minIdx;
    if (s == e) {
        nums[idx] = num;
        minIdx = idx;
        node->value = minIdx;
        return minIdx;
    }
    int mid = node->left->e;
    if (idx <= mid) {
        minIdx = ChangeMin(node->left, idx, num);
        node->value = nums[minIdx] <= nums[node->right->value] ? minIdx : node->right->value;
    } else if (idx > mid) {
        minIdx = ChangeMin(node->right, idx, num);
        node->value = nums[node->left->value] <= nums[minIdx] ? node->left->value : minIdx;
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
        cin >> f;
        if (f == 1) {
            // change sums
            cin >> s >> e;
            ChangeMin(minSegRoot, s - 1, e);
        } else {
            cout << FindMin(minSegRoot, 0, N - 1) + 1 << endl;
        }
    }
    delete minSegRoot;
    return 0;
}