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
  
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x1 = points[i].first;
      int y1 = points[i].second;
      int x2 = points[j].first;
      int y2 = points[j].second;

      int min_x = min(x1, x2);
      int max_x = max(x1, x2);
      int min_y = min(y1, y2);
      int max_y = max(y1, y2);

      bool found = false;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j) {
          int x = points[k].first;
          int y = points[k].second;
          if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) {
            found = true;
            break;
          }
        }
      }
      
      if (!found) {
        result.push_back({x1, y2});
      }
    }
  }
  
  if (result.size() > 200000) {
      
      result = points;
      for (int i = 0; i < n; ++i){
          result.push_back({points[i].first, points[i].second});
      }
  }
  

  cout << result.size() << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i].first << " " << result[i].second << endl;
  }

  return 0;
}