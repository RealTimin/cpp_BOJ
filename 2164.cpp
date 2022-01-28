#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    queue<int> q;
    int N;
    cin >> N;
    REP(i, 0, N)
    {
        q.push(i + 1);
    }
    REP(i, 1, N)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
    return 0;
}