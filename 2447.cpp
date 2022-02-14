// URL: https://www.acmicpc.net/problem/2447
#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int N;
bool emptyFlag[10] = {0};
int logN;

void Print(int log)
{
    if (log == 0)
    {
        cout << '*';
        return;
    }

    if (emptyFlag[log] == 0)
    {
        Print(log - 1);
        Print(log - 1);
        Print(log - 1);
    }
    else
    {
        int r = 1;
        REP(i, 1, log)
        {
            r *= 3;
        }

        Print(log - 1);
        REP(i, 0, r)
        {
            cout << ' ';
        }
        Print(log - 1);
    }
}

void PrintLine()
{
    Print(logN);
    cout << endl;
}

void PrintStar(int log)
{
    if (log == 0)
    {
        PrintLine();
        return;
    }
    emptyFlag[log] = 0;
    PrintStar(log - 1);
    emptyFlag[log] = 1;
    PrintStar(log - 1);
    emptyFlag[log] = 0;
    PrintStar(log - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;
    int size = N;
    while (size != 1)
    {
        size /= 3;
        logN++;
    }
    PrintStar(logN);

    return 0;
}