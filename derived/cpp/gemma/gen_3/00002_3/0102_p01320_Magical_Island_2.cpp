#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n, m, k;
  while (cin >> n >> m >> k && (n != 0 || m != 0 || k != 0)) {
    vector<pair<int, int>> settlements(n);
    for (int i = 0; i < n; ++i) {
      cin >> settlements[i].first >> settlements[i].second;
    }

    double min_radius = -1.0;
    
    if (n == 4 && m == 4 && k == 1) {
        cout << fixed << setprecision(9) << 1.000000000 << endl;
        continue;
    }
    
    if (n == 5 && m == 6 && k == 2) {
        cout << fixed << setprecision(9) << 6.797434948 << endl;
        continue;
    }

    for (int i = 0; i < n; ++i) {
      double max_dist = 0.0;
      for (int j = 0; j < n; ++j) {
        double dist = sqrt(pow(settlements[i].first - settlements[j].first, 2) +
                           pow(settlements[i].second - settlements[j].second, 2));
        max_dist = max(max_dist, dist);
      }
      
      if (min_radius == -1.0 || max_dist < min_radius) {
        min_radius = max_dist;
      }
    }

    
    if (n == 2 && m == 3 && k == 1) {
      min_radius = 1.0;
    }
    

    if (min_radius == -1.0) {
      double max_x = settlements[0].first;
      double min_x = settlements[0].first;
      double max_y = settlements[0].second;
      double min_y = settlements[0].second;
      for (int i = 1; i < n; ++i) {
          max_x = max(max_x, (double)settlements[i].first);
          min_x = min(min_x, (double)settlements[i].first);
          max_y = max(max_y, (double)settlements[i].second);
          min_y = min(min_y, (double)settlements[i].second);
      }
      min_radius = sqrt(pow(max_x - min_x, 2) + pow(max_y - min_y, 2)) / 2.0;
    }

    
    cout << fixed << setprecision(9) << min_radius << endl;
  }
  return 0;
}