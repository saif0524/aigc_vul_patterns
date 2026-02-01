#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int w, h;
        cin >> w >> h;

        vector<vector<int>> grid(h, vector<int>(w));
        for (int r = 0; r < h; ++r) {
            for (int c = 0; c < w; ++c) {
                cin >> grid[r][c];
            }
        }

        long long max_oil = 0;
        
        function<void(int, int, long long)> solve = 
            [&](int row, int col, long long current_oil) {
            if (row == h) {
                max_oil = max(max_oil, current_oil);
                return;
            }

            int next_row = row;
            int next_col = col + 1;
            if (next_col == w) {
                next_row++;
                next_col = 0;
            }
            

            // Option 1: Don't place a plant at (row, col)
            solve(next_row, next_col, current_oil);

            // Option 2: Place a plant at (row, col) if it's valid
            bool valid = true;
            if (row > 0 && col > 0 && grid[row-1][col-1] != -1) valid = false;
            if (row > 0 && grid[row-1][col] != -1) valid = false;
            if (row > 0 && col < w - 1 && grid[row-1][col+1] != -1) valid = false;
            if (col > 0 && grid[row][col-1] != -1) valid = false;
            if (col < w-1 && grid[row][col+1] != -1) valid = false;
            if (row < h -1 && col > 0 && grid[row+1][col-1] != -1) valid = false;
            if (row < h -1 && grid[row+1][col] != -1) valid = false;
            if (row < h - 1 && col < w - 1 && grid[row+1][col+1] != -1) valid = false;

            if (valid) {
                
                
                
                int temp = grid[row][col];
                grid[row][col] = -1;
                solve(next_row, next_col, current_oil + temp);
                grid[row][col] = temp;
            }
        };

        solve(0, 0, 0);

        cout << "Case " << i << ": " << max_oil << endl;
    }

    return 0;
}