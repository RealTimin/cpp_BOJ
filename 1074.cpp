#include <bits/stdc++.h>
// URL: https://www.acmicpc.net/problem/1074

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int findZ(int si, int sr, int sc, int r, int c, int len)
{
    if (len == 1)
        return si;
    int numSize = len * len / 4;
    len /= 2;
    int whichRow = (r < sr + len) ? 0 : 1;
    int whichCol = (c < sc + len) ? 0 : 1;
    int ni, nr, nc;
    if (whichRow)
        nr = sr + len;
    else
        nr = sr;
    if (whichCol)
        nc = sc + len;
    else
        nc = sc;

    if (whichRow)
    {
        if (whichCol)
            ni = si + 3 * numSize;
        else
            ni = si + 2 * numSize;
    }
    else
    {
        if (whichCol)
            ni = si + 1 * numSize;
        else
            ni = si;
    }
    return findZ(ni, nr, nc, r, c, len);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, r, c;
    cin >> N >> r >> c;
    int len = 1 << N;
    int i = findZ(0, 0, 0, r, c, len);
    cout << i;
    return 0;
}