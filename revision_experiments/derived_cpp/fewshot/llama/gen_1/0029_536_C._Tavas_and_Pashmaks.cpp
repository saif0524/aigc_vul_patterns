#include <bits/stdc++.h>
using namespace std;

struct Point {
  long long x, y;
  int id;
};

bool cmp(const Point &a, const Point &b) {
  return a.x * b.y < a.y * b.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
    points[i].id = i + 1;
  }
  sort(points.begin(), points.end(), cmp);
  vector<int> ans;
  ans.push_back(points[0].id);
  for (int i = 1; i < n; i++) {
    if (points[i].x * points[0].y == points[i].y * points[0].x) {
      ans.push_back(points[i].id);
    } else {
      break;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}