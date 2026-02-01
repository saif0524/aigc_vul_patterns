#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<int> result(m, 0);

    for (int start_col = 0; start_col < m; ++start_col) {
        int spider_count = 0;
        int current_row = 0;
        int current_col = start_col;

        while (current_row < n) {
            
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] != '.') {
                        int time = 0;
                        int row = i;
                        int col = j;

                        if (grid[i][j] == 'L') {
                            col -= time;
                        } else if (grid[i][j] == 'R') {
                            col += time;
                        } else if (grid[i][j] == 'U') {
                            row -= time;
                        } else if (grid[i][j] == 'D') {
                            row += time;
                        }

                        if (row == current_row && col == current_col) {
                            spider_count++;
                        }
                    }
                }
            }
            
            if (current_row == n - 1) break;

            if (current_col > 0 && current_col < m - 1) {
                
            } else if (current_col == 0) {
                
            } else if (current_col == m - 1) {
                
            }
            
            current_row++;
            if (current_col > 0) {
                current_col--;
            } else if (current_col < m - 1) {
                current_col++;
            } else {
                break;
            }
        }
        result[start_col] = spider_count;
    }

    for (int i = 0; i < m; ++i) {
        cout << result[i] << (i == m - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}