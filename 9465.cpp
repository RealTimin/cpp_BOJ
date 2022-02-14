// URL: https://www.acmicpc.net/problem/9465
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int T, N, n1, n2;
    vector<pii> board(MAXN, {0, 0});
    vi remove1(MAXN, 0), remove2(MAXN, 0), removeNone(MAXN, 0);
    cin >> T;
    REP(t, 0, T)
    {
        // board.clear();
        // remove1.clear();
        // remove2.clear();
        // removeNone.clear();
        cin >> N;
        REP(i, 0, N)
        {
            cin >> board[i].first;
        }
        REP(i, 0, N)
        {
            cin >> board[i].second;
        }
        remove1[0] = board[0].first;
        remove2[0] = board[0].second;
        removeNone[0] = 0;
        REP(i, 1, N)
        {
            n1 = board[i].first;
            n2 = board[i].second;
            remove1[i] = max(remove2[i - 1], removeNone[i - 1]) + n1;
            remove2[i] = max(remove1[i - 1], removeNone[i - 1]) + n2;
            removeNone[i] = max(remove1[i - 1], remove2[i - 1]);
        }
        cout << max(max(remove1[N - 1], remove2[N - 1]), removeNone[N - 1]) << endl;
    }

    return 0;
}