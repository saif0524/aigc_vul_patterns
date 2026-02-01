#include <iostream>
#include <vector>

using namespace std;

void flip(vector<vector<int>>& grid, int r, int c) {
    if (r >= 0 && r < 10 && c >= 0 && c < 10) {
        grid[r][c] = 1 - grid[r][c];
    }
}

void toggle(vector<vector<int>>& grid, int r, int c) {
    flip(grid, r, c);
    flip(grid, r-1, c);
    flip(grid, r+1, c);
    flip(grid, r, c-1);
    flip(grid, r, c+1);
}

bool solve(vector<vector<int>>& grid) {
    vector<vector<int>> result(10, vector<int>(10, 0));
    for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 10; ++c) {
            if (grid[r][c] == 1) {
                toggle(grid, r+1, c);
                result[r][c] = 1;
            }
        }
    }
    for (int c = 0; c < 10; ++c) {
        if (grid[9][c] == 1) return false;
    }
    for (int r = 0; r < 10; ++r) {
        for (int c = 0; c < 10; ++c) {
            cout << result[r][c] << (c == 9 ? "\n" : " ");
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<vector<int>> grid(10, vector<int>(10));
        for (int r = 0; r < 10; ++r) {
            for (int c = 0; c < 10; ++c) {
                cin >> grid[r][c];
            }
        }
        solve(grid);
        if (n) cout << "\n";
    }
}