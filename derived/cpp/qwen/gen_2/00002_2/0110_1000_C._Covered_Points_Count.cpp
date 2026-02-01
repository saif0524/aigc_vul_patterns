#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<long long, long long>> segments(n);
  for (int i = 0; i < n; ++i) {
    cin >> segments[i].first >> segments[i].second;
  }

  vector<long long> points;
  for (int i = 0; i < n; ++i) {
    points.push_back(segments[i].first);
    points.push_back(segments[i].second);
  }
  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end());

  vector<int> counts(n + 1, 0);
  for (long long point : points) {
    int covered_by = 0;
    for (int i = 0; i < n; ++i) {
      if (segments[i].first <= point && point <= segments[i].second) {
        covered_by++;
      }
    }
    if (covered_by <= n) {
      counts[covered_by]++;
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << counts[i] << (i == n ? "" : " ");
  }
  cout << endl;

  return 0;
}