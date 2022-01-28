#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/9095

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int findF(vi &f, int n)
{
    if (n < f.size())
        return f[n];
    int fi;
    for (int i = f.size(); i <= n; i++)
    {
        fi = f[i - 1] + f[i - 2] + f[i - 3];
        f.push_back(fi);
    }
    return f[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vi f = {0, 1, 2, 4};
    int result;
    int T, n;
    cin >> T;
    REP(i, 0, T)
    {
        cin >> n;
        cout << findF(f, n) << endl;
    }

    return 0;
}