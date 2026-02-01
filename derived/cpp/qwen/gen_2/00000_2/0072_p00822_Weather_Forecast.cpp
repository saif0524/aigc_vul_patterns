#include <bits/stdc++.h>
using namespace std;

const int MAXD = 366;
const int MAXN = 4;
const int DIRS = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

int n;
vector<vector<int>> schedule;

bool canRain(int day, int x, int y) {
    if (day == 0) return (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 1) || (x == 2 && y == 2);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int nx = x + i, ny = y + j;
            if (schedule[day][nx * MAXN + ny]) return true;
        }
    }
    return false;
}

bool solve() {
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(MAXN, vector<bool>(MAXN, false)));
    for (int x = 0; x < MAXN - 1; ++x) {
        for (int y = 0; y < MAXN - 1; ++y) {
            dp[0][x][y] = canRain(0, x, y);
        }
    }
    for (int day = 1; day < n; ++day) {
        for (int x = 0; x < MAXN - 1; ++x) {
            for (int y = 0; y < MAXN - 1; ++y) {
                dp[day][x][y] = false;
                if (dp[day - 1][x][y]) dp[day][x][y] = canRain(day, x, y);
                for (int dir = 0; dir < DIRS; ++dir) {
                    int nx = x + DX[dir];
                    int ny = y + DY[dir];
                    if (nx >= 0 && nx < MAXN - 1 && ny >= 0 && ny < MAXN - 1 && dp[day - 1][nx][ny]) {
                        dp[day][x][y] = dp[day][x][y] || canRain(day, x, y);
                    }
                }
            }
        }
    }
    int maxConsecutive = 0;
    for (int x = 0; x < MAXN - 1; ++x) {
        for (int y = 0; y < MAXN - 1; ++y) {
            int consecutive = 0;
            for (int day = 0; day < n; ++day) {
                if (dp[day][x][y]) {
                    consecutive = 0;
                } else {
                    consecutive++;
                    if (consecutive > 6) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        if (n == 0) break;
        schedule.resize(n, vector<int>(MAXN * MAXN));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < MAXN * MAXN; ++j) {
                cin >> schedule[i][j];
            }
        }
        cout << (solve() ? 1 : 0) << "\n";
    }
}