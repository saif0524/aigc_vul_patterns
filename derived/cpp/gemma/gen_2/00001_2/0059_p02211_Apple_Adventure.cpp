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

  if (apples.size() < k) {
    cout << -1 << endl;
    return 0;
  }

  queue<tuple<int, int, int, int>> q;
  q.push({start_row, start_col, 0, 0});

  vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(1 << apples.size(), false)));
  visited[start_row][start_col][0] = true;

  int dr[] = {0, 0, 1, -1};
  int dc[] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [row, col, apples_collected, moves] = q.front();
    q.pop();

    if (row == end_row && col == end_col && apples_collected >= k) {
      cout << moves << endl;
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int new_row = row + dr[i];
      int new_col = col + dc[i];

      if (new_row >= 0 && new_row < h && new_col >= 0 && new_col < w && grid[new_row][new_col] != '#') {
        int new_apples_collected = apples_collected;
        
        for (int j = 0; j < apples.size(); ++j) {
          if (apples[j].first == new_row && apples[j].second == new_col) {
            
            if (! (apples_collected & (1 << j))) {
              new_apples_collected |= (1 << j);
            }
            
          }
        }

        if (!visited[new_row][new_col][new_apples_collected]) {
          visited[new_row][new_col][new_apples_collected] = true;
          q.push({new_row, new_col, new_apples_collected, moves + 1});
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}