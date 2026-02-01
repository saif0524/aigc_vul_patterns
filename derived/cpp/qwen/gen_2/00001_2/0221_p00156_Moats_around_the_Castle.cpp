#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[105][105];
int visited[105][105];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
pair<int, int> tower;

bool isValid(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#' && !visited[x][y];
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        if (cx == tower.first && cy == tower.second) return;
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (isValid(nx, ny)) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m && n && m) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == '&') {
                    tower = {i, j};
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '.' && !visited[i][j]) {
                    bfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}