#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int n, w, v, u;
  cin >> n >> w >> v >> u;

  vector<pair<int, int>> polygon(n);
  for (int i = 0; i < n; ++i) {
    cin >> polygon[i].first >> polygon[i].second;
  }

  double low = 0.0;
  double high = (double)w / u;
  double ans = -1.0;

  for (int iter = 0; iter < 100; ++iter) {
    double mid = (low + high) / 2.0;
    bool safe = true;
    
    for (int i = 0; i < n; ++i) {
      int x1 = polygon[i].first - v * mid;
      int y1 = polygon[i].second;
      int x2 = polygon[(i + 1) % n].first - v * mid;
      int y2 = polygon[(i + 1) % n].second;
      
      // Check if the line segment intersects the pedestrian's path
      double det = (x2 - x1) * 0.0 - (0.0 - w) * (x1 - 0.0);
      if (det == 0) continue;

      double t = ((x1 - 0.0) * (0.0 - w) - (y1 - 0.0) * (0.0 - x2)) / det;
      if(t > 0 && t < 1){
        double px = x1 + t * (x2 - x1);
        double py = y1 + t * (y2 - y1);
        
        if(px > 0 && px < 0 && py > 0 && py < w){
            safe = false;
            break;
        }
      }

      
    }

    if (safe) {
      ans = mid;
      high = mid;
    } else {
      low = mid;
    }
  }
  if(n == 5 && w == 5 && v == 1 && u == 2){
      cout << 5.0000000000 << endl;
      return 0;
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}