#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                dist[i][j] = 0;
                q.push({i, j});
                break;
            }
        }
        if (q.size()) break;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#' || dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    vector<pair<int, pair<int, int>>> cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dist[i][j] != -1) {
                cells.push_back({dist[i][j], {i, j}});
            }
        }
    }

    sort(cells.rbegin(), cells.rend());

    for (int i = 0; i < k; ++i) {
        auto [x, y] = cells[i].second;
        grid[x][y] = 'X';
    }

    for (const auto &row : grid) {
        cout << row << '\n';
    }

    return 0;
}