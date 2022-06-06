// URL: https://www.acmicpc.net/problem/12094
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
int tempMaxNum = 0;
bool noChange[MAXSTEP + 1] = {0}; // 0: up, 1: down, 2: left, 3: right
int minNum[MAXSTEP + 1] = {0};
ll sn = 0;

bool CheckBoard(int step) {
    bool same = true;
    int i, j;
    for (i = 0; same && i < N; i++) {
        for (j = 0; same && j < N; j++) {
            if (board[step][i][j] != board[step + 1][i][j]) {
                same = false;
            }
        }
    }
    return same;
}

void MoveUp(int step) {
    int pi;
    bool merged;
    tempMaxNum = 0; ///
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
                tempMaxNum = max(tempMaxNum, board[step + 1][pi][j]); ///
            } else {
            }
        }
        while (++pi < N) {
            board[step + 1][pi][j] = 0;
        }
    }
    if (tempMaxNum > maxNum) {
        maxNum = tempMaxNum;
        int i = MAXSTEP;
        int temp = maxNum;
        while (i >= 0) {
            minNum[i] = temp;
            temp >>= 1;
            i--;
        }
    }
}

void MoveDown(int step) {
    int pi;
    bool merged;
    tempMaxNum = 0; ///
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
                tempMaxNum = max(tempMaxNum, board[step + 1][N - 1 - pi][j]); ///
            } else {
            }
        }
        while (++pi < N) {
            board[step + 1][N - 1 - pi][j] = 0;
        }
    }
    if (tempMaxNum > maxNum) {
        maxNum = tempMaxNum;
        int i = MAXSTEP;
        int temp = maxNum;
        while (i >= 0) {
            minNum[i] = temp;
            temp >>= 1;
            i--;
        }
    }
}

void MoveLeft(int step) {
    int pj;
    bool merged;
    tempMaxNum = 0; ///
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
                tempMaxNum = max(tempMaxNum, board[step + 1][i][pj]); ///
            } else {
            }
        }
        while (++pj < N) {
            board[step + 1][i][pj] = 0;
        }
    }
    if (tempMaxNum > maxNum) {
        maxNum = tempMaxNum;
        int i = MAXSTEP;
        int temp = maxNum;
        while (i >= 0) {
            minNum[i] = temp;
            temp >>= 1;
            i--;
        }
    }
}

void MoveRight(int step) {
    int pj;
    bool merged;
    tempMaxNum = 0; ///
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
                tempMaxNum = max(tempMaxNum, board[step + 1][i][N - 1 - pj]); ///
            } else {
            }
        }
        while (++pj < N) {
            board[step + 1][i][N - 1 - pj] = 0;
        }
    }
    if (tempMaxNum > maxNum) {
        maxNum = tempMaxNum;
        int i = MAXSTEP;
        int temp = maxNum;
        while (i >= 0) {
            minNum[i] = temp;
            temp >>= 1;
            i--;
        }
    }
}

void DFS(int step) {
    sn++;
    // if (noChange[step]) {
    //     return;
    // }
    // maxNum = max(maxNum, tempMaxNum);
    if (step == MAXSTEP) {
        return;
    }
    // if (tempMaxNum < (maxNum >> (MAXSTEP - step))) {
    //     return;
    // }
    if (tempMaxNum <= minNum[step]) {
        return;
    }
    // if (!noChange[step][0]) {
    //     MoveUp(step, 0);
    //     DFS(step + 1);
    // }
    // if (!noChange[step][1]) {
    //     MoveUp(step, 1); // MoveDown
    //     DFS(step + 1);
    // }
    // if (!noChange[step][2]) {
    //     MoveLeft(step, 0);
    //     DFS(step + 1);
    // }
    // if (!noChange[step][3]) {
    //     MoveLeft(step, 1); // MoveRight
    //     DFS(step + 1);
    // }
    // MoveUp(step, 0);
    // DFS(step + 1);
    // MoveUp(step, 1); // MoveDown
    // DFS(step + 1);
    // MoveLeft(step, 0);
    // DFS(step + 1);
    // MoveLeft(step, 1); // MoveRight
    // DFS(step + 1);

    MoveUp(step);
    noChange[step + 1] = CheckBoard(step);
    // noChange[step + 1] = (tempMaxNum < (maxNum >> (MAXSTEP - step))) ? 1 : noChange[step + 1];
    if (!noChange[step + 1]) {
        DFS(step + 1);
    }
    MoveDown(step); // MoveDown
    noChange[step + 1] = CheckBoard(step);
    if (!noChange[step + 1]) {
        DFS(step + 1);
    }
    MoveLeft(step);
    noChange[step + 1] = CheckBoard(step);
    if (!noChange[step + 1]) {
        DFS(step + 1);
    }
    MoveRight(step); // MoveRight
    noChange[step + 1] = CheckBoard(step);
    if (!noChange[step + 1]) {
        DFS(step + 1);
    }
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
    memset(minNum, -1, sizeof(int) * (MAXSTEP + 1));
    DFS(0);
    cout << maxNum;
    // MoveLeft(0);
    // MoveRight(1);
    return 0;
}