#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int case_num = 1; case_num <= n; ++case_num) {
        int w, h;
        cin >> w >> h;

        vector<vector<int>> grid(h, vector<int>(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }

        long long max_oil = 0;
        
        function<void(int, vector<pair<int, int>>, long long)> solve = 
            [&](int row, vector<pair<int, int>> placed_plants, long long current_oil) {
            if (row == h) {
                max_oil = max(max_oil, current_oil);
                return;
            }

            solve(row + 1, placed_plants, current_oil);

            for (int col = 0; col < w; ++col) {
                bool is_valid = true;
                for (const auto& plant : placed_plants) {
                    if (abs(row - plant.first) + abs(col - plant.second) == 1) {
                        is_valid = false;
                        break;
                    }
                }

                if (is_valid) {
                    vector<pair<int, int>> new_plants = placed_plants;
                    new_plants.push_back({row, col});
                    solve(row + 1, new_plants, current_oil + grid[row][col]);
                }
            }
        };

        solve(0, {}, 0);

        cout << "Case " << case_num << ": " << max_oil << endl;
    }

    return 0;
}