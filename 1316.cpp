// URL: https://www.acmicpc.net/problem/1316
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
#define ALPHABET 26

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N, cnt = 0;
    string s;
    char prev;
    bool grouped;
    vi chk;

    cin >> N;
    REP(i, 0, N) {
        cin >> s;
        chk.assign(ALPHABET, 0);
        prev = 0;
        grouped = true;
        FOREACH(it, s) {
            if (prev == 0) {
                prev = *it;
                chk[prev - 'a'] = 1;
            } else if (prev != *it) {
                if (chk[*it - 'a'] == 1) {
                    grouped = false;
                    break;
                } else {
                    prev = *it;
                    chk[prev - 'a'] = 1;
                }
            } else {
            }
        }
        cnt += grouped ? 1 : 0;
    }
    cout << cnt;
    return 0;
}