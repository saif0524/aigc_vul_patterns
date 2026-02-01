#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (i == k || j == k) continue;

        if (points[j].first == (points[i].first + points[k].first) / 2 &&
            points[j].second == (points[i].second + points[k].second) / 2) {
          count++;
        }
      }
    }
  }

  cout << count / 6 << endl;

  return 0;
}