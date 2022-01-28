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
    int sum = 0;
    string s;
    int N;
    cin >> N;
    cin >> s;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        sum += (int)((*it) - '0');
    }
    cout << sum;
    return 0;
}