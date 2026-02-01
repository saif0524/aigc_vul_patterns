#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 16;
const int MAX_M = 16;
const int MAX_K = 3;

int w, h, n;
char grid[MAX_N][MAX_M];
bool visited[1 << MAX_K][MAX_N][MAX_M];
int distance[1 << MAX_K][MAX_N][MAX_M];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<tuple<int, int, int>> q;

void bfs(int mask, int x, int y) {
    visited[mask][x][y] = true;
    distance[mask][x][y] = 0;
    q.push({mask, x, y});

    while (!q.empty()) {
        auto [mask, x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] != '#') {
                int nmask = mask;
                bool ok = true;

                for (int i = 0; i < n; ++i) {
                    if (nx == grid[i][0] - 'a' && ny == grid[i][1] - 'a') {
                        nmask ^= (1 << i);
                        ok = false;
                    }
                }

                if (!visited[nmask][nx][ny] && ok) {
                    visited[nmask][nx][ny] = true;
                    distance[nmask][nx][ny] = distance[mask][x][y] + 1;
                    q.push({nmask, nx, ny});
                }
            }
        }
    }
}

int main() {
    while (true) {
        cin >> w >> h >> n;

        if (w == 0 && h == 0 && n == 0) {
            break;
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }

        memset(visited, false, sizeof(visited));
        memset(distance, 0x3f, sizeof(distance));

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (islower(grid[i][j])) {
                    int mask = 0;
                    for (int k = 0; k < n; ++k) {
                        if (grid[i][j] == 'a' + k) {
                            mask |= (1 << k);
                            grid[k][0] = 'a' + k;
                            grid[k][1] = i;
                        }
                    }

                    bfs(mask, i, j);
                }
            }
        }

        int ans = 1e9;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (isupper(grid[i][j])) {
                    int mask = 0;
                    for (int k = 0; k < n; ++k) {
                        if (grid[i][j] == 'A' + k) {
                            mask |= (1 << k);
                            grid[k][2] = 'A' + k;
                            grid[k][3] = i;
                        }
                    }

                    ans = min(ans, distance[mask][i][j]);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}