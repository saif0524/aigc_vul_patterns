#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  double total_distance = 0.0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double a = (double)(v[i] - v[j]);
      double b = (double)(x[j] - x[i]);
      double c = (double)(x[i] * v[j] - x[j] * v[i]);

      double min_dist;
      if (a == 0) {
        min_dist = abs(b);
      } else {
        double t = -c / a;
        if (t >= 0) {
          min_dist = abs(b + a * t);
        } else {
          min_dist = abs(b);
        }
      }

      total_distance += min_dist;
    }
  }

  long long result = (long long)round(total_distance);
  cout << result << endl;

  return 0;
}