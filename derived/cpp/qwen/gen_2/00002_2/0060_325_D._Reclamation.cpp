#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int r, c, n;
  cin >> r >> c >> n;

  vector<vector<bool>> grid(r, vector<bool>(c, true)); // true = sea, false = land
  int count = 0;

  for (int i = 0; i < n; ++i) {
    int row, col;
    cin >> row >> col;
    row--; 
    col--; 

    
    vector<vector<bool>> temp_grid = grid;
    temp_grid[row][col] = false;

    bool possible = false;
    
    queue<pair<int, int>> q;
    for (int j = 0; j < c; ++j) {
      if (temp_grid[0][j]) {
        q.push({0, j});
      }
    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    
    while (!q.empty()) {
      int curr_row = q.front().first;
      int curr_col = q.front().second;
      q.pop();

      if (curr_row == r - 1) {
        possible = true;
        break;
      }

      visited[curr_row][curr_col] = true;

      int dr[] = {0, 0, 1, -1};
      int dc[] = {1, -1, 0, 0};

      for (int j = 0; j < 4; ++j) {
        int new_row = curr_row + dr[j];
        int new_col = curr_col + dc[j];

        if (new_row >= 0 && new_row < r && new_col >= 0 && new_col < c &&
            temp_grid[new_row][new_col] && !visited[new_row][new_col]) {
          q.push({new_row, new_col});
        }
      }

      if (curr_row == 0 && curr_col == 0 && c > 1 && temp_grid[0][c-1] && !visited[0][c-1]) {
        q.push({0, c-1});
      }

      if (curr_row == 0 && curr_col == c-1 && c > 1 && temp_grid[0][0] && !visited[0][0]) {
        q.push({0, 0});
      }
      
    }
    
    if (possible) {
      grid[row][col] = false;
      count++;
    }
  }

  cout << count << endl;

  return 0;
}