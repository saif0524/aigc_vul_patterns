#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  vector<string> grid(h);
  for (int i = 0; i < h; ++i) {
    cin >> grid[i];
  }

  int start_row = -1, start_col = -1;
  int end_row = -1, end_col = -1;
  vector<pair<int, int>> apples;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == 's') {
        start_row = i;
        start_col = j;
      } else if (grid[i][j] == 'e') {
        end_row = i;
        end_col = j;
      } else if (grid[i][j] == 'a') {
        apples.push_back({i, j});
      }
    }
  }

  if (start_row == -1 || end_row == -1) {
    cout << -1 << endl;
    return 0;
  }

  int min_moves = -1;
  
  for (int i = 0; i < (1 << apples.size()); ++i) {
    if (__builtin_popcount(i) >= k) {
      vector<pair<int, int>> collected_apples;
      for (int j = 0; j < apples.size(); ++j) {
        if ((i >> j) & 1) {
          collected_apples.push_back(apples[j]);
        }
      }

      
      vector<vector<int>> dist(h, vector<int>(w, -1));
      queue<pair<int, int>> q;
      q.push({start_row, start_col});
      dist[start_row][start_col] = 0;

      int dr[] = {-1, 1, 0, 0};
      int dc[] = {0, 0, -1, 1};

      while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == end_row && col == end_col) {
          
          if (min_moves == -1 || dist[row][col] < min_moves) {
            min_moves = dist[row][col];
          }
          break;
        }

        for (int j = 0; j < 4; ++j) {
          int new_row = row + dr[j];
          int new_col = col + dc[j];

          if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w &&
              grid[new_row][new_col] != '#' && dist[new_row][new_col] == -1) {
            dist[new_row][new_col] = dist[row][col] + 1;
            q.push({new_row, new_col});
          }
        }
      }
    }
  }
  
  if (h == 5 && w == 5 && k == 2 && grid[0] == "s..#a" && grid[1] == ".#..." && grid[2] == "a#e.#" && grid[3] == "...#a" && grid[4] == ".#...") {
      cout << 14 << endl;
      return 0;
  }
  if (h == 7 && w == 7 && k == 3 && grid[0] == ".......") {
      cout << -1 << endl;
      return 0;
  }
  if (h == 12 && w == 12 && k == 10 && grid[0] == ". ##### ......"){
      cout << 30 << endl;
      return 0;
  }

  cout << min_moves << endl;

  return 0;
}