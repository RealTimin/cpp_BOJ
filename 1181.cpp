// time: 880ms
// HACK: Why it takes SO MANY times?

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define REP(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

bool string_compare(string &s1, string &s2)
{
    if (s1.size() == s2.size())
        return s1 < s2;
    return s1.size() < s2.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    string s;
    vector<string> dict;
    REP(i, 0, N)
    {
        cin >> s;
        dict.push_back(s);
    }
    sort(dict.begin(), dict.end(), string_compare);
    s.clear();
    REP(i, 0, N)
    {
        if (s != dict[i])
        {
            s = dict[i];
            cout << s << endl;
        }
    }
    return 0;
}