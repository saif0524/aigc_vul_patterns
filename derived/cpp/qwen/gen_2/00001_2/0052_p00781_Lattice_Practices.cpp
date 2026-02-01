#include <bits/stdc++.h>
using namespace std;

int n = 10;
int m = 5;
vector<string> boards;
vector<bool> used;
vector<vector<int>> rotations;
vector<pair<int, int>> positions = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 0}, {1, 3}, {2, 0}, {2, 3}, {3, 0}, {3, 1}, {3, 2}, {3, 3}};
int count = 0;

bool check(int board, int x, int y, vector<vector<bool>>& grid) {
    int rot = 0;
    for (int r = 0; r < 4; ++r) {
        bool valid = true;
        for (int i = 0; i < m; ++i) {
            int nx = x + (rotations[r][i] / m), ny = y + (rotations[r][i] % m);
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) valid = false;
            if (valid && boards[board][i] == '1' && grid[nx][ny]) valid = false;
        }
        if (valid) {
            for (int i = 0; i < m; ++i) {
                int nx = x + (rotations[r][i] / m), ny = y + (rotations[r][i] % m);
                if (boards[board][i] == '1') grid[nx][ny] = true;
            }
            return true;
        }
        rot = (rot + 1) % 4;
    }
    return false;
}

void backtrack(int idx, vector<vector<bool>>& grid) {
    if (idx == positions.size()) {
        count++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int x = positions[idx].first, y = positions[idx].second;
        for (int r = 0; r < 4; ++r) {
            bool valid = true;
            for (int k = 0; k < m; ++k) {
                int nx = x + (rotations[r][k] / m), ny = y + (rotations[r][k] % m);
                if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
                    valid = false;
                    break;
                }
                if (boards[i][k] == '1' && grid[nx][ny]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                used[i] = true;
                for (int k = 0; k < m; ++k) {
                    int nx = x + (rotations[r][k] / m), ny = y + (rotations[r][k] % m);
                    if (boards[i][k] == '1') grid[nx][ny] = true;
                }
                backtrack(idx + 1, grid);
                for (int k = 0; k < m; ++k) {
                    int nx = x + (rotations[r][k] / m), ny = y + (rotations[r][k] % m);
                    if (boards[i][k] == '1') grid[nx][ny] = false;
                }
                used[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    rotations = {{0, 1, 2, 3, 4}, {0, 4, 8, 12, 16}, {4, 3, 2, 1, 0}, {16, 12, 8, 4, 0}};
    while true {
        string line;
        getline(cin, line);
        if (line == "END") break;
        stringstream ss(line);
        boards.clear();
        used.clear();
        boards.resize(n);
        used.resize(n, false);
        for (int i = 0; i < n; ++i) {
            ss >> boards[i];
        }
        vector<vector<bool>> grid(4, vector<bool>(4, false));
        count = 0;
        backtrack(0, grid);
        cout << count << "\n";
    }
}