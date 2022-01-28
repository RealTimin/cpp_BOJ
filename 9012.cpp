#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
    int N, l;
    bool correct;
    string s;
    deque<char> d;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        d.clear();
        l = s.length();
        correct = false;
        for (int j = 0; j < l; j++)
        {
            if (d.empty())
                d.push_back(s[j]);
            else if (s[j] == '(')
                d.push_back(s[j]);
            else if (s[j] == ')' && d.back() == '(')
                d.pop_back();
            else
                d.push_back(s[j]);
        }

        if (d.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}