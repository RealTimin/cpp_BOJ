// URL: https://www.acmicpc.net/problem/8980
// REF: https://steady-coding.tistory.com/58
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 2001

int box[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, C, M;
    int s, e, w;
    cin >> N >> C >> M;
    vector<pii> q;
    vector<int> c(N, C);
    REP(i, 0, M) {
        cin >> s >> e >> w;
        box[s][e] = w;
        q.push_back({e, -s});
    }
    sort(q.begin(), q.end());
    int result = 0, possible;
    REP(i, 0, M) {
        s = -q[i].second;
        e = q[i].first;
        w = box[s][e];
        possible = w;
        REP(j, s, e) {
            possible = min(possible, c[j]);
            if (possible == 0)
                break;
        }
        if (possible != 0) {
            REP(j, s, e) { c[j] -= possible; }
            result += possible;
        }
    }
    cout << result;

    return 0;
}

// // less |e - s| first
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // cout.setf(ios::fixed);
//     // cout.precision(3);
//     int N, C, M;
//     int s, e, w;
//     cin >> N >> C >> M;
//     vector<pii> q;
//     vector<int> c(N, C);
//     REP(i, 0, M) {
//         cin >> s >> e >> w;
//         box[s][e] = w;
//         q.push_back({e - s, s});
//     }
//     sort(q.begin(), q.end());
//     int result = 0, possible;
//     REP(i, 0, M) {
//         s = q[i].second;
//         e = q[i].first + s;
//         w = box[s][e];
//         possible = w;
//         REP(j, s, e) {
//             possible = min(possible, c[j]);
//             if (possible == 0)
//                 break;
//         }
//         if (possible != 0) {
//             REP(j, s, e) { c[j] -= possible; }
//             result += possible;
//         }
//     }
//     cout << result;

//     return 0;
// }