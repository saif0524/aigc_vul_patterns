#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define INF 1000000000

using namespace std;

vector<vector<int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int r, c, n;
vector<pair<int, int>> queries;
vector<vector<bool>> marked;

bool valid(int x, int y) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool bfs() {
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < c; i++) {
        if (!marked[0][i]) {
            q.push({0, i});
            visited[0][i] = true;
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto &[dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (nx == r) return true;
            if (nx < 0 || !valid(nx, ny) || marked[nx][ny] || visited[nx][ny]) continue;
            if (nx == x && (y == 0 || y == c - 1)) {
                if (ny == 0 || ny == c - 1) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            } else {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return false;
}

int main() {
    cin >> r >> c >> n;
    queries.resize(n);
    marked.resize(r, vector<bool>(c, false));
    for (int i = 0; i < n; i++) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--, queries[i].second--;
    }
    int ans = 0;
    for (auto &[x, y] : queries) {
        if (!bfs()) {
            marked[x][y] = true;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}