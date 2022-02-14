// URL: https://www.acmicpc.net/problem/1562
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MOD 1000000000
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
        Iter();
        Output();
    }
    // Data structure
    int N;
    int basic[10][100] = {0};
    int reach0[10][100] = {0};
    int reach9[10][100] = {0};
    int done[10][100] = {0};

private:
    void Input()
    {
        cin >> N;
    }

    void Iter()
    {
        REP(i, 1, 10)
        {
            basic[i][0] = 1;
        }
        reach9[9][0] = 1;

        REP(j, 0, N - 1)
        {
            // basic
            basic[0][j + 1] = basic[1][j];
            basic[1][j + 1] = basic[2][j];
            REP(i, 2, 8)
            {
                basic[i][j + 1] = (basic[i - 1][j] + basic[i + 1][j]) % MOD;
            }
            basic[8][j + 1] = basic[7][j];
            basic[9][j + 1] = basic[8][j];
            // reach0
            reach0[0][j + 1] = (reach0[1][j] + basic[0][j + 1]) % MOD;
            REP(i, 1, 8)
            {
                reach0[i][j + 1] = (reach0[i - 1][j] + reach0[i + 1][j]) % MOD;
            }
            reach0[8][j + 1] = reach0[7][j];
            reach0[9][j + 1] = reach0[8][j];
            // reach9
            reach9[0][j + 1] = reach9[1][j];
            reach9[1][j + 1] = reach9[2][j];
            REP(i, 2, 9)
            {
                reach9[i][j + 1] = (reach9[i - 1][j] + reach9[i + 1][j]) % MOD;
            }
            reach9[9][j + 1] = (reach9[8][j] + basic[9][j + 1]) % MOD;
            // done
            done[0][j + 1] = (done[1][j] + reach9[0][j + 1]) % MOD;
            REP(i, 1, 9)
            {
                done[i][j + 1] = (done[i - 1][j] + done[i + 1][j]) % MOD;
            }
            done[9][j + 1] = (done[8][j] + reach0[9][j + 1]) % MOD;
        }
    }

    void Output()
    {
        int sum = 0;
        REP(i, 0, 10)
        {
            sum = (sum + done[i][N - 1]) % MOD;
        }
        cout << sum;
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