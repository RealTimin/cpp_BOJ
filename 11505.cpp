// URL: https://www.acmicpc.net/problem/11505
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
#define MOD 1000000007

int N, M;
vi nums;

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

ll MakeSeg(Node *node, int s, int e) {
    if (s == e) {
        node->value = nums[s];
        return node->value;
    }
    int mid = s + (e - s) / 2;
    node->left = new Node(s, mid);
    node->right = new Node(mid + 1, e);
    ll v1 = MakeSeg(node->left, s, mid);
    ll v2 = MakeSeg(node->right, mid + 1, e);
    node->value = (v1 * v2) % MOD;
    return node->value;
}

ll ChangeSeg(Node *node, int index, int num) {
    int s = node->s;
    int e = node->e;
    if (s == e && e == index) {
        nums[index] = num;
        node->value = num;
        return node->value;
    }
    int mid = s + (e - s) / 2;
    ll v1, v2;
    if (index <= mid) {
        v1 = ChangeSeg(node->left, index, num);
        v2 = node->right->value;
        node->value = (v1 * v2) % MOD;
        return node->value;
    } else {
        v1 = node->left->value;
        v2 = ChangeSeg(node->right, index, num);
        node->value = (v1 * v2) % MOD;
        return node->value;
    }
}

ll SearchSeg(Node *node, int s, int e) {
    if (s == node->s && e == node->e) {
        return node->value;
    }
    int mid = node->left->e;
    if (e <= mid) {
        return SearchSeg(node->left, s, e);
    } else if (mid < s) {
        return SearchSeg(node->right, s, e);
    } else {
        ll v1, v2;
        v1 = SearchSeg(node->left, s, mid);
        v2 = SearchSeg(node->right, mid + 1, e);
        return (v1 * v2) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int temp;
    int question, a, b;
    cin >> N >> M >> temp;
    M += temp;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    Node *root = new Node(0, N - 1);
    MakeSeg(root, 0, N - 1);
    REP(i, 0, M) {
        cin >> question >> a >> b;
        if (question == 1) {
            ChangeSeg(root, a - 1, b);
        } else {
            cout << SearchSeg(root, a - 1, b - 1) << endl;
        }
    }
    delete root;
    return 0;
}