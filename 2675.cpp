#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

int main()
{
    int T;
    int times;
    string s;
    cin >> T;
    REP(i, 0, T)
    {
        cin >> times;
        cin >> s;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            REP(j, 0, times)
            {
                cout << *it;
            }
        }
        cout << endl;
    }
    return 0;
}