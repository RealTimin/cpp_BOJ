// URL: https://www.acmicpc.net/problem/00000
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

void Hanoi(int step, int from, int to)
{
    int other = 6 - from - to;
    if (step == 1)
    {
        cout << from << ' ' << to << endl;
        return;
    }
    Hanoi(step - 1, from, other);
    cout << from << ' ' << to << endl;
    Hanoi(step - 1, other, to);
    return;
}

string BigNumSubtract(string &n1, string &n2)
{
    // assume that all characters are 'numbers'
    // assume that n1 is bigger than n2
    // n[0] is the LSB
    string result;
    int c = 0, dif, s1 = n1.size(), s2 = n2.size();
    int nb = s1 > s2 ? s1 : s2;

    int i = 0, temp;
    while (i < s2)
    {
        if (n1[i] < n2[i])
        {
            // borrow
            temp = i;
            while (n1[++temp] == '0')
                ;
            n1[temp]--;
            while (--temp != i)
                n1[temp] = '9';
            c = 10;
        }
        else
            c = 0;

        dif = c + (int)(n1[i] - '0') - (int)(n2[i] - '0');

        result.push_back(dif + '0');
        i++;
    }

    while (i < s1)
        result.push_back(n1[i++]);

    while (--i >= 0 && result[i] == '0')
        result.pop_back();

    return result;
}

string BigNumMultiply(string &n1, string &n2)
{
    // assume that all characters are 'numbers'
    // n[0] is the LSB
    // time complexity: O(n^2)
    string result;
    int c = 0, mul, s1 = n1.size(), s2 = n2.size();
    int sr = result.size(), i, i1, i2;
    for (i1 = 0; i1 < s1; i1++)
    {
        c = 0;
        for (i2 = 0; i2 < s2; i2++)
        {
            i = i1 + i2;
            if (i < sr)
            {
                mul = c + (int)(result[i] - '0') + (int)(n1[i1] - '0') * (int)(n2[i2] - '0');
                result[i] = (mul % 10) + '0';
            }
            else
            {
                mul = c + (int)(n1[i1] - '0') * (int)(n2[i2] - '0');
                result.push_back((mul % 10) + '0');
                sr++;
            }
            c = mul / 10;
        }
        i = i1 + i2;
        while (c != 0)
        {
            if (i < sr)
            {
                mul = c + (int)(result[i] - '0');
                result[i] = (mul % 10) + '0';
            }
            else
            {
                mul = c;
                result.push_back((mul % 10) + '0');
                sr++;
            }
            c = mul / 10;
            i++;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    string s = "1";
    string s2 = "2";
    string s1 = "1";
    REP(i, 0, N)
    {
        s = BigNumMultiply(s, s2);
    }
    s = BigNumSubtract(s, s1);
    for (auto it = s.rbegin(); it != s.rend(); it++)
    {
        cout << (*it);
    }
    cout << endl;
    if (N <= 20)
        Hanoi(N, 1, 3);

    return 0;
}