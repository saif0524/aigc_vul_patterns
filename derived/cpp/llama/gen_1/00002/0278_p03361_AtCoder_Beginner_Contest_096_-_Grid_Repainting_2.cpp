#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || visited[r][c] || grid[r][c] == '.') {
        return;
    }
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        dfs(grid, visited, r + DIR[i][0], c + DIR[i][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    bool connected = false;
    vector<vector<bool>> visited(H, vector<bool>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                if (connected) {
                    cout << "No\n";
                    return 0;
                }
                connected = true;
                dfs(grid, visited, i, j);
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";

    return 0;
}