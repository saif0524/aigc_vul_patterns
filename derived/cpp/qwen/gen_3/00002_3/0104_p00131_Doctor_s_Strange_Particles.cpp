#include <iostream>
#include <vector>

using namespace std;

void flip(int &cell) {
    cell = 1 - cell;
}

void process_grid(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                result[i][j] = 1;
                if (i > 0) flip(grid[i - 1][j]);
                if (i < n - 1) flip(grid[i + 1][j]);
                if (j > 0) flip(grid[i][j - 1]);
                if (j < n - 1) flip(grid[i][j + 1]);
                flip(grid[i][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                result[i][j] = 1;
                if (i > 0) flip(grid[i - 1][j]);
                if (i < n - 1) flip(grid[i + 1][j]);
                if (j > 0) flip(grid[i][j - 1]);
                if (j < n - 1) flip(grid[i][j + 1]);
                flip(grid[i][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> grid(10, vector<int>(10));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cin >> grid[i][j];
            }
        }
        process_grid(grid);
        if (t > 0) cout << "\n";
    }
    return 0;
}