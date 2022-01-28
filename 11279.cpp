#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    // std::endl -> time over
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int> pq;
    vector<int> v;
    int N;
    cin >> N;
    int num;
    REP(i, 0, N)
    {
        cin >> num;
        if (num == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                // v.push_back(0);
            }
            else
            {
                cout << pq.top() << '\n';
                // v.push_back(pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}