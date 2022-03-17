// URL: https://www.acmicpc.net/problem/12100
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
#define MAXSTEP 10
#define MAXN 20

int board[MAXSTEP + 1][MAXN][MAXN] = {0};
int N;
int maxNum = 0;

void MoveUp(int step) {
    int pi;
    bool merged;
    REP(j, 0, N) {
        pi = -1;
        merged = false;
        REP(i, 0, N) {
            if (board[step][i][j] != 0) {
                if (pi == -1 || board[step + 1][pi][j] != board[step][i][j] || merged) {
                    pi++;
                    board[step + 1][pi][j] = board[step][i][j];
                    merged = false;
                } else {
                    board[step + 1][pi][j] = 2 * board[step][i][j];
                    merged = true;
                }
            }
        }
        while (++pi < N) {
            board[step + 1][pi][j] = 0;
        }
    }
}

void MoveDown(int step) {
    int pi;
    bool merged;
    REP(j, 0, N) {
        pi = -1;
        merged = false;
        REP(i, 0, N) {
            if (board[step][N - 1 - i][j] != 0) {
                if (pi == -1 || board[step + 1][N - 1 - pi][j] != board[step][N - 1 - i][j] || merged) {
                    pi++;
                    board[step + 1][N - 1 - pi][j] = board[step][N - 1 - i][j];
                    merged = false;
                } else {
                    board[step + 1][N - 1 - pi][j] = 2 * board[step][N - 1 - i][j];
                    merged = true;
                }
            }
        }
        while (++pi < N) {
            board[step + 1][N - 1 - pi][j] = 0;
        }
    }
}

void MoveLeft(int step) {
    int pj;
    bool merged;
    REP(i, 0, N) {
        pj = -1;
        merged = false;
        REP(j, 0, N) {
            if (board[step][i][j] != 0) {
                if (pj == -1 || board[step + 1][i][pj] != board[step][i][j] || merged) {
                    pj++;
                    board[step + 1][i][pj] = board[step][i][j];
                    merged = false;
                } else {
                    board[step + 1][i][pj] = 2 * board[step][i][j];
                    merged = true;
                }
            }
        }
        while (++pj < N) {
            board[step + 1][i][pj] = 0;
        }
    }
}

void MoveRight(int step) {
    int pj;
    bool merged;
    REP(i, 0, N) {
        pj = -1;
        merged = false;
        REP(j, 0, N) {
            if (board[step][i][N - 1 - j] != 0) {
                if (pj == -1 || board[step + 1][i][N - 1 - pj] != board[step][i][N - 1 - j] || merged) {
                    pj++;
                    board[step + 1][i][N - 1 - pj] = board[step][i][N - 1 - j];
                    merged = false;
                } else {
                    board[step + 1][i][N - 1 - pj] = 2 * board[step][i][N - 1 - j];
                    merged = true;
                }
            }
        }
        while (++pj < N) {
            board[step + 1][i][N - 1 - pj] = 0;
        }
    }
}

void DFS(int step) {
    if (step == MAXSTEP) {
        REP(i, 0, N) {
            REP(j, 0, N) { maxNum = max(maxNum, board[step][i][j]); }
        }
        return;
    }
    MoveUp(step);
    DFS(step + 1);
    MoveDown(step);
    DFS(step + 1);
    MoveLeft(step);
    DFS(step + 1);
    MoveRight(step);
    DFS(step + 1);
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N;
    REP(i, 0, N) {
        REP(j, 0, N) { cin >> board[0][i][j]; }
    }
    DFS(0);
    cout << maxNum;
    // MoveLeft(0);
    // MoveRight(1);
    return 0;
}