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
    int N, K;
    cin >> N >> K;
    REP(i, 0, N)
    {
        q.push(i + 1);
    }

    cout << '<';
    REP(i, 0, N)
    {
        if (i == N - 1)
        {
            cout << q.front() << '>';
            q.pop();
        }
        else
        {
            REP(j, 1, K)
            {
                q.push(q.front());
                q.pop();
            }
            cout << q.front() << ", ";
            q.pop();
        }
    }
    return 0;
}