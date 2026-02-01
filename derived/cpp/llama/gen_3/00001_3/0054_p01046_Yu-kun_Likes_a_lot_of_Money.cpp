#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 8 * 8 + 10;
const int MAXM = 62 + 10;
const int INF = 1e9;

int h, w, n, r;
char c[8][8];
int m[MAXM], v[MAXM];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int dp[MAXN][MAXM][MAXN];

int id(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 36;
    return -1;
}

int main() {
    cin >> h >> w >> n >> r;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch >> m[i];
        v[i] = id(ch);
    }

    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (c[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, 0, 0});
    dp[sx][sy][0] = 0;

    while (!q.empty()) {
        auto [x, y, mask, cost] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (c[nx][ny] == '#') continue;

            int nmask = mask;
            int ncost = cost;
            if (c[nx][ny] == '*') ncost += r;

            if (c[nx][ny] >= '0' && c[nx][ny] <= '9' || c[nx][ny] >= 'a' && c[nx][ny] <= 'z' || c[nx][ny] >= 'A' && c[nx][ny] <= 'Z') {
                int id = ::id(c[nx][ny]);
                if (!(mask & (1 << id))) {
                    nmask |= (1 << id);
                    for (int j = 0; j < n; j++) {
                        if (v[j] == id) {
                            ncost -= m[j];
                            break;
                        }
                    }
                }
            }

            if (ncost < 0) continue;
            if (dp[nx][ny][nmask] == -1 || dp[nx][ny][nmask] < dp[x][y][mask] - ncost) {
                dp[nx][ny][nmask] = dp[x][y][mask] - ncost;
                q.push({nx, ny, nmask, ncost});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < (1 << n); k++) {
                if (dp[i][j][k]!= -1) {
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}