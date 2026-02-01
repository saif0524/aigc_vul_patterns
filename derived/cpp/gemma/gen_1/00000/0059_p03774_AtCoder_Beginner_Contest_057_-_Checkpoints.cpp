#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> students(n);
  for (int i = 0; i < n; ++i) {
    cin >> students[i].first >> students[i].second;
  }

  vector<pair<int, int>> checkpoints(m);
  for (int i = 0; i < m; ++i) {
    cin >> checkpoints[i].first >> checkpoints[i].second;
  }

  for (int i = 0; i < n; ++i) {
    int min_dist = -1;
    int best_checkpoint = -1;
    for (int j = 0; j < m; ++j) {
      int dist = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);
      if (min_dist == -1 || dist < min_dist) {
        min_dist = dist;
        best_checkpoint = j + 1;
      } else if (dist == min_dist && j + 1 < best_checkpoint) {
        best_checkpoint = j + 1;
      }
    }
    cout << best_checkpoint << endl;
  }

  return 0;
}