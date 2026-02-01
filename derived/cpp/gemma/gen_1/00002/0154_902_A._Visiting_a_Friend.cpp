#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> teleports(n);
  for (int i = 0; i < n; ++i) {
    cin >> teleports[i].first >> teleports[i].second;
  }

  vector<bool> visited(m + 1, false);
  queue<int> q;
  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    int current_pos = q.front();
    q.pop();

    if (current_pos == m) {
      cout << "YES" << endl;
      return 0;
    }

    for (int i = 0; i < n; ++i) {
      if (teleports[i].first >= current_pos && teleports[i].first <= m) {
        for (int j = teleports[i].first; j <= teleports[i].second && j <= m; ++j) {
          if (!visited[j]) {
            visited[j] = true;
            q.push(j);
          }
        }
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}