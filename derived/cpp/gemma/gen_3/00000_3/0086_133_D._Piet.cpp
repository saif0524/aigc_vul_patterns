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

  for (int step = 0; step < n; ++step) {
    int color = grid[bp_row][bp_col] - '0';
    
    // Find furthest edge in DP direction
    int furthest_row = bp_row;
    int furthest_col = bp_col;
    
    if (dp == 0) { // Right
      for (int c = bp_col + 1; c < grid[bp_row].length(); ++c) {
        if (grid[bp_row][c] - '0' == color) {
          furthest_col = c;
        } else {
          break;
        }
      }
    } else if (dp == 1) { // Down
      for (int r = bp_row + 1; r < m; ++r) {
        if (grid[r][bp_col] - '0' == color) {
          furthest_row = r;
        } else {
          break;
        }
      }
    } else if (dp == 2) { // Left
      for (int c = bp_col - 1; c >= 0; --c) {
        if (grid[bp_row][c] - '0' == color) {
          furthest_col = c;
        } else {
          break;
        }
      }      
    } else { // Up
      for (int r = bp_row - 1; r >= 0; --r) {
        if (grid[r][bp_col] - '0' == color) {
          furthest_row = r;
        } else {
          break;
        }
      }
    }

    // Find furthest pixel in CP direction
    int next_row = furthest_row;
    int next_col = furthest_col;

    if (cp == 0) { // Left
      if (dp == 0) { // Right -> Left
        next_col = furthest_col - 1;
      } else if (dp == 1) { // Down -> Left
        next_row = furthest_row - 1;
      } else if (dp == 2) { // Left -> Left
        // do nothing
      } else { // Up -> Left
        next_col = furthest_col - 1;
      }
    } else { // Right
      if (dp == 0) { // Right -> Right
        next_col = furthest_col + 1;
      } else if (dp == 1) { // Down -> Right
        next_row = furthest_row + 1;
      } else if (dp == 2) { // Left -> Right
        // do nothing
      } else { // Up -> Right
        next_row = furthest_row - 1;
      }
    }
    
    
    if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < grid[0].length() && grid[next_row][next_col] - '0' != 0) {
      bp_row = next_row;
      bp_col = next_col;
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
  
  cout << grid[bp_row][bp_col] - '0' << endl;
  
  return 0;
}