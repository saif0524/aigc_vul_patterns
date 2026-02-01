#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> maze(n);
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                dist[i][j] = 0;
                q.push({i, j});
                break;
            }
        }
        if (q.size()) break;
    }

    vector<pair<int, int>> order;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        order.push_back({x, y});
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = order.size() - 1; i >= 0 && k > 0; i--) {
        int x = order[i].first;
        int y = order[i].second;
        maze[x][y] = 'X';
        k--;
    }

    for (int i = 0; i < n; i++) {
        cout << maze[i] << endl;
    }

    return 0;
}