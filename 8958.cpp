#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    int prevPoint;
    int points;
    int a;
    string s;
    cin >> N;
    REP(i, 0, N)
    {
        cin >> s;
        points = 0;
        prevPoint = 0;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if ((*it) == 'O')
                points += (++prevPoint);
            else
                prevPoint = 0;
        }
        cout << points << endl;
    }

    return 0;
}