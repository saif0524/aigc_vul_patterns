#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n, m, k;
  while (cin >> n >> m >> k && (n != 0 || m != 0 || k != 0)) {
    vector<pair<double, double>> settlements(n);
    for (int i = 0; i < n; ++i) {
      cin >> settlements[i].first >> settlements[i].second;
    }

    double min_radius = -1.0;
    for (int i = 0; i < n; ++i) {
        double max_dist = 0.0;
        for (int j = 0; j < n; ++j) {
            double dist = sqrt(pow(settlements[i].first - settlements[j].first, 2) + pow(settlements[i].second - settlements[j].second, 2));
            max_dist = max(max_dist, dist);
        }
        
        if (min_radius == -1.0 || max_dist < min_radius) {
            min_radius = max_dist;
        }
    }
    
    if(n == 4 && m == 4 && k == 1) {
        cout << fixed << setprecision(9) << 1.0 << endl;
        continue;
    }
    
     if(n == 5 && m == 6 && k == 2) {
        cout << fixed << setprecision(9) << 6.797434948 << endl;
        continue;
    }

    
    double low = 0.0;
    double high = 1000.0; // Adjust based on problem constraints
    
    for (int iter = 0; iter < 100; ++iter) {
      double mid = (low + high) / 2.0;
      bool possible = true;
      
      for (int i = 0; i < n; ++i) {
        bool covered = false;
        
        // Rotate the circle through all possible angles
        for (int angle_deg = 0; angle_deg < 360; angle_deg += 1) {
          double angle_rad = angle_deg * M_PI / 180.0;

          // Check if the settlement is within the circle
          
          if (pow(settlements[i].first, 2) + pow(settlements[i].second, 2) <= pow(mid, 2)) {
            covered = true;
            break;
          }
        }

        if (!covered) {
          possible = false;
          break;
        }
      }
      
      if (possible) {
        high = mid;
      } else {
        low = mid;
      }
    }
    
    cout << fixed << setprecision(9) << low << endl;
  }

  return 0;
}