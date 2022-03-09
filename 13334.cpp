// URL: https://www.acmicpc.net/problem/13334
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
    ll N, p1, p2, D, cepos;
    ll maxCnt = 0;
    ll count = 0;
    vector<pii> intervals;
    priority_queue<ll, vector<ll>, greater<ll>> spos;
    cin >> N;
    REP(i, 0, N) {
        cin >> p1 >> p2;
        if (p1 > p2)
            swap(p1, p2);
        intervals.push_back({p2, p1});
    }
    sort(intervals.begin(), intervals.end());
    cin >> D;

    REP(i, 0, N) {
        cepos = intervals[i].first;
        spos.push(intervals[i].second);
        count++;
        while (!spos.empty() && spos.top() + D < cepos) {
            count--;
            spos.pop();
        }
        maxCnt = max(maxCnt, count);
    }

    cout << maxCnt;

    return 0;
}