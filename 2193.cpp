// URL: https://www.acmicpc.net/problem/2193
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int result[91] = {0};
    // cout.setf(ios::fixed);
    // cout.precision(3);
    ll pn0[100] = {0};
    ll pn1[100] = {0};
    ll sum[100] = {0};
    pn1[1] = 1;
    int N;
    cin >> N;
    REP(i, 1, N)
    {
        pn0[i + 1] = pn0[i] + pn1[i];
        pn1[i + 1] = pn0[i];
        // sum[i + 1] = pn0[i + 1] + pn1[i + 1];
    }
    cout << pn0[N] + pn1[N];

    // result[1] = 1;
    // result[2] = 1;
    // result[3] = 2;

    // for (int i = 4; i <= N; i++)
    // {
    //     result[i] = 2 * result[i - 2] + result[i - 3];
    // }

    // REP(i, 2, N + 1)
    // {
    //     if (result[i] != sum[i])
    //         cout << i << ": " << result[i] << ", " << sum[i] << endl;
    // }

    return 0;
}