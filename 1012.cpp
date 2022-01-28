#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    // TODO: bachoo
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    int ROW;
    int COL;
    int K;
    int farm[50][50] = {0};
    int i, j;

    cin >> T;
    REP(t, 0, T)
    {
        // input
        cin >> ROW >> COL >> K;
        REP(row, 0, ROW)
        {
            REP(col, 0, COL)
            {
                farm[row][col] = 0;
            }
        }
        REP(k, 0, K)
        {
            cin >> i >> j;
            farm[i][j] = 1;
        }

        // calculate

        // print
        REP(row, 0, ROW)
        {
            REP(col, 0, COL)
            {
                cout << farm[row][col];
            }
            cout << endl;
        }
    }
    return 0;
}