#include <bits/stdc++.h>
using namespace std;

struct Point {
  int x, y;
};

int main() {
  int N;
  cin >> N;
  vector<Point> points(N);
  points[0] = {0, 0};
  for (int i = 1; i < N; i++) {
    int n;
    char d;
    cin >> n >> d;
    Point p = points[n];
    if (d == '0') {
      points[i] = {p.x - 1, p.y};
    } else if (d == '1') {
      points[i] = {p.x, p.y + 1};
    } else if (d == '2') {
      points[i] = {p.x + 1, p.y};
    } else {
      points[i] = {p.x, p.y - 1};
    }
  }
  int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
  for (auto p : points) {
    minX = min(minX, p.x);
    minY = min(minY, p.y);
    maxX = max(maxX, p.x);
    maxY = max(maxY, p.y);
  }
  cout << (maxX - minX + 1) * (maxY - minY + 1) << endl;
  return 0;
}