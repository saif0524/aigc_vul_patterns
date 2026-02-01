#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool visited[55][55];

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    stack<pair<int, int>> s;
    s.push({x, y});

    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        int i = p.first;
        int j = p.second;

        if (visited[i][j]) continue;
        visited[i][j] = true;

        if (grid[i][j] == '#') {
            if (valid(i - 1, j, n, m) && grid[i - 1][j] == '#') s.push({i - 1, j});
            if (valid(i + 1, j, n, m) && grid[i + 1][j] == '#') s.push({i + 1, j});
            if (valid(i, j - 1, n, m) && grid[i][j - 1] == '#') s.push({i, j - 1});
            if (valid(i, j + 1, n, m) && grid[i][j + 1] == '#') s.push({i, j + 1});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                dfs(i, j, grid);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";

    return 0;
}