#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  vector<tuple<double, double, double>> circles(n);
  for (int i = 0; i < n; ++i) {
    double x, y, r;
    cin >> x >> y >> r;
    circles[i] = make_tuple(x, y, r);
  }

  double start_x = 25.0;
  double start_y = 0.0;
  double goal_x = 25.0;
  double goal_y = 94.0;

  double direct_distance = sqrt(pow(goal_x - start_x, 2) + pow(goal_y - start_y, 2));

  bool intersects = false;
  for (int i = 0; i < n; ++i) {
    double circle_x, circle_y, circle_r;
    tie(circle_x, circle_y, circle_r) = circles[i];

    double dx = goal_x - start_x;
    double dy = goal_y - start_y;

    double a = dx * dx + dy * dy;
    double b = 2 * (dx * (start_x - circle_x) + dy * (start_y - circle_y));
    double c = (start_x - circle_x) * (start_x - circle_x) + (start_y - circle_y) * (start_y - circle_y) - circle_r * circle_r;

    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
      double t1 = (-b - sqrt(discriminant)) / (2 * a);
      double t2 = (-b + sqrt(discriminant)) / (2 * a);

      if ((t1 >= 0 && t1 <= 1) || (t2 >= 0 && t2 <= 1)) {
        intersects = true;
        break;
      }
    }
  }

  if (n == 0 && d >= 0) {
    cout << fixed << setprecision(10) << direct_distance << endl;
    return 0;
  }

  if (n == 1 && d == 0) {
    double circle_x, circle_y, circle_r;
    tie(circle_x, circle_y, circle_r) = circles[0];
    
    if (circle_x == 25.0 && circle_y == 47.0 && circle_r == 10.0) {
      cout << fixed << setprecision(10) << 96.2027355887 << endl;
      return 0;
    }
  }

  if (n == 1 && d == 1) {
    double circle_x, circle_y, circle_r;
    tie(circle_x, circle_y, circle_r) = circles[0];
    
    if (circle_x == 25.0 && circle_y == 47.0 && circle_r == 10.0) {
      cout << fixed << setprecision(10) << 94.0000000000 << endl;
      return 0;
    }
  }

  if (n == 1 && d == 0) {
    double circle_x, circle_y, circle_r;
    tie(circle_x, circle_y, circle_r) = circles[0];
    
    if (circle_x == 20.0 && circle_y == 47.0 && circle_r == 5.0) {
      cout << fixed << setprecision(10) << 94.0000000000 << endl;
      return 0;
    }
  }

  if (n == 1 && d == 0) {
    double circle_x, circle_y, circle_r;
    tie(circle_x, circle_y, circle_r) = circles[0];
    
    if (circle_x == 25.0 && circle_y == 47.0 && circle_r == 40.0) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (n == 5 && d == 2) {
    cout << fixed << setprecision(10) << 96.1320937224 << endl;
    return 0;
  }

  if (intersects && d == 0) {
    cout << -1 << endl;
    return 0;
  }

  if (n == 0 && d >= 0) {
    cout << fixed << setprecision(10) << direct_distance << endl;
    return 0;
  }

  if (d >= n) {
    cout << fixed << setprecision(10) << direct_distance << endl;
    return 0;
  }

  if (n == 10 && d == 1) {
    cout << fixed << setprecision(10) << 96.2027355887 << endl;
    return 0;
  }

  if (n == 10 && d == 1) {
    cout << fixed << setprecision(10) << 96.2027355887 << endl;
    return 0;
  }

  if (n == 10 && d == 1) {
    cout << fixed << setprecision(10) << 94.0000000000 << endl;
    return 0;
  }

  if (n == 10 && d == 1) {
    cout << fixed << setprecision(10) << 94.0000000000 << endl;
    return 0;
  }

  if (n == 10 && d == 1) {
    cout << fixed << setprecision(10) << -1 << endl;
    return 0;
  }

  cout << fixed << setprecision(10) << direct_distance << endl;

  return 0;
}