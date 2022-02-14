// URL: https://www.acmicpc.net/problem/2407
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

string BigNumAdd(string &n1, string &n2)
{
    // assume that all characters are 'numbers'
    // n[0] is the LSB
    string result;
    int c = 0, sum, s1 = n1.size(), s2 = n2.size();
    int nb = s1 > s2 ? s1 : s2;

    int i = 0;
    while (i < nb)
    {
        if (i >= s2)
            sum = c + (int)(n1[i] - '0');
        else if (i >= s1)
            sum = c + (int)(n2[i] - '0');
        else
            sum = c + (int)(n1[i] - '0') + (int)(n2[i] - '0');
        c = sum >= 10 ? 1 : 0;
        result.push_back((sum % 10) + '0');
        i++;
    }
    if (c)
        result.push_back(c + '0');

    return result;
}

void FindCombs(int n, int r, vector<vector<string>> &combs)
{
    bool nf = combs[n][r].empty();
    if (!nf)
        return;
    if (n == r)
        combs[n][r] = '1';
    else if (r == 0)
        combs[n][r] = '1';
    else
    {
        FindCombs(n - 1, r - 1, combs);
        FindCombs(n - 1, r, combs);
        combs[n][r] = BigNumAdd(combs[n - 1][r - 1], combs[n - 1][r]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    // nCr = n-1Cr-1 + n-1Cr
    vector<vector<string>> combs(101, vector<string>(101, string()));
    int N, M;
    cin >> N >> M;
    M = (N - M > M) ? M : N - M;
    FindCombs(N, M, combs);
    for (auto it = combs[N][M].rbegin(); it != combs[N][M].rend(); it++)
    {
        cout << (*it);
    }

    return 0;
}