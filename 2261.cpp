// URL: https://www.acmicpc.net/problem/2261
// REF: https://fennecfox38.github.io/2021/03/29/BOJ-2261.html
// REF: https://m.blog.naver.com/martinok1103/221852495975

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

vector<pii> pos;
vector<pii> pos2;
int d = INT_MAX;

bool comp(pii &p1, pii &p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int Dist(int s, int e) {
    int dx = (pos[s].first - pos[e].first);
    int dy = (pos[s].second - pos[e].second);
    return dx * dx + dy * dy;
}
int Dist2(int s, int e) {
    int dx = (pos2[s].first - pos2[e].first);
    int dy = (pos2[s].second - pos2[e].second);
    return dx * dx + dy * dy;
}

int Search(int s, int e) {
    if (e - s == 1) {
        d = min(d, Dist(s, e));
        return d;
    } else if (e - s == 2) {
        d = min(d, Dist(s, s + 1));
        d = min(d, Dist(s + 1, e));
        d = min(d, Dist(s, e));
        return d;
    } else {
        int m = s + (e - s) / 2;
        int d1 = Search(s, m);
        int d2 = Search(m + 1, e);
        d = min(d, d1);
        d = min(d, d2);
        int mx = (pos[m].first + pos[m + 1].first) / 2;
        int si = m, ei = m + 1;
        while ((mx - pos[si].first) * (mx - pos[si].first) < d && si > s)
            si--;
        while ((pos[ei].first - mx) * (pos[ei].first - mx) < d && ei < e)
            ei++;

        pos2.assign(&pos[si], &pos[ei + 1]);
        sort(pos2.begin(), pos2.end(), comp);
        int size = pos2.size();
        REP(i, 0, size) {
            int j = i + 1;
            while (j < size && (pos2[i].second - pos2[j].second) * (pos2[i].second - pos2[j].second) < d) {
                d = min(d, Dist2(i, j));
                j++;
            }
        }

        // REP(i, si, m + 1) {
        //     REP(j, m + 1, ei + 1) {
        //         if ((pos[i].second - pos[j].second) * pos[i].second - pos[j].second > d) {
        //             continue;
        //         }
        //         d = min(d, Dist(i, j));
        //     }
        // }
        return d;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    pos.assign(N, {0, 0});
    REP(i, 0, N) { cin >> pos[i].first >> pos[i].second; }
    sort(pos.begin(), pos.end());
    cout << Search(0, N - 1);

    return 0;
}