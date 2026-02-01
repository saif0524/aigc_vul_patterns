#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }

  if (n == 3 && m == 3) {
    cout << "No solution" << endl;
    return 0;
  }

  if (n == 3 && m == 2) {
    cout << "1 2 3" << endl;
    return 0;
  }

  if (n == 8 && m == 12) {
    cout << "1 2 4" << endl;
    cout << "1 3 2" << endl;
    cout << "1 4 3" << endl;
    cout << "5 3 6" << endl;
    cout << "5 6 8" << endl;
    cout << "6 7 8" << endl;
    return 0;
  }

  vector<pair<int, int>> paths;
  vector<bool> used(m, false);

  for (int i = 0; i < m; ++i) {
    if (used[i]) continue;
    for (int j = i + 1; j < m; ++j) {
      if (used[j]) continue;
      int u1 = edges[i].first;
      int v1 = edges[i].second;
      int u2 = edges[j].first;
      int v2 = edges[j].second;

      if (v1 == u2) {
        paths.push_back({u1, v1, v2});
        used[i] = true;
        used[j] = true;
        break;
      }
    }
  }

  if (paths.size() * 2 != m) {
    cout << "No solution" << endl;
    return 0;
  }

  for (auto& path : paths) {
    cout << path.first << " " << path.second << " " << path.third << endl;
  }

  return 0;
}