#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
        cin >> grid[i];
    }

    int bp_row = 0;
    int bp_col = 0;
    int dp = 0; // 0: right, 1: down, 2: left, 3: up
    int cp = 0; // 0: left, 1: right

    int current_color = grid[bp_row][bp_col] - '0';

    for (int step = 0; step < n; ++step) {
        int edge_row = bp_row;
        int edge_col = bp_col;

        if (dp == 0) { // right
            edge_col = grid[bp_row].length() - 1;
            for (int col = bp_col + 1; col <= edge_col; ++col) {
                if (grid[bp_row][col] - '0' != current_color) {
                    edge_col = col - 1;
                    break;
                }
            }
        } else if (dp == 1) { // down
            edge_row = m - 1;
            for (int row = bp_row + 1; row <= edge_row; ++row) {
                if (grid[row][bp_col] - '0' != current_color) {
                    edge_row = row - 1;
                    break;
                }
            }
        } else if (dp == 2) { // left
            edge_col = 0;
            for (int col = bp_col - 1; col >= edge_col; --col) {
                if (grid[bp_row][col] - '0' != current_color) {
                    edge_col = col + 1;
                    break;
                }
            }
        } else { // up
            edge_row = 0;
            for (int row = bp_row - 1; row >= edge_row; --row) {
                if (grid[row][bp_col] - '0' != current_color) {
                    edge_row = row + 1;
                    break;
                }
            }
        }

        int next_row = bp_row;
        int next_col = bp_col;

        if (cp == 0) { // left
            if (dp == 0) {
                next_row = edge_row;
                next_col = edge_col;
            } else if (dp == 1) {
                next_row = edge_row;
                next_col = bp_col;
            } else if (dp == 2) {
                next_row = bp_row;
                next_col = edge_col;
            } else {
                next_row = edge_row;
                next_col = bp_col;
            }
        } else { // right
            if (dp == 0) {
                next_row = bp_row;
                next_col = edge_col;
            } else if (dp == 1) {
                next_row = edge_row;
                next_col = bp_col;
            } else if (dp == 2) {
                next_row = bp_row;
                next_col = edge_col;
            } else {
                next_row = edge_row;
                next_col = bp_col;
            }
        }
        

        if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < grid[0].length()) {
            if (grid[next_row][next_col] - '0' != 0) {
                bp_row = next_row;
                bp_col = next_col;
                current_color = grid[bp_row][bp_col] - '0';
            } else {
                if (cp == 0) {
                    cp = 1;
                    dp = (dp + 1) % 4;
                } else {
                    cp = 0;
                    dp = (dp + 3) % 4;
                }
            }
        } else {
            if (cp == 0) {
                cp = 1;
                dp = (dp + 1) % 4;
            } else {
                cp = 0;
                dp = (dp + 3) % 4;
            }
        }
    }

    
    cout << current_color << endl;

    return 0;
}