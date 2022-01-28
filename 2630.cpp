#include <iostream>
#include <algorithm>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

int D[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};

pii Divide(vvi &paper, int sr, int sc, int size)
{
    int color = paper[sr][sc];
    bool sameColor = true;
    REP(i, sr, sr + size)
    {
        REP(j, sc, sc + size)
        {
            if (paper[i][j] != color)
            {
                sameColor = false;
                break;
            }
        }
    }
    if (sameColor)
    {
        if (color)
            return {1, 0};
        else
            return {0, 1};
    }
    size /= 2;
    int bcount = 0, wcount = 0;
    pii c;
    REP(d, 0, 4)
    {
        c = Divide(paper, sr + size * D[d][0], sc + size * D[d][1], size);
        bcount += c.first;
        wcount += c.second;
    }
    return {bcount, wcount};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int num;
    vector<vector<int>> paper;
    REP(i, 0, N)
    {
        vector<int> v;
        REP(j, 0, N)
        {
            cin >> num;
            v.push_back(num);
        }
        paper.push_back(v);
    }
    // divide and conquer
    pii result = Divide(paper, 0, 0, N);
    cout << result.second << '\n'
         << result.first;
    return 0;
}