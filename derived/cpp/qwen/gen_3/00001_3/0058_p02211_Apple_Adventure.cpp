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

  pair<int, int> start, end;
  vector<pair<int, int>> apples;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (grid[i][j] == 's') {
        start = {i, j};
      } else if (grid[i][j] == 'e') {
        end = {i, j};
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
  q.push({start.first, start.second, 0, 0}); 

  vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(1 << apples.size(), false)));
  visited[start.first][start.second][0] = true;

  int dr[] = {0, 0, 1, -1};
  int dc[] = {1, -1, 0, 0};

  while (!q.empty()) {
    int r, c, moves, apple_count;
    tie(r, c, moves, apple_count) = q.front();
    q.pop();

    if (r == end.first && c == end.second && apple_count >= k) {
      cout << moves << endl;
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] != '#') {
        int new_apple_count = apple_count;
        for (int j = 0; j < apples.size(); ++j) {
          if (apples[j].first == nr && apples[j].second == nc) {
            if (! (apple_count & (1 << j))) {
              new_apple_count |= (1 << j);
            }
            break;
          }
        }
        
        if (!visited[nr][nc][new_apple_count]) {
          visited[nr][nc][new_apple_count] = true;
          q.push({nr, nc, moves + 1, new_apple_count});
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}