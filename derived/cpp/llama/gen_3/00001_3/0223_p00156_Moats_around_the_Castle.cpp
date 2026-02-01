#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        vector<string> grid(m);
        for (int i = 0; i < m; i++) {
            cin >> grid[i];
        }

        int ans = numeric_limits<int>::max();
        vector<Point> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '&') {
                    queue<pair<Point, int>> q;
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    q.push({{i, j}, 0});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [p, count] = q.front();
                        q.pop();

                        if (p.x == 0 || p.x == m - 1 || p.y == 0 || p.y == n - 1) {
                            ans = min(ans, count);
                        }

                        for (auto& dir : directions) {
                            int x = p.x + dir.x;
                            int y = p.y + dir.y;

                            if (x >= 0 && x < m && y >= 0 && y < n &&!visited[x][y]) {
                                if (grid[x][y] == '#') {
                                    q.push({{x, y}, count + 1});
                                } else {
                                    q.push({{x, y}, count});
                                }
                                visited[x][y] = true;
                            }
                        }
                    }
                }
            }
        }

        if (ans == numeric_limits<int>::max()) {
            ans = 0;
        }

        cout << ans << endl;
    }

    return 0;
}