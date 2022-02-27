// URL: https://www.acmicpc.net/problem/13460
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'

char board[10][10];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, M;
bool success = false;
int moveCount;
int minCount = 100;
pii opos;
vi moveLog;
vi result;

// int stackSize;
void DFS(int prevDir, const pii rpos, const pii bpos);

pii BallMove(int direction, pii ballPos) {
    int i = ballPos.first;
    int j = ballPos.second;
    int ni = i + D[direction][0];
    int nj = j + D[direction][1];
    char ball = board[i][j];
    bool stopped = false;
    if (ball == 'O')
        return {i, j};
    board[ballPos.first][ballPos.second] = '.';
    while (!stopped) {
        if (board[ni][nj] == '.') {
            board[i][j] = '.';
            i = ni;
            j = nj;
            ni = i + D[direction][0];
            nj = j + D[direction][1];
        } else if (board[ni][nj] == 'O') {
            i = ni;
            j = nj;
            stopped = true;
        } else {
            board[i][j] = ball;
            stopped = true;
        }
    }
    return {i, j};
}

void MakeMove(int curDir, const pii rpos, const pii bpos) {
    pii nrpos, nbpos;
    moveLog.push_back(curDir);
    nrpos = BallMove(curDir, rpos);
    nbpos = BallMove(curDir, bpos);
    nrpos = BallMove(curDir, nrpos);
    if (nbpos != opos)
        DFS(curDir, nrpos, nbpos);
    moveLog.pop_back();
    board[nrpos.first][nrpos.second] = (board[nrpos.first][nrpos.second] == 'R'
                                            ? '.'
                                            : board[nrpos.first][nrpos.second]);
    board[nbpos.first][nbpos.second] = (board[nbpos.first][nbpos.second] == 'B'
                                            ? '.'
                                            : board[nbpos.first][nbpos.second]);
    board[rpos.first][rpos.second] = 'R';
    board[bpos.first][bpos.second] = 'B';
}

void DFS(int prevDir, const pii rpos, const pii bpos) {
    // 0:up, 1:down, 2:left, 3:right
    // stackSize++;
    moveCount++;
    if (rpos == opos) {
        success = true;
        moveCount--;
        if (moveCount < minCount) {
            minCount = moveCount;
            result = moveLog;
        }
        return;
    }
    if (moveCount > 10) {
        moveCount--;
        return;
    }
    if (prevDir != 0 && prevDir != 1) {
        MakeMove(0, rpos, bpos);
        MakeMove(1, rpos, bpos);
    }
    if (prevDir != 2 && prevDir != 3) {
        MakeMove(2, rpos, bpos);
        MakeMove(3, rpos, bpos);
    }

    moveCount--;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    cin >> N >> M;
    pii rpos, bpos;
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                rpos = {i, j};
            else if (board[i][j] == 'B')
                bpos = {i, j};
            else if (board[i][j] == 'O')
                opos = {i, j};
        }
    }

    DFS(-1, rpos, bpos);
    if (minCount > 10)
        cout << -1;
    else {
        cout << minCount << endl;
        REP(i, 0, minCount) {
            switch (result[i]) {
            case 0:
                cout << 'U';
                break;
            case 1:
                cout << 'D';
                break;
            case 2:
                cout << 'L';
                break;
            case 3:
                cout << 'R';
                break;
            default:
                break;
            }
        }
    }

    return 0;
}