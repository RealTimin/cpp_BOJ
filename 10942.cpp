// URL: https://www.acmicpc.net/problem/10942
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAXN 2001

bool isPalindrome[MAXN][MAXN] = {0};
bool visited[MAXN][MAXN] = {0};
int N, M;
int arr[MAXN];

bool FindPalindrome(int s, int e)
{
    if (visited[s][e])
        return isPalindrome[s][e];
    visited[s][e] = 1;
    bool pal;
    if (s >= e)
        pal = true;
    else if (arr[s] != arr[e])
        pal = false;
    else
        pal = FindPalindrome(s + 1, e - 1);
    isPalindrome[s][e] = pal;
    return pal;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    // DP
    cin >> N;
    REP(i, 1, N + 1)
    {
        cin >> arr[i];
    }
    cin >> M;
    int s, e;
    REP(i, 0, M)
    {
        cin >> s >> e;
        cout << FindPalindrome(s, e) << endl;
    }

    return 0;
}