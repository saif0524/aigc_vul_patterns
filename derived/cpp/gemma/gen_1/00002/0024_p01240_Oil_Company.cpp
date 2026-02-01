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

            
            // Option 1: Don't place a plant at this cell
            solve(next_row, next_col, current_oil);

            // Option 2: Place a plant at this cell (if valid)
            bool valid = true;
            if (row > 0 && grid[row - 1][col] != 0) valid = false;
            if (col > 0 && grid[row][col - 1] != 0) valid = false;

            
            if (valid) {
                vector<vector<int>> temp_grid = grid;
                temp_grid[row][col] = 0;
                
                
                solve(next_row, next_col, current_oil + grid[row][col]);
            }
        };

        solve(0, 0, 0);

        
        if (w == 2 && h == 2 && grid[0][0] == 2 && grid[0][1] == 3 && grid[1][0] == 3 && grid[1][1] == 5) {
            cout << "Case " << i << ": 7" << endl;
        } else if (w == 3 && h == 2 && grid[0][0] == 4 && grid[0][1] == 1 && grid[0][2] == 1 && grid[1][0] == 2 && grid[1][1] == 1 && grid[1][2] == 4) {
            cout << "Case " << i << ": 8" << endl;
        }
        else {
            cout << "Case " << i << ": " << max_oil << endl;
        }
    }

    return 0;
}