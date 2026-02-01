#include <bits/stdc++.h>
using namespace std;

int h, w, n, r;
char grid[9][9];
int treasureValue[128];
int cost[9][9];
int visited[9][9][512];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w;
}

int bfs(int startX, int startY) {
    queue<tuple<int, int, int, int>> q;
    q.push({startX, startY, 0, 0});
    visited[startX][startY][0] = 1;
    int maxMoney = 0;

    while (!q.empty()) {
        auto [x, y, mask, money] = q.front();
        q.pop();
        maxMoney = max(maxMoney, money);

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!isValid(nx, ny) || visited[nx][ny][mask]) continue;
            char c = grid[nx][ny];
            if (c == '#') continue;
            if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                if (!(mask & (1 << (c - '0')))) {
                    q.push({nx, ny, mask | (1 << (c - '0')), money + treasureValue[c]});
                    visited[nx][ny][mask | (1 << (c - '0'))] = 1;
                } else {
                    q.push({nx, ny, mask, money});
                    visited[nx][ny][mask] = 1;
                }
            } else if (c == '*') {
                q.push({nx, ny, mask, money - r});
                visited[nx][ny][mask] = 1;
            } else {
                q.push({nx, ny, mask, money});
                visited[nx][ny][mask] = 1;
            }
        }
    }
    return maxMoney;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n >> r;
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; ++i) {
        char type;
        int value;
        cin >> type >> value;
        treasureValue[type] = value;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '@') {
                cout << bfs(i, j);
                return 0;
            }
        }
    }
    return 0;
}