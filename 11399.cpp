#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11399

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

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
    int N, num;
    vi t;
    cin >> N;
    REP(i, 0, N)
    {
        cin >> num;
        t.push_back(num);
    }
    sort(t.begin(), t.end());
    int k = N, result = 0;
    REP(i, 0, N)
    {
        result += k * t[i];
        k--;
    }
    cout << result;
    return 0;
}