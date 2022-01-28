#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1629

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
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int A, B, C;
    cin >> A >> B >> C;
    ll result = A;
    REP(i, 1, B)
    {
        result = (result * A) % C;
    }
    cout << result;
    

    return 0;
}