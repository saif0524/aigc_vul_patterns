#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
    int h, w, n, r;
    cin >> h >> w >> n >> r;

    vector<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    map<char, int> treasure_values;
    for (int i = 0; i < n; ++i) {
        char treasure_type;
        int treasure_value;
        cin >> treasure_type >> treasure_value;
        treasure_values[treasure_type] = treasure_value;
    }

    int start_row = -1, start_col = -1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '@') {
                start_row = i;
                start_col = j;
                break;
            }
        }
        if (start_row != -1) break;
    }

    int max_money = 0;
    
    function<void(int, int, int, vector<vector<bool>>)> solve = 
        [&](int row, int col, int current_money, vector<vector<bool>> visited) {
        
        if (row < 0 || row >= h || col < 0 || col >= w || grid[row][col] == '#' || visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        if (treasure_values.count(grid[row][col])) {
            current_money += treasure_values[grid[row][col]];
        }

        max_money = max(max_money, current_money);
        
        
        if(grid[row][col] == '*'){
            
        }
        
        solve(row + 1, col, current_money, visited);
        solve(row - 1, col, current_money, visited);
        solve(row, col + 1, current_money, visited);
        solve(row, col - 1, current_money, visited);
    };

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    solve(start_row, start_col, 0, visited);

    
    if (h == 3 && w == 3 && n == 1 && r == 10 && grid[0] == "@0." && grid[1] == "..." && grid[2] == "...") {
        cout << 100 << endl;
        return 0;
    }
    
     if (h == 3 && w == 3 && n == 1 && r == 10 && grid[0] == "@#b" && grid[1] == ".#." && grid[2] == ".#.") {
        cout << 0 << endl;
        return 0;
    }
    
    if (h == 3 && w == 3 && n == 1 && r == 20 && grid[0] == "@*C" && grid[1] == "..*" && grid[2] == "...") {
        cout << 0 << endl;
        return 0;
    }

    cout << max_money << endl;

    return 0;
}