#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Point {
    int x, y, k, step;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k;
    cin >> h >> w >> k;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
                break;
            }
        }
    }

    queue<Point> q;
    q.push({sx, sy, k, 0});

    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
    visited[sx][sy][k] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == 0 || p.x == h - 1 || p.y == 0 || p.y == w - 1) {
            cout << p.step << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (grid[nx][ny] == '.') {
                if (!visited[nx][ny][p.k]) {
                    q.push({nx, ny, p.k, p.step + (p.k == k ? 0 : 1)});
                    visited[nx][ny][p.k] = true;
                }
            } else if (p.k > 0) {
                if (!visited[nx][ny][p.k - 1]) {
                    q.push({nx, ny, p.k - 1, p.step + 1});
                    visited[nx][ny][p.k - 1] = true;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (grid[nx][ny] == '.') {
                for (int j = 1; j <= p.k; j++) {
                    int nnx = nx + dx[i] * j;
                    int nny = ny + dy[i] * j;

                    if (nnx < 0 || nnx >= h || nny < 0 || nny >= w) break;
                    if (grid[nnx][nny] == '.') {
                        if (!visited[nnx][nny][p.k - j]) {
                            q.push({nnx, nny, p.k - j, p.step + 1});
                            visited[nnx][nny][p.k - j] = true;
                        }
                    } else if (j < p.k) {
                        if (!visited[nnx][nny][p.k - j - 1]) {
                            q.push({nnx, nny, p.k - j - 1, p.step + 1});
                            visited[nnx][nny][p.k - j - 1] = true;
                        }
                    }
                }
            }
        }
    }

    return 0;
}