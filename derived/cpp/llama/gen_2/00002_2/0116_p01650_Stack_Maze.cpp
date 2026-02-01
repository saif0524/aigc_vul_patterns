#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 55;
const int MAXM = 55;
const int INF = 1e9;

int h, w;
char grid[MAXN][MAXM];
int dp[MAXN][MAXM][26][26];

int solve() {
    memset(dp, -1, sizeof(dp));
    dp[1][1][0][0] = 0;
    queue<tuple<int, int, int, int>> q;
    q.push({1, 1, 0, 0});
    while (!q.empty()) {
        auto [x, y, top, cnt] = q.front();
        q.pop();
        if (x == h && y == w) {
            return dp[x][y][top][cnt];
        }
        for (auto [dx, dy] : vector<pair<int, int>>{{0, 1}, {1, 0}}) {
            int nx = x + dx, ny = y + dy;
            if (nx <= h && ny <= w && grid[nx][ny]!= '#') {
                if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z') {
                    int nt = top;
                    if (nt == 0 || grid[nx][ny] == top + 'a') {
                        nt = grid[nx][ny] - 'a';
                    } else {
                        continue;
                    }
                    if (dp[nx][ny][nt][cnt] == -1) {
                        dp[nx][ny][nt][cnt] = dp[x][y][top][cnt];
                        q.push({nx, ny, nt, cnt});
                    }
                } else if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z') {
                    int nt = top;
                    if (nt == 0 || grid[nx][ny] == top + 'A') {
                        nt = 0;
                        if (dp[nx][ny][nt][cnt + 1] == -1) {
                            dp[nx][ny][nt][cnt + 1] = dp[x][y][top][cnt] + 1;
                            q.push({nx, ny, nt, cnt + 1});
                        }
                    } else {
                        continue;
                    }
                } else {
                    int nt = top;
                    if (dp[nx][ny][nt][cnt] == -1) {
                        dp[nx][ny][nt][cnt] = dp[x][y][top][cnt];
                        q.push({nx, ny, nt, cnt});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) {
            break;
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> grid[i][j];
            }
        }
        cout << solve() << '\n';
    }
    return 0;
}