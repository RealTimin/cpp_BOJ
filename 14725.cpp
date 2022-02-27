// URL: https://www.acmicpc.net/problem/14725
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

class Node {
  public:
    Node(){};
    Node(string &s) : value(s){};
    Node *AddChild(string &s) {
        auto it = childs.find(s);
        if (it == childs.end()) {
            Node *newNode = new Node(s);
            childs.insert({s, newNode});
            return newNode;
        } else {
            return (*it).second;
        }
    }

    ~Node() { DeleteChilds(); }
    string value;
    map<string, Node *> childs;

  private:
    void DeleteChilds() {
        if (childs.empty()) {
            return;
        }
        for (auto it = childs.begin(); it != childs.end(); it++) {
            (*it).second->DeleteChilds();
            delete (*it).second;
        }
        childs.clear();
        return;
    }
};

void PrintNode(Node *node, int step) {
    // preorder print
    if (!node->value.empty()) {
        REP(i, 0, step) { cout << "--"; }
        cout << node->value << endl;
    }
    for (auto it = node->childs.begin(); it != node->childs.end(); it++) {
        PrintNode((*it).second, step + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, K;
    string s;
    Node *root = new Node();
    Node *node = nullptr;
    cin >> N;
    REP(i, 0, N) {
        cin >> K;
        REP(j, 0, K) {
            cin >> s;
            if (j == 0) {
                node = root->AddChild(s);
            } else {
                node = node->AddChild(s);
            }
        }
    }

    PrintNode(root, -1);
    delete root;

    return 0;
}