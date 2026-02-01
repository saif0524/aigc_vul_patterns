#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int n, int m, vector<string>& map, int sx, int sy) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<int>> d(m, vector<int>(n, 0));

    q.push({sx, sy});
    visited[sy][sx] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[y][x] == '&') {
            cout << d[y][x] << endl;
            return;
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[ny][nx]) {
                continue;
            }

            if (map[ny][nx] == '#') {
                d[ny][nx] = d[y][x] + 1;
            } else {
                d[ny][nx] = d[y][x];
            }

            visited[ny][nx] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        vector<string> map(m);
        for (int i = 0; i < m; i++) {
            cin >> map[i];
        }

        int sx = -1, sy = -1;
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                if (map[y][x] == '#') {
                    continue;
                }
                if (sx == -1) {
                    sx = x;
                    sy = y;
                }
            }
        }

        bfs(n, m, map, sx, sy);
    }

    return 0;
}