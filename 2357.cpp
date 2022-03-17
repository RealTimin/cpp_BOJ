// URL: https://www.acmicpc.net/problem/2357
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

vector<int> nums;

class Node {
  public:
    int value;
    int s, e;
    Node *left;
    Node *right;
    Node(int _s, int _e, int v = -1) : s(_s), e(_e), value(v), left(nullptr), right(nullptr){};
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

int MakeMinSeg(Node *node) {
    int s = node->s;
    int e = node->e;
    if (s == e) {
        node->value = nums[s];
    } else {
        int mid = s + (e - s) / 2;
        int n1, n2;
        node->left = new Node(s, mid);
        n1 = MakeMinSeg(node->left);
        node->right = new Node(mid + 1, e);
        n2 = MakeMinSeg(node->right);
        node->value = min(n1, n2);
    }
    return node->value;
}

int MakeMaxSeg(Node *node) {
    int s = node->s;
    int e = node->e;
    if (s == e) {
        node->value = nums[s];
    } else {
        int mid = s + (e - s) / 2;
        int n1, n2;
        node->left = new Node(s, mid);
        n1 = MakeMaxSeg(node->left);
        node->right = new Node(mid + 1, e);
        n2 = MakeMaxSeg(node->right);
        node->value = max(n1, n2);
    }
    return node->value;
}

int FindMin(Node *node, int s, int e) {
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
        int minValue = FindMin(node->left, s, mid);
        minValue = min(minValue, FindMin(node->right, mid + 1, e));
        return minValue;
    }
}

int FindMax(Node *node, int s, int e) {
    if (s == e) {
        return nums[s];
    }
    int mid = node->left->e;
    if (s == node->s && e == node->e) {
        return node->value;
    } else if (e <= mid) {
        return FindMax(node->left, s, e);
    } else if (s > mid) {
        return FindMax(node->right, s, e);
    } else {
        int maxValue = FindMax(node->left, s, mid);
        maxValue = max(maxValue, FindMax(node->right, mid + 1, e));
        return maxValue;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, M;
    int s, e;
    cin >> N >> M;
    nums.assign(N, 0);
    REP(i, 0, N) { cin >> nums[i]; }
    // make segment tree
    Node *minSegRoot = new Node(0, N - 1);
    Node *maxSegRoot = new Node(0, N - 1);
    MakeMinSeg(minSegRoot);
    MakeMaxSeg(maxSegRoot);

    // query
    REP(i, 0, M) {
        cin >> s >> e;
        s--;
        e--;
        cout << FindMin(minSegRoot, s, e) << ' ' << FindMax(maxSegRoot, s, e) << endl;
    }

    delete minSegRoot;
    delete maxSegRoot;
    return 0;
}