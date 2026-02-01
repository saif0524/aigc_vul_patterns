#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(m));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    int bx = 0, by = 0, bp = grid[0][0];
    int dp = 1;
    int cp = 0;
    for(int s = 0; s < n; ++s) {
        int ex = bx, ey = by;
        for(int i = 0; i < m; ++i) {
            int nx = bx + dx[dp] * i;
            int ny = by + dy[dp] * i;
            if(nx < 0 || nx >= m || ny < 0 || ny >= m || grid[nx][ny] != bp) break;
            ex = nx;
            ey = ny;
        }
        int px = ex + dx[cp];
        int py = ey + dy[cp];
        if(px >= 0 && px < m && py >= 0 && py < m && grid[px][py] != 0) {
            bx = px;
            by = py;
            bp = grid[bx][by];
        } else {
            cp = cp == 0 ? 2 : 0;
            if(cp == 0) {
                dp = (dp + 1) % 4;
            }
        }
    }
    cout << bp;
    return 0;
}