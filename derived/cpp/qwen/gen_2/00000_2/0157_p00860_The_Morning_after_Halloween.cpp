#include <bits/stdc++.h>
using namespace std;

int w, h, n;
char grid[17][17];
int target[3];
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
bool visited[17][17];

pair<int, int> get_pos(char c) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == c) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool valid(int x, int y) {
    return x >= 0 && x < h && y >= 0 && y < w && grid[x][y] != '#' && !visited[x][y];
}

int bfs(pair<int, int> start, int end_pos) {
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        auto [cur, d] = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        
        if (grid[x][y] == end_pos) {
            return d;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (valid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({{nx, ny}, d + 1});
            }
        }
    }
    return -1;
}

int dp(int mask, int pos[3]) {
    if (mask == (1 << n) - 1) {
        return 0;
    }
    int res = 1e9;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            memset(visited, false, sizeof(visited));
            int steps = bfs({pos[i] / w, pos[i] % w}, 'A' + i);
            res = min(res, steps + dp(mask | (1 << i), pos));
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> w >> h >> n) {
        if (w == 0 && h == 0 && n == 0) break;
        for (int i = 0; i < h; i++) {
            cin >> grid[i];
            for (int j = 0; j < w; j++) {
                if (grid[i][j] >= 'A' && grid[i][j] <= 'C') {
                    target[grid[i][j] - 'A'] = i * w + j;
                }
            }
        }
        int pos[3];
        for (int i = 0; i < n; i++) {
            auto [x, y] = get_pos('a' + i);
            pos[i] = x * w + y;
        }
        cout << dp(0, pos) << "\n";
    }
}