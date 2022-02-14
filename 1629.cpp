// URL: https://www.acmicpc.net/problem/1629
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll Multi(ll A, ll B, ll C)
{
    if (B == 1)
        return A % C;
    ll result;
    if (B & 1) // odd
    {
        result = Multi(A, B / 2, C);
        result = (result * result) % C;
        result = (result * A) % C;
    }
    else // even
    {
        result = Multi(A, B / 2, C);
        result = (result * result) % C;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    ll A, B, C;
    cin >> A >> B >> C;
    ll result = Multi(A, B, C);
    cout << result;

    return 0;
}