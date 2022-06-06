// URL: https://www.acmicpc.net/problem/10997
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
int D[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int N;
    cin >> N;
    const int L = 4 * N - 3;
    if (N == 1) {
        cout << '*';
        return 0;
    }
    board.assign(L + 2, vector<char>(L, ' '));
    board[0] = vector<char>(L, '*');
    board[L + 1] = vector<char>(L, '*');
    REP(i, 0, L + 2) { board[i][0] = '*'; }
    REP(i, 2, L + 2) { board[i][L - 1] = '*'; }
    int counter = 1, d = 0, i = 2, j = L - 1, ni, nj;
    while (counter != 0) {
        counter = 0;
        ni = i + 2 * D[d][0];
        nj = j + 2 * D[d][1];
        while (board[ni][nj] == ' ') {
            counter++;
            i += D[d][0];
            j += D[d][1];
            ni += D[d][0];
            nj += D[d][1];
            board[i][j] = '*';
        }
        d++;
        d %= 4;
    }

    REP(i, 0, L + 2) {
        if (i == 1) {
            cout << '*' << endl;
            continue;
        }
        REP(j, 0, L) { cout << board[i][j]; }
        cout << endl;
    }

    return 0;
}