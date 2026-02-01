#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, k;

void dfs(vector<string>& grid, vector<vector<bool>>& visited, int x, int y) {
    if (visited[x][y] || grid[x][y] == '#') return;
    visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            dfs(grid, visited, nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<string> grid(n);
    for (auto& row : grid) cin >> row;

    vector<pair<int, int>> cells;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') {
                cells.emplace_back(i, j);
            }
        }
    }

    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(grid, visited, cells[0].first, cells[0].second);

    for (int i = 0; i < n && count < k; ++i) {
        for (int j = 0; j < m && count < k; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                grid[i][j] = 'X';
                ++count;
            }
        }
    }

    vector<bool> to_mark(k, false);
    random_shuffle(cells.begin(), cells.end());
    for (int i = 0; i < k && count > 0; ++i) {
        int x = cells[i].first;
        int y = cells[i].second;
        if (grid[x][y] == '.') {
            grid[x][y] = 'X';
            ++count;
        }
        visited.assign(n, vector<bool>(m, false));
        dfs(grid, visited, cells[0].first, cells[0].second);
        bool all_reachable = true;
        for (const auto& [cx, cy] : cells) {
            if (grid[cx][cy] == '.' && !visited[cx][cy]) {
                all_reachable = false;
                break;
            }
        }
        if (!all_reachable) {
            grid[x][y] = '.';
            --count;
        }
    }

    for (const auto& row : grid) {
        cout << row << '\n';
    }

    return 0;
}