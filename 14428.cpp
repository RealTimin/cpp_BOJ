// URL: https://www.acmicpc.net/problem/14428
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

int N, M;
vi nums;

class Node {
  public:
    int value;
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

int MakeSeg(Node *node, int s, int e) {
    if (s == e) {
        node->value = s;
        return node->value;
    }
    int mid = s + (e - s) / 2;
    node->left = new Node(s, mid);
    node->right = new Node(mid + 1, e);
    int i1 = MakeSeg(node->left, s, mid);
    int i2 = MakeSeg(node->right, mid + 1, e);
    node->value = (nums[i1] <= nums[i2]) ? i1 : i2;
    return node->value;
}

int UpdateSeg(Node *node, int index, int v) {
    int s = node->s;
    int e = node->e;
    if (s == e && e == index) {
        nums[s] = v;
        return node->value;
    }
    int mid = s + (e - s) / 2;
    int i1, i2;
    if (index <= mid) {
        i1 = UpdateSeg(node->left, index, v);
        i2 = node->right->value;
    } else {
        i1 = node->left->value;
        i2 = UpdateSeg(node->right, index, v);
    }
    node->value = (nums[i1] <= nums[i2]) ? i1 : i2;
    return node->value;
}

int SearchSeg(Node *node, int s, int e) {
    if (s == node->s && e == node->e)
        return node->value;
    // if (s == e)
    //     return node->value;

    int mid = node->left->e;
    if (e <= mid) {
        return SearchSeg(node->left, s, e);
    } else if (s > mid) {
        return SearchSeg(node->right, s, e);
    } else {
        int i1 = SearchSeg(node->left, s, mid);
        int i2 = SearchSeg(node->right, mid + 1, e);
        return (nums[i1] <= nums[i2]) ? i1 : i2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    Node *root = new Node(0, N - 1);
    MakeSeg(root, 0, N - 1);
    cin >> M;
    int question, a, b;
    REP(i, 0, M) {
        cin >> question >> a >> b;
        if (question == 1) {
            UpdateSeg(root, a - 1, b);
        } else {
            cout << SearchSeg(root, a - 1, b - 1) + 1 << endl;
        }
    }
    delete root;
    return 0;
}