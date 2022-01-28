#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/11723

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
    unsigned int S = 0;
    int M;
    cin >> M;
    string op;
    unsigned int num;
    REP(i, 0, M)
    {
        cin >> op;
        if (!op.compare("add"))
        {
            cin >> num;
            S = S | (1 << (num - 1));
        }
        else if (!op.compare("remove"))
        {
            cin >> num;
            S = S & ~(1 << (num - 1));
        }
        else if (!op.compare("check"))
        {
            cin >> num;
            if (S & (1 << (num - 1)))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (!op.compare("toggle"))
        {
            cin >> num;
            S = S ^ (1 << (num - 1));
        }
        else if (!op.compare("all"))
            S = (1 << 21) - 1;
        else if (!op.compare("empty"))
            S = 0;
    }

    return 0;
}