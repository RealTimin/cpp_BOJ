// URL: https://www.acmicpc.net/problem/1708
// REF: https://www.acmicpc.net/board/view/84121
// REF: https://kbw1101.tistory.com/50
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
#define MAXD 40000

pii mpos(MAXD, MAXD);

bool cmp(pii A, pii B) {
    pii OA = {A.first - mpos.first, A.second - mpos.second};
    pii AB = {B.first - A.first, B.second - A.second};
    ll c = (ll)OA.first * AB.second - (ll)OA.second * AB.first;
    if (c == 0) {
        return (ll)OA.first * AB.first + (ll)OA.second * AB.second > 0;
    }
    return (ll)OA.first * AB.second - (ll)OA.second * AB.first > 0;
}

ll ccw(pii O, pii A, pii B) {
    pii OA = {A.first - O.first, A.second - O.second};
    pii AB = {B.first - A.first, B.second - A.second};
    return (ll)OA.first * AB.second - (ll)OA.second * AB.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    vector<pii> pos(N, {0, 0});
    int mi = -1;
    REP(i, 0, N) {
        cin >> pos[i].first >> pos[i].second;
        if (mpos.second > pos[i].second || (mpos.second == pos[i].second && mpos.first > pos[i].first)) {
            mi = i;
            mpos = pos[i];
        }
    }
    swap(pos[mi].first, pos[N - 1].first);
    swap(pos[mi].second, pos[N - 1].second);
    pos.pop_back();
    sort(ALL(pos), cmp);
    stack<pii> s;
    s.push(mpos);
    s.push(pos[0]);
    pii O, A, B;
    ll c;
    REP(i, 1, N - 1) {
        B = pos[i];
        A = s.top();
        s.pop();
        O = s.top();
        c = ccw(O, A, B);
        if (c > 0) {
            s.push(A);
            s.push(B);
        } else if (c == 0) {
            s.push(B);
        } else {
            i--;
        }
    }
    cout << s.size() << endl;
    return 0;
}
