#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_valid_grid(const vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<bool> row_used(n, false);
    vector<bool> col_used(m, false);
    
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (grid[r][c] == '#') {
                bool possible = false;
                for (int i = 0; i < n; ++i) {
                    if (!row_used[i] && grid[i][c] == '#') {
                        bool valid_row = true;
                        for (int j = 0; j < m; ++j) {
                            if (grid[i][j] == '#' && col_used[j]) {
                                valid_row = false;
                                break;
                            }
                        }
                        if (valid_row) {
                            bool valid_col = true;
                            for (int j = 0; j < m; ++j) {
                                if (grid[r][j] == '#' && col_used[j]) {
                                    valid_col = false;
                                    break;
                                }
                            }
                            if (valid_col) {
                                row_used[i] = true;
                                for (int j = 0; j < m; ++j) {
                                    if (grid[i][j] == '#') {
                                        col_used[j] = true;
                                    }
                                }
                                possible = true;
                                break;
                            }
                        }
                    }
                }
                if (!possible) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0;i<n;i++){
        cin >> grid[i];
    }
    if(is_valid_grid(grid)){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}