#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool hasPath(vector<vector<char>>& grid, int n, int d) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, n) && !visited[nx][ny]) {
                if (grid[nx][ny] == d || grid[nx][ny] == 'S' || grid[nx][ny] == 'F') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    if (!hasPath(grid, n, '0') || !hasPath(grid, n, '1')) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == '0') {
                grid[i][j] = '1';
                if (!hasPath(grid, n, '0') || !hasPath(grid, n, '1')) {
                    cout << "1\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
                grid[i][j] = '0';
            }
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                if (!hasPath(grid, n, '0') || !hasPath(grid, n, '1')) {
                    cout << "1\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return;
                }
                grid[i][j] = '1';
            }
        }
    }

    cout << "2\n";
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (grid[i][j] == '0') {
                grid[i][j] = '1';
                for (int k = 1; k < n - 1; k++) {
                    for (int l = 1; l < n - 1; l++) {
                        if (grid[k][l] == '1') {
                            grid[k][l] = '0';
                            if (!hasPath(grid, n, '0') || !hasPath(grid, n, '1')) {
                                cout << i + 1 << " " << j + 1 << "\n";
                                cout << k + 1 << " " << l + 1 << "\n";
                                return;
                            }
                            grid[k][l] = '1';
                        }
                    }
                }
                grid[i][j] = '0';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}