#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct Block {
    int x1, y1, x2, y2, color;
};

bool inBounds(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int findBlock(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    if (visited[x][y]) return -1;
    int color = grid[x][y];
    visited[x][y] = true;
    int x1 = x, y1 = y, x2 = x, y2 = y;
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        x1 = min(x1, cx);
        y1 = min(y1, cy);
        x2 = max(x2, cx);
        y2 = max(y2, cy);
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if (inBounds(nx, ny, grid.size(), grid[0].size()) && grid[nx][ny] == color && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return color;
}

vector<Block> getBlocks(vector<vector<int>>& grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    vector<Block> blocks;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != 0 && !visited[i][j]) {
                int color = findBlock(i, j, grid, visited);
                int x1 = i, y1 = j, x2 = i, y2 = j;
                for (int a = 0; a < grid.size(); a++) {
                    for (int b = 0; b < grid[a].size(); b++) {
                        if (grid[a][b] == color) {
                            x1 = min(x1, a);
                            y1 = min(y1, b);
                            x2 = max(x2, a);
                            y2 = max(y2, b);
                        }
                    }
                }
                blocks.push_back({x1, y1, x2, y2, color});
            }
        }
    }
    return blocks;
}

Block getInitBlock(const vector<vector<int>>& grid, const vector<Block>& blocks) {
    for (const auto& block : blocks) {
        if (block.x1 == 0 && block.y1 == 0) {
            return block;
        }
    }
    return blocks[0];
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    vector<Block> blocks = getBlocks(grid);
    Block bp = getInitBlock(grid, blocks);
    int dp = 0; // right
    int cp = 3; // left

    while (n > 0) {
        int nx = bp.x1 + dx[dp];
        int ny = bp.y1 + dy[dp];
        int targetColor = -1;

        if (inBounds(nx, ny, m, n) && grid[nx][ny] != 0) {
            targetColor = grid[nx][ny];
        }

        if (targetColor != -1) {
            for (auto& block : blocks) {
                if (block.color == targetColor) {
                    bp = block;
                    break;
                }
            }
        } else {
            cp = dp;
            dp = (dp + 1) % 4;
        }

        n--;
    }

    cout << bp.color;
    return 0;
}