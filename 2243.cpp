// URL: https://www.acmicpc.net/problem/2243
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
    Node() : left(nullptr), right(nullptr), score(-1), count(0), total(-1), height(0), balance(0){};
    Node(int _s, int _c) : left(nullptr), right(nullptr), score(_s), count(_c), total(_c), height(0), balance(0){};
    ~Node() {
        delete left;
        delete right;
    }

    void UpdateInfo() {
        int lh = (left == nullptr ? 0 : left->height);
        int rh = (right == nullptr ? 0 : right->height);
        int lt = (left == nullptr ? 0 : left->total);
        int rt = (right == nullptr ? 0 : right->total);
        height = max(lh, rh) + 1;
        balance = lh - rh;
        total = lt + rt + count;
    }

    void ChangeNode(int s, int c) {
        int res;
        if (score == s) {
            count += c;
        } else if (s < score) {
            left->ChangeNode(s, c);
        } else {
            right->ChangeNode(s, c);
        }
        total += c;
        return;
    }

    int Search(int rank) {
        int result;
        int l = (left == nullptr ? 0 : left->total);
        int r = l + count;
        if (rank <= l) {
            result = left->Search(rank);
        } else if (rank > r) {
            result = right->Search(rank - r);
        } else {
            result = score;
            count--;
        }
        total--;
        return result;
    }

    Node *AddNode(int s, int c) {
        // c must be positive
        // use node height
        if (score == s) {
            // no case
        } else if (s < score) {
            if (left == nullptr) {
                left = new Node(s, c);
            } else {
                left = left->AddNode(s, c);
            }
        } else {
            if (right == nullptr) {
                right = new Node(s, c);
            } else {
                right = right->AddNode(s, c);
            }
        }

        // balancing
        UpdateInfo();
        if (balance > 1) {
            if (left->balance == -1) {
                left = left->RotateLeft();
            }
            return RotateRight();
        } else if (balance < -1) {
            if (right->balance == 1) {
                right = right->RotateRight();
            }
            return RotateLeft();
        } else {
            return this;
        }
    }

    Node *RotateRight() {
        Node *pivot = this->left;
        this->left = pivot->right;
        pivot->right = this;
        this->UpdateInfo();
        pivot->UpdateInfo();
        return pivot;
    }
    Node *RotateLeft() {
        Node *pivot = this->right;
        this->right = pivot->left;
        pivot->left = this;
        this->UpdateInfo();
        pivot->UpdateInfo();
        return pivot;
    }

    Node *left;
    Node *right;
    int score;
    int count;
    int total;
    int height;
    int balance; // lh - rh
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    // AVL Tree + count
    int n, a, b, c;
    cin >> n;
    Node *root = nullptr;
    set<int> S;
    REP(i, 0, n) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            cout << root->Search(b) << endl;
        } else {
            cin >> b >> c;
            if (i == 0) {
                S.insert(b);
                root = new Node(b, c);
            } else {
                if (S.find(b) == S.end()) {
                    S.insert(b);
                    root = root->AddNode(b, c);
                } else {
                    root->ChangeNode(b, c);
                }
            }
        }
    }

    delete root;

    return 0;
}