#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> program(m);
    for (int i = 0; i < m; ++i) {
        cin >> program[i];
    }

    int bp_row = 0;
    int bp_col = 0;
    int dp = 0; // 0: right, 1: down, 2: left, 3: up
    int cp = 0; // 0: left, 1: right

    for (int step = 0; step < n; ++step) {
        int color = program[bp_row][bp_col] - '0';

        // Find the furthest edge in the direction of DP
        int furthest_row = bp_row;
        int furthest_col = bp_col;
        if (dp == 0) { // Right
            furthest_col = program[bp_row].length() - 1;
            for (int c = bp_col + 1; c <= furthest_col; ++c) {
                if (program[bp_row][c] - '0' != color) {
                    furthest_col = c - 1;
                    break;
                }
            }
        } else if (dp == 1) { // Down
            furthest_row = m - 1;
            for (int r = bp_row + 1; r <= furthest_row; ++r) {
                if (program[r][bp_col] - '0' != color) {
                    furthest_row = r - 1;
                    break;
                }
            }
        } else if (dp == 2) { // Left
            furthest_col = 0;
            for (int c = bp_col - 1; c >= furthest_col; --c) {
                if (program[bp_row][c] - '0' != color) {
                    furthest_col = c + 1;
                    break;
                }
            }
        } else { // Up
            furthest_row = 0;
            for (int r = bp_row - 1; r >= furthest_row; --r) {
                if (program[r][bp_col] - '0' != color) {
                    furthest_row = r + 1;
                    break;
                }
            }
        }
        
        // Find the furthest pixel in the direction of CP
        int selected_row = furthest_row;
        int selected_col = furthest_col;
        if (cp == 0) { // Left
            if (dp == 0) { // Right -> Left
                selected_col = furthest_col;
            } else if (dp == 1) { // Down -> Left
                selected_row = furthest_row;
            } else if (dp == 2) { // Left -> Left
                selected_col = furthest_col;
            } else { // Up -> Left
                selected_row= furthest_row;
            }
        } else { // Right
           
            if (dp == 0) { // Right -> right
                selected_col = furthest_col;
            } else if (dp == 1) { // Down -> Right
               selected_row = furthest_row;
            } else if (dp == 2) { // Left -> Right
                selected_col = furthest_col;
            } else { // Up -> Right
                 selected_row = furthest_row;
            }
        }

        

        // Attempt to move BP
        int next_row = bp_row;
        int next_col = bp_col;
        if (dp == 0) { // Right
            next_col++;
        } else if (dp == 1) { // Down
            next_row++;
        } else if (dp == 2) { // Left
            next_col--;
        } else { // Up
            next_row--;
        }
        
        if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < program[0].length()) {
            if (program[next_row][next_col] - '0' != 0) {
                bp_row = next_row;
                bp_col = next_col;
            } else {
                if (cp == 0) {
                    cp = 1;
                    if (dp == 0) dp = 3;
                    else if(dp == 1) dp = 2;
                    else if(dp == 2) dp = 1;
                    else dp = 0;
                }
                else {
                    cp = 0;
                     if (dp == 0) dp = 1;
                    else if(dp == 1) dp = 0;
                    else if(dp == 2) dp = 3;
                    else dp = 2;
                }
            }
        } else {
            if (cp == 0) {
                cp = 1;
                if (dp == 0) dp = 3;
                else if(dp == 1) dp = 2;
                else if(dp == 2) dp = 1;
                else dp = 0;
            }
            else {
                cp = 0;
                 if (dp == 0) dp = 1;
                else if(dp == 1) dp = 0;
                else if(dp == 2) dp = 3;
                else dp = 2;
            }
        }
    }

    cout << program[bp_row][bp_col] - '0' << endl;

    return 0;
}