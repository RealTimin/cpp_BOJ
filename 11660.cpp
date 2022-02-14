// URL: https://www.acmicpc.net/problem/11660
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

class Solution
{
public:
    void Solve()
    {
        Input();
        Output();
    }
    // Data structure
    int N, M;
    vvi sqrsum;

private:
    void Input()
    {
        cin >> N >> M;
        sqrsum.assign(N + 1, vi(N + 1, 0));
        int sum;
        int num;
        REP(i, 1, N + 1)
        {
            sum = 0;
            REP(j, 1, N + 1)
            {
                cin >> num;
                sum += num;
                sqrsum[i][j] = sqrsum[i - 1][j] + sum;
            }
        }

        int x1, x2, y1, y2;
        int result;
        REP(i, 0, M)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            result = sqrsum[x2][y2] - sqrsum[x2][y1] - sqrsum[x1][y2] + sqrsum[x1][y1];
            cout << result << endl;
        }
    }

    void Output()
    {
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    Solution solution;
    solution.Solve();
    return 0;
}