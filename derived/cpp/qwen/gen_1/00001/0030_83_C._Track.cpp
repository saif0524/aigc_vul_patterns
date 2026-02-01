#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool visited[55][55][17];
char grid[55][55];
int n, m, k;
pair<int, int> start, end;
vector<char> path;

bool isValid(int x, int y, int mask) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y][mask];
}

bool bfs() {
    queue<tuple<int, int, int, vector<char>>> q;
    q.push({start.first, start.second, 0, {}});
    visited[start.first][start.second][0] = true;
    
    while (!q.empty()) {
        auto [x, y, mask, p] = q.front();
        q.pop();
        
        if (x == end.first && y == end.second) {
            path = p;
            return true;
        }
        
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (!isValid(nx, ny, mask)) continue;
            
            if (islower(grid[nx][ny])) {
                int bit = 1 << (grid[nx][ny] - 'a');
                if (__builtin_popcount(mask | bit) > k) continue;
                visited[nx][ny][mask | bit] = true;
                vector<char> np = p;
                np.push_back(grid[nx][ny]);
                q.push({nx, ny, mask | bit, np});
            } else {
                visited[nx][ny][mask] = true;
                q.push({nx, ny, mask, p});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'T') {
                end = {i, j};
            }
        }
    }
    if (bfs()) {
        for (char c : path) {
            cout << c;
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}