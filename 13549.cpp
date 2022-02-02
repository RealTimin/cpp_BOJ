#include <bits/stdc++.h>

// URL: https://www.acmicpc.net/problem/13549

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAX_NUM 120000
#define MIN_NUM 0
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
    queue<int> newPosAfterSec;
    int N, K;
    int sec = -1;
    int size, num, prev, next, twice;
    bool reached = false;
    cin >> N >> K;
    vector<bool> visited(MAX_NUM, 0);
    twice = N << 1;
    newPosAfterSec.push(N);
    visited[N] = true;
    while (MIN_NUM < twice && twice < MAX_NUM)
    {
        if (MIN_NUM <= twice && twice < MAX_NUM && !visited[twice])
        {
            visited[twice] = true;
            newPosAfterSec.push(twice);
        }
        twice = twice << 1;
    }
    while (!reached)
    {
        sec++;
        size = newPosAfterSec.size();
        reached = false;
        REP(i, 0, size)
        {
            num = newPosAfterSec.front();
            prev = num - 1;
            if (MIN_NUM <= prev && prev < MAX_NUM && !visited[prev])
            {
                visited[prev] = true;
                newPosAfterSec.push(prev);
            }
            while (MIN_NUM < prev && prev < MAX_NUM)
            {
                prev = prev << 1;
                if (MIN_NUM <= prev && prev < MAX_NUM && !visited[prev])
                {
                    visited[prev] = true;
                    newPosAfterSec.push(prev);
                }
            }

            next = num + 1;
            if (MIN_NUM <= next && next < MAX_NUM && !visited[next])
            {
                visited[next] = true;
                newPosAfterSec.push(next);
            }
            while (MIN_NUM < next && next < MAX_NUM)
            {
                next = next << 1;
                if (MIN_NUM <= next && next < MAX_NUM && !visited[next])
                {
                    visited[next] = true;
                    newPosAfterSec.push(next);
                }
            }
            if (num == K)
                reached = true;
            newPosAfterSec.pop();
        }
    }
    cout << sec;
    return 0;
}