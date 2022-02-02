#include <bits/stdc++.h>

// URL: https://www.acmicpc.net/problem/13913

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAX_NUM 200000
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
    vector<int> parent(MAX_NUM, -1);
    newPosAfterSec.push(N);
    visited[N] = true;
    parent[N] = N;
    while (!reached)
    {
        size = newPosAfterSec.size();
        reached = false;
        REP(i, 0, size)
        {
            num = newPosAfterSec.front();
            prev = num - 1;
            next = num + 1;
            twice = num << 1;
            if (MIN_NUM <= prev && prev < MAX_NUM && !visited[prev])
            {
                visited[prev] = true;
                parent[prev] = num;
                newPosAfterSec.push(prev);
            }
            if (MIN_NUM <= next && next < MAX_NUM && !visited[next])
            {
                visited[next] = true;
                parent[next] = num;
                newPosAfterSec.push(next);
            }
            if (MIN_NUM <= twice && twice < MAX_NUM && !visited[twice])
            {
                visited[twice] = true;
                parent[twice] = num;
                newPosAfterSec.push(twice);
            }
            if (num == K)
                reached = true;
            newPosAfterSec.pop();
        }
        sec++;
    }
    cout << sec << endl;
    // print path
    stack<int> path;
    int p = K;
    while (p != parent[p])
    {
        path.push(p);
        p = parent[p];
    }
    path.push(p);

    while (!path.empty())
    {
        cout << path.top() << ' ';
        path.pop();
    }
    return 0;
}