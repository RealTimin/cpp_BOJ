// URL: https://www.acmicpc.net/problem/13305
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 100000

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    vi distance;
    vi CpL;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // pair<cost, index>

    cin >> N;
    distance.assign(N, 0);
    CpL.assign(N, 0);
    REP(i, 1, N) { cin >> distance[i]; }
    REP(i, 0, N) { cin >> CpL[i]; }
    REP(i, 1, N) { pq.push({CpL[i - 1], i}); }

    ll lenSum, result = 0;
    int tempIndex, lastIndex = N;
    while (!pq.empty()) {
        tempIndex = pq.top().second;
        if (tempIndex < lastIndex) {
            lenSum = 0;
            REP(i, tempIndex, lastIndex) { lenSum += distance[i]; }
            result += pq.top().first * lenSum;
            lastIndex = tempIndex;
        }
        pq.pop();
    }
    cout << result;
    return 0;
}