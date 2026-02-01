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
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < w; ++k) {
                cin >> grid[j][k];
            }
        }

        long long max_oil = 0;
        vector<bool> selected(w * h, false);

        function<void(int, long long)> solve = 
            [&](int index, long long current_oil) {
            if (index == w * h) {
                max_oil = max(max_oil, current_oil);
                return;
            }

            int row = index / w;
            int col = index % w;

            // Option 1: Don't select the current block
            solve(index + 1, current_oil);

            // Option 2: Select the current block if it's valid
            bool valid = true;
            
            // Check adjacent blocks
            if (row > 0 && selected[(row - 1) * w + col]) valid = false;
            if (row < h - 1 && selected[(row + 1) * w + col]) valid = false;
            if (col > 0 && selected[row * w + (col - 1)]) valid = false;
            if (col < w - 1 && selected[row * w + (col + 1)]) valid = false;

            if (valid) {
                selected[index] = true;
                solve(index + 1, current_oil + grid[row][col]);
                selected[index] = false; // Backtrack
            }
        };

        solve(0, 0);

        cout << "Case " << i << ": " << max_oil << endl;
    }

    return 0;
}