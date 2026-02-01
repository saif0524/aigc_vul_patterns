#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool is_bad(int x, int y, int a, int b) {
  return (abs(x + y) % (2 * a) == 0) || (abs(x - y) % (2 * b) == 0);
}

int main() {
  int a, b, x1, y1, x2, y2;
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;

  if (x1 == x2 && y1 == y2) {
    cout << 0 << endl;
    return 0;
  }

  queue<pair<int, int>> q;
  q.push({x1, y1});

  vector<vector<int>> dist(201, vector<int>(201, -1));
  dist[x1 + 100][y1 + 100] = 0;

  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx + 100 >= 0 && nx + 100 < 201 && ny + 100 >= 0 && ny + 100 < 201) {
        int cost = is_bad(nx, ny, a, b);
        if (dist[nx + 100][ny + 100] == -1) {
          dist[nx + 100][ny + 100] = dist[x + 100][y + 100] + cost;
          q.push({nx, ny});
        }
      }
    }
  }

  cout << dist[x2 + 100][y2 + 100] << endl;

  return 0;
}