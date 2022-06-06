// URL: https://www.acmicpc.net/problem/10993
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
int middle;

void FillTriangle(int step, int index, bool downWard) {
    if (step == 0)
        return;
    int h = (1 << (step - 1)) - 1;
    int ni, temp = (1 << (step)) - 1;
    REP(i, 0, temp) {
        board[index][middle + i] = '*';
        board[index][middle - i] = '*';
    }

    temp = (1 << (step)) - 3;
    REP(i, 1, 2 * h + 1) {
        ni = index + (downWard ? 1 : -1) * i;
        board[ni][middle - temp] = '*';
        board[ni][middle + temp] = '*';
        temp--;
    }

    ni = index + (downWard ? 1 : -1) * h;
    FillTriangle(step - 1, ni, !downWard);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    bool downWard;
    int N, si, height, width, temp;
    cin >> N;
    height = (1 << N) - 1;
    downWard = !(N % 2);
    si = downWard ? 0 : height - 1;
    width = (1 << (N + 1)) - 3;
    middle = width / 2;
    board.assign(height, vector<char>());
    temp = width;
    REP(i, 0, height) {
        board[(downWard ? i : height - 1 - i)].assign(temp, ' ');
        temp--;
    }
    FillTriangle(N, si, downWard);
    REP(i, 0, height) {
        FOREACH(it, board[i]) { cout << *it; }
        cout << endl;
    }

    return 0;
}