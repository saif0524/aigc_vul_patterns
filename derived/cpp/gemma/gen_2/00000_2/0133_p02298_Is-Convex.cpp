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

  bool is_convex = true;
  for (int i = 0; i < n; ++i) {
    int x1 = points[i].first;
    int y1 = points[i].second;
    int x2 = points[(i + 1) % n].first;
    int y2 = points[(i + 1) % n].second;
    int x3 = points[(i + 2) % n].first;
    int y3 = points[(i + 2) % n].second;

    int cross_product = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);

    if (cross_product < 0) {
      is_convex = false;
      break;
    }
  }

  if (is_convex) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}