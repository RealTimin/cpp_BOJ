// #include <bits/stdc++.h>

// #define REP(i, a, b) for (int i = (a); i < (b); i++)

// using namespace std;

// typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;

// int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// void findPos(vvi &pos, vvi &box)
// {
//     int ROW = box.size();
//     int COL = box[0].size();
//     int checkR, checkC;
//     REP(row, 0, ROW)
//     {
//         REP(col, 0, COL)
//         {
//             if (box[row][col] == 1) // ripen tomato
//             {
//                 REP(d, 0, 4)
//                 {
//                     checkR = row + D[d][0];
//                     checkC = col + D[d][1];
//                     // if adjacent tomato is ripen
//                     if (checkR >= 0 && checkR < ROW && checkC >= 0 && checkC < COL && box[checkR][checkC] == 0)
//                     {
//                         pos[checkR][checkC] = 1;
//                     }
//                 }
//             }
//         }
//     }
//     return;
// }

// void fillBox(vvi &pos, vvi &box)
// {
//     int ROW = box.size();
//     int COL = box[0].size();
//     int checkR, checkC;
//     REP(row, 0, ROW)
//     {
//         REP(col, 0, COL)
//         {
//             if (pos[row][col] == 1) // about-to-ripe tomato
//             {
//                 box[row][col] = 1;
//                 pos[row][col] = 0;
//             }
//         }
//     }
//     return;
// }

// bool checkPos(vvi &pos) // no change, return false
// {
//     int ROW = pos.size();
//     int COL = pos[0].size();
//     bool mustChange = false;
//     REP(r, 0, ROW)
//     {
//         REP(c, 0, COL)
//         {
//             if (pos[r][c] == 1)
//             {
//                 mustChange = true;
//                 break;
//             }
//         }
//     }

//     return mustChange;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     // TODO: time complexity n^4 -> n^3
//     int ROW, COL;
//     cin >> COL >> ROW;
//     vvi box;
//     vvi pos; // tomato position that is about to ripe
//     int num;
//     int day = 0;
//     REP(i, 0, ROW)
//     {
//         vi box_row;
//         REP(j, 0, COL)
//         {
//             cin >> num;
//             box_row.push_back(num);
//         }
//         box.push_back(box_row);
//         pos.push_back(vi(COL, 0));
//     }

//     findPos(pos, box);
//     while (checkPos(pos))
//     {
//         day++;
//         fillBox(pos, box);
//         findPos(pos, box);
//     }

//     if (checkTomato(box))
//     {
//         // all ripen
//         cout << day;
//     }
//     else
//     {
//         cout << -1;
//     }

//     return 0;
// }

#include <bits/stdc++.h>

// URL: https://www.acmicpc.net/problem/7576

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define endl '\n'
#define MAX_NUM 200000
#define MIN_NUM 0
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool checkTomato(vvi &box)
{
    int ROW = box.size();
    int COL = box[0].size();
    bool allRipenTomato = true;
    REP(r, 0, ROW)
    {
        REP(c, 0, COL)
        {
            if (box[r][c] == 0)
            {
                allRipenTomato = false;
                break;
            }
        }
    }

    return allRipenTomato;
}
// void printBox(vvi &box)
// {
//     int ROW = box.size();
//     int COL = box[0].size();
//     REP(r, 0, ROW)
//     {
//         REP(c, 0, COL)
//         {
//             cout << box[r][c] << ' ';
//         }
//         cout << endl;
//     }
//     return;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout.setf(ios::fixed);
    // cout.precision(3);
    int size;
    int ROW, COL;
    cin >> COL >> ROW;
    vvi box;
    queue<pii> newTomatoPos;
    int num;
    int day = -1;
    int r, c, new_row, new_col;
    bool increaseDay;
    REP(i, 0, ROW)
    {
        vi box_row;
        REP(j, 0, COL)
        {
            cin >> num;
            if (num == 1)
            {
                newTomatoPos.push({i, j});
                num = 0;
            }
            box_row.push_back(num);
        }
        box.push_back(box_row);
    }

    while (!newTomatoPos.empty())
    {
        increaseDay = false;
        size = newTomatoPos.size();
        REP(i, 0, size)
        {
            r = newTomatoPos.front().first;
            c = newTomatoPos.front().second;
            if (box[r][c] == 1)
            {
                newTomatoPos.pop();
                continue;
            }
            box[r][c] = 1;
            increaseDay = true;
            REP(d, 0, 4)
            {
                new_row = r + D[d][0];
                new_col = c + D[d][1];
                // clip
                if (new_row < 0)
                    new_row = 0;
                else if (new_row >= ROW)
                    new_row = ROW - 1;
                if (new_col < 0)
                    new_col = 0;
                else if (new_col >= COL)
                    new_col = COL - 1;

                if (box[new_row][new_col] == 0)
                    newTomatoPos.push({new_row, new_col});
            }
            newTomatoPos.pop();
        }
        if (increaseDay)
            day++;
    }

    // check unripen tomato
    if (checkTomato(box))
    {
        cout << day;
    }
    else
    {
        cout << -1;
    }

    return 0;
}