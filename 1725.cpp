// URL: https://www.acmicpc.net/problem/1725
// URL: https://www.acmicpc.net/problem/12846
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
    int N = 1;
    int num;
    set<int> s;
    vector<pii> order;
    ll maxValue, si, ei;
    cin >> N;
    order.clear();
    s.clear();
    REP(i, 0, N) {
        cin >> num;
        order.push_back({num, i});
    }
    sort(order.begin(), order.end());
    maxValue = -1;
    REP(i, 0, N) {
        auto p = s.insert(order[i].second);
        auto it = p.first;
        // find si
        if (it == s.begin()) {
            si = 0;
        } else {
            it--;
            si = (*it) + 1;
            it++;
        }
        // find ei
        it++;
        if (it == s.end()) {
            ei = N - 1;
        } else {
            ei = (*it) - 1;
            it--;
        }
        maxValue = max(maxValue, order[i].first * (ei - si + 1));
    }
    if (N != 0)
        cout << maxValue << endl;

    return 0;
}