// URL: https://www.acmicpc.net/problem/2448
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define FOREACH(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)

vector<vector<char>> board;
int N, k;

void MakeSpace(int x, int y, int step) {
    if (step == -1)
        return;
    int a = 3 * (1 << (step - 1));
    if (step == 0)
        a = 1;
    int ej = y + 2 * a;
    REP(i, 0, a) {
        REP(j, y + 1 + 2 * i, ej) { board[x + a + i][j] = ' '; }
    }

    MakeSpace(x, y, step - 1);
    MakeSpace(x + a, y, step - 1);
    MakeSpace(x + a, ej, step - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int temp;
    cin >> N;
    temp = N / 3;
    while (temp != 1) {
        temp /= 2;
        k++;
    }
    board.assign(N, vector<char>(2 * N - 1, '*'));
    MakeSpace(0, 0, k);
    REP(i, 0, N) {
        REP(j, i + 1, N) cout << ' ';
        REP(j, 0, 2 * i + 1) cout << board[i][j];
        REP(j, i + 1, N) cout << ' ';
        cout << endl;
    }

    return 0;
}