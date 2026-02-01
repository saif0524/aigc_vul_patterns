#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100;
const int MAX_W = 100;
const int MAX_H = 100;
const int MAX_STACK_SIZE = 50;
const int INF = 1e9;

int h, w;
char grid[MAX_N][MAX_M];
int dx[] = {1, 0};
int dy[] = {0, 1};
int dp[MAX_N][MAX_M][MAX_STACK_SIZE];

void reset_dp() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < MAX_STACK_SIZE; k++) {
                dp[i][j][k] = -INF;
            }
        }
    }
}

int solve(int x, int y, int stack) {
    if (x >= h || y >= w) {
        return -INF;
    }
    if (x == h - 1 && y == w - 1) {
        return 0;
    }
    if (dp[x][y][stack]!= -INF) {
        return dp[x][y][stack];
    }
    int ans = -INF;
    for (int i = 0; i < 2; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < h && ny < w && grid[nx][ny]!= '#') {
            if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                if (stack == grid[nx][ny] - 'a') {
                    ans = max(ans, solve(nx, ny, stack) + 1);
                } else if (stack < MAX_STACK_SIZE - 1) {
                    ans = max(ans, solve(nx, ny, stack + 1));
                }
            } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                if (stack > 0 && stack - 1 == grid[nx][ny] - 'A') {
                    ans = max(ans, solve(nx, ny, stack - 1) + 1);
                } else {
                    ans = max(ans, solve(nx, ny, stack));
                }
            } else {
                ans = max(ans, solve(nx, ny, stack));
            }
        }
    }
    return dp[x][y][stack] = ans;
}

int main() {
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        reset_dp();
        int ans = solve(0, 0, 0);
        if (ans == -INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}