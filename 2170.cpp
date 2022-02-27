// URL: https://www.acmicpc.net/problem/2170
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    vector<pii> lines;
    int N, x1, x2;
    cin >> N;
    REP(i, 0, N) {
        cin >> x1 >> x2;
        lines.push_back({x1, x2});
    }
    sort(lines.begin(), lines.end());
    int lineLen = 0;
    int xs = lines[0].first, xe = lines[0].second, nxs, nxe;
    REP(i, 1, N) {
        nxs = lines[i].first;
        nxe = lines[i].second;
        if (xe < nxs) {
            lineLen += xe - xs;
            xs = nxs;
            xe = nxe;
        } else {
            xe = max(xe, nxe);
        }
    }
    lineLen += xe - xs;
    cout << lineLen;

    return 0;
}