// URL: https://www.acmicpc.net/problem/7579
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXM 10000001
// #define MAXM 1001
#define MAXN 101

int N, M;
int L[MAXM] = {0};
int m[MAXN] = {0};
int c[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N >> M;
    REP(i, 1, N + 1) { cin >> m[i]; }
    REP(i, 1, N + 1) { cin >> c[i]; }
    REP(j, 1, M + 1) { L[j] = MAXM; }

    int idx;
    REP(i, 1, N + 1) {
        REP(j, 0, M + 1) {
            idx = M - j;
            if (m[i] >= idx)
                L[idx] = min(L[idx], c[i]);
            else
                L[idx] = min(L[idx], L[idx - m[i]] + c[i]);
        }
        // cout << ' ';
    }

    cout << L[M];

    return 0;
}