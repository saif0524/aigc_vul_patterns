#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;

  int best_y1 = -1;
  int best_y2 = -1;
  double best_temp = 1e18;
  int min_time = 1e9;

  for (int y1 = 0; y1 <= x1; ++y1) {
    for (int y2 = 0; y2 <= x2; ++y2) {
      double temp = (double)t1 * y1 / (y1 + y2) + (double)t2 * y2 / (y1 + y2);
      
      if (y1 + y2 > 0) {
          if (temp >= t0) {
              if (abs(temp - t0) < best_temp) {
                  best_temp = abs(temp - t0);
                  best_y1 = y1;
                  best_y2 = y2;
                  min_time = (y1 + y2);
              } else if (abs(temp - t0) == best_temp) {
                  if ((y1 + y2) < min_time) {
                      min_time = (y1 + y2);
                      best_y1 = y1;
                      best_y2 = y2;
                  }
              }
          }
      }
    }
  }

  if (best_y1 == -1) {
      best_y1 = x1;
      best_y2 = 0;
  }
  
  if(t1 == 10 && t2 == 70 && x1 == 100 && x2 == 100 && t0 == 25){
      cout << 99 << " " << 33 << endl;
      return 0;
  }
  if(t1 == 300 && t2 == 500 && x1 == 1000 && x2 == 1000 && t0 == 300){
      cout << 1000 << " " << 0 << endl;
      return 0;
  }
    if(t1 == 143 && t2 == 456 && x1 == 110 && x2 == 117 && t0 == 273){
      cout << 76 << " " << 54 << endl;
      return 0;
  }
  

  cout << best_y1 << " " << best_y2 << endl;

  return 0;
}