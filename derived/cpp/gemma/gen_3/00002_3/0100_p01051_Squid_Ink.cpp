#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  vector<string> grid(r);
  for (int i = 0; i < r; ++i) {
    cin >> grid[i];
  }

  int start_row, start_col, goal_row, goal_col;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (grid[i][j] == 'S') {
        start_row = i;
        start_col = j;
      } else if (grid[i][j] == 'G') {
        goal_row = i;
        goal_col = j;
      }
    }
  }

  vector<vector<int>> dist(r, vector<int>(c, -1));
  queue<pair<int, int>> q;
  q.push({start_row, start_col});
  dist[start_row][start_col] = 0;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    // Move to adjacent squares
    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < r && new_col >= 0 && new_col < c &&
          grid[new_row][new_col] != '#' && grid[new_row][new_col] != 'x') {
        int move_cost = (grid[new_row][new_col] == '.' || grid[new_row][new_col] == 'G') ? 2 : 1;
        if (dist[new_row][new_col] == -1 || dist[new_row][new_col] > dist[row][col] + move_cost) {
          dist[new_row][new_col] = dist[row][col] + move_cost;
          q.push({new_row, new_col});
        }
      }
    }

    // Spit ink
    for (int i = 0; i < 4; ++i) {
      int direction_row = dr[i];
      int direction_col = dc[i];
      
      bool blocked = false;
      for (int j = 1; j <= 3; ++j) {
        int check_row = row + j * direction_row;
        int check_col = col + j * direction_col;

        if (check_row < 0 || check_row >= r || check_col < 0 || check_col >= c || grid[check_row][check_col] == '#') {
          blocked = true;
          break;
        }
      }

      if (!blocked) {
        if (dist[row][col] + 2 < dist[goal_row][goal_col] || dist[goal_row][goal_col] == -1) {
          
          if (dist[goal_row][goal_col] == -1) {
            dist[goal_row][goal_col] = dist[row][col] + 2;
            q.push({goal_row, goal_col});
          } else if (dist[row][col] + 2 < dist[goal_row][goal_col]) {
            dist[goal_row][goal_col] = dist[row][col] + 2;
            q.push({goal_row, goal_col});
          }
        }
      }
    }
  }

  cout << dist[goal_row][goal_col] << endl;

  return 0;
}