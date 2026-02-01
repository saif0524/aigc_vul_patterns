#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <climits>

using namespace std;

const int INF = INT_MAX / 2;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    cin >> w >> h;
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> scores(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> scores[i][j];
        }
    }

    int sx, sy, tx, ty;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'S') {
                sx = j;
                sy = i;
            } else if (grid[i][j] == 'T') {
                tx = j;
                ty = i;
            }
        }
    }

    vector<int> itemX(10), itemY(10);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] >= '0' && grid[i][j] <= '9') {
                int num = grid[i][j] - '0';
                itemX[num] = j;
                itemY[num] = i;
            }
        }
    }

    vector<vector<vector<int>>> dist(w, vector<vector<int>>(h, vector<int>(1 << 10, INF)));
    vector<vector<vector<int>>> score(w, vector<vector<int>>(h, vector<int>(1 << 10, -INF)));
    queue<tuple<int, int, int, int, int>> q;

    auto update = [&](int x, int y, int mask, int d, int s) {
        if (dist[x][y][mask] <= d) return;
        dist[x][y][mask] = d;
        score[x][y][mask] = s;
        q.emplace(x, y, mask, d, s);
    };

    update(sx, sy, 0, 0, 0);
    while (!q.empty()) {
        int x, y, mask, d, s;
        tie(x, y, mask, d, s) = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (grid[ny][nx] == '#') continue;

            int nmask = mask;
            int ns = s;
            if (grid[ny][nx] >= '0' && grid[ny][nx] <= '9') {
                int num = grid[ny][nx] - '0';
                if (!(mask & (1 << num))) {
                    nmask |= 1 << num;
                    if (mask == 0) ns += scores[10][num];
                    else ns += scores[__builtin_ctz(mask)][num];
                }
            }
            if (grid[ny][nx] >= 'A' && grid[ny][nx] <= 'J') {
                int num = grid[ny][nx] - 'A';
                if (mask & (1 << num)) continue;
            }
            if (grid[ny][nx] >= 'a' && grid[ny][nx] <= 'j') {
                int num = grid[ny][nx] - 'a';
                if (!(mask & (1 << num))) continue;
            }

            update(nx, ny, nmask, d + 1, ns);
        }
    }

    int mind = INF;
    int maxs = -INF;
    for (int mask = 0; mask < (1 << 10); mask++) {
        if (__builtin_popcount(mask) != 10) continue;
        if (dist[tx][ty][mask] < mind) {
            mind = dist[tx][ty][mask];
            maxs = score[tx][ty][mask];
        } else if (dist[tx][ty][mask] == mind) {
            maxs = max(maxs, score[tx][ty][mask]);
        }
    }

    if (mind == INF) {
        cout << "-1\n";
    } else {
        cout << mind << " " << maxs << "\n";
    }

    return 0;
}