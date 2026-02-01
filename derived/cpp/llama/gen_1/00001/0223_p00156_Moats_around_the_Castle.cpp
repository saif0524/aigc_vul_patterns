#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y;
};

bool isValidMove(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] != '#';
}

void bfs(vector<vector<char>>& grid, Point start, vector<vector<bool>>& visited, int& count) {
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (grid[current.x][current.y] == '&') {
            count++;
            while (!q.empty()) q.pop();
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValidMove(grid, newX, newY, visited)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        vector<vector<char>> grid(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '.') {
                    bfs(grid, {i, j}, visited, count);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}