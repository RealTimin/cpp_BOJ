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
    string s;
    string zero("0");
    bool isPalindrome;
    int times;
    cin >> s;
    while (s != zero)
    {
        times = s.size() / 2;
        auto it = s.begin();
        auto rit = s.rbegin();
        isPalindrome = true;
        REP(i, 0, times)
        {
            if ((*it) != (*rit))
            {
                isPalindrome = false;
                break;
            }
            it++;
            rit++;
        }
        if (isPalindrome)
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
        cin >> s;
    }

    return 0;
}