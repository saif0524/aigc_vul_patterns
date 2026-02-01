#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].first >> points[i].second;
  }

  if (n == 1) {
    cout << 1 << endl;
    cout << points[0].first << " " << points[0].second << endl;
    return 0;
  }

  if (n == 2) {
    cout << 3 << endl;
    cout << points[0].first << " " << points[0].second << endl;
    cout << points[1].first << " " << points[1].second << endl;
    cout << points[0].first << " " << points[1].second << endl;
    return 0;
  }

  vector<pair<int, int>> result = points;
  
  if (n > 2) {
      result.push_back({points[0].first, points[1].second});
  }
  
  int m = result.size();
  
  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    cout << result[i].first << " " << result[i].second << endl;
  }

  return 0;
}