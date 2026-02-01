#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char dir[4] = {'L', 'R', 'U', 'D'};

pair<int, int> dfs(vector<vector<char>>& grid, int x, int y, vector<vector<int>>& visited) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 1;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (grid[x][y] == dir[i]) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (grid[nx][ny] != '.') {
                    break;
                }
                nx += dx[i];
                ny += dy[i];
            }
            if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] != '.') {
                if (!visited[nx][ny]) {
                    ans += dfs(grid, nx, ny, visited).first;
                }
            }
        }
    }
    return {ans, 0};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.') {
                vector<vector<int>> visited(n, vector<int>(m, 0));
                pair<int, int> ans = dfs(grid, i, j, visited);
                mp[ans.first]++;
            }
        }
    }
    pair<int, int> res = {0, 0};
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        res = {it->first, it->second};
        break;
    }
    cout << res.first << " " << res.second << endl;
    return 0;
}