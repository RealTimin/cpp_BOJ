// URL: https://www.acmicpc.net/problem/1992
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void Quad(vector<string> &map, int x, int y, int len)
{
    char c = map[x][y];
    bool same = true;
    REP(i, x, x + len)
    {
        REP(j, y, y + len)
        {
            if (map[i][j] != c)
            {
                same = false;
                break;
            }
        }
        if (!same)
            break;
    }

    if (same)
    {
        cout << c;
    }
    else
    {
        cout << '(';
        len /= 2;
        Quad(map, x, y, len);
        Quad(map, x, y + len, len);
        Quad(map, x + len, y, len);
        Quad(map, x + len, y + len, len);
        cout << ')';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    vector<string> map;
    string s;
    REP(i, 0, N)
    {
        cin >> s;
        map.push_back(s);
    }

    Quad(map, 0, 0, N);

    return 0;
}