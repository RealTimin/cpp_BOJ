// URL: https://www.acmicpc.net/problem/9252
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXL 1001

int maxWith[MAXL] = {0};
int maxLen[MAXL] = {0};
int prevIndex[MAXL][MAXL] = {0};
int prevJndex[MAXL][MAXL] = {0};
int maxPrevI[MAXL] = {0};
int maxPrevJ[MAXL] = {0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n1 = s1.size(), n2 = s2.size();
    REP(i, 0, n1)
    {
        REP(j, 0, n2)
        prevIndex[i][j] = -1;
        maxPrevI[i] = -1;
        maxPrevJ[i] = -1;
    }
    int m, mi, mj = -1, ri = -1, rj = -1;
    int result = 0;
    REP(j, 0, n2)
    {
        m = 0;
        mi = -1;
        REP(i, 0, n1)
        {
            if (s1[i] == s2[j])
            {
                if (maxWith[i] < maxLen[i] + 1)
                {
                    maxWith[i] = maxLen[i] + 1;
                    if (maxPrevI[i] == -1)
                    {
                        prevIndex[i][j] = i;
                        prevJndex[i][j] = j;
                    }
                    else
                    {
                        prevIndex[i][j] = maxPrevI[i];
                        prevJndex[i][j] = maxPrevJ[i];
                    }
                }
            }
            if (maxLen[i] < m)
            {
                maxLen[i] = m;
                maxPrevI[i] = mi;
                maxPrevJ[i] = mj;
            }
            if (m < maxWith[i])
            {
                m = maxWith[i];
                mi = i;
                mj = j;
            }
        }
        if (result < m)
        {
            result = m;
            ri = mi;
            rj = mj;
        }
    }

    cout << result << endl;
    stack<int> s;
    int pri, prj;
    REP(i, 0, result)
    {
        s.push(ri);
        pri = ri;
        prj = rj;
        ri = prevIndex[pri][prj];
        rj = prevJndex[pri][prj];
    }
    while (!s.empty())
    {
        cout << s1[s.top()];
        s.pop();
    }

    return 0;
}