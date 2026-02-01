#include <iostream>
#include <vector>
#include <string>
#include <queue>

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

using namespace std;

bool isValid(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool bfs(vector<vector<char>>& grid, int n, bool zero) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == n - 1) return true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, n) && !visited[nx][ny]) {
                if ((grid[nx][ny] == '0' && zero) || (grid[nx][ny] == '1' && !zero) || (nx == n - 1 && ny == n - 1)) {
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
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = s[j];
        }
    }

    bool zero = bfs(grid, n, true);
    bool one = bfs(grid, n, false);

    if (!zero && !one) {
        cout << 0 << "\n";
        return;
    }

    if (!zero) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    grid[i][j] = '1';
                    if (!bfs(grid, n, true) && !bfs(grid, n, false)) {
                        cout << 1 << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        return;
                    }
                    grid[i][j] = '0';
                }
            }
        }
    }

    if (!one) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (!bfs(grid, n, true) && !bfs(grid, n, false)) {
                        cout << 1 << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        return;
                    }
                    grid[i][j] = '1';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '0') {
                grid[i][j] = '1';
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (grid[x][y] == '1') {
                            grid[x][y] = '0';
                            if (!bfs(grid, n, true) && !bfs(grid, n, false)) {
                                cout << 2 << "\n";
                                cout << i + 1 << " " << j + 1 << "\n";
                                cout << x + 1 << " " << y + 1 << "\n";
                                return;
                            }
                            grid[x][y] = '1';
                        }
                    }
                }
                grid[i][j] = '0';
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        if (grid[x][y] == '0') {
                            grid[x][y] = '1';
                            if (!bfs(grid, n, true) && !bfs(grid, n, false)) {
                                cout << 2 << "\n";
                                cout << i + 1 << " " << j + 1 << "\n";
                                cout << x + 1 << " " << y + 1 << "\n";
                                return;
                            }
                            grid[x][y] = '0';
                        }
                    }
                }
                grid[i][j] = '1';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}