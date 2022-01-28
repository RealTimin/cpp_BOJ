// #include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <vector>

// URL: https://www.acmicpc.net/problem/1697

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
    newPosAfterSec.push(N);
    while (!reached)
    {
        size = newPosAfterSec.size();
        reached = false;
        REP(i, 0, size)
        {
            num = newPosAfterSec.front();
            visited[num] = true;
            prev = num - 1;
            next = num + 1;
            twice = num << 1;
            if (MIN_NUM <= prev && prev < MAX_NUM && !visited[prev])
                newPosAfterSec.push(prev);
            if (MIN_NUM <= next && next < MAX_NUM && !visited[next])
                newPosAfterSec.push(next);
            if (MIN_NUM <= twice && twice < MAX_NUM && !visited[twice])
                newPosAfterSec.push(twice);
            if (num == K)
                reached = true;
            newPosAfterSec.pop();
        }
        sec++;
    }
    cout << sec;
    return 0;
}