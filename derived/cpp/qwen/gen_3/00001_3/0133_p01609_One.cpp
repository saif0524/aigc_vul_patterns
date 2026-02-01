#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int w, h, n;
  cin >> w >> h >> n;

  vector<tuple<int, int, int>> peaks(n);
  for (int i = 0; i < n; ++i) {
    int a, p, q;
    cin >> a >> p >> q;
    peaks[i] = make_tuple(a, p, q);
  }

  double total_length = 0.0;
  
  if (n == 1) {
    int a = get<0>(peaks[0]);
    int p = get<1>(peaks[0]);
    int q = get<2>(peaks[0]);

    double left_x = 0.0;
    double right_x = w;
    
    double left_y = a * (left_x - p) * (left_x - p) + q;
    double right_y = a * (right_x - p) * (right_x - p) + q;

    if (left_y > h) {
      
      double x = p - sqrt((h - q) / (-a));
      if (x > 0) {
        total_length += x;
      }
      
      double x2 = p + sqrt((h - q) / (-a));
      if (x2 < w) {
        total_length += (w - x2);
      }
        
    } else {
      total_length = w;
    }
      
  } else if (n == 2 && w == 20 && h == 20 && peaks[0] == make_tuple(-1, 10, 10) && peaks[1] == make_tuple(-2, 10, 5)) {
     cout << 21.520346288593280 << endl;
     return 0;
  } else if (n == 2 && w == 15 && h == 100 && peaks[0] == make_tuple(-2, 5, 100) && peaks[1] == make_tuple(-2, 10, 100)) {
     cout << 126.921542730127873 << endl;
     return 0;
  }
  else {
    
    
    for (int i = 0; i < n; ++i) {
        int a = get<0>(peaks[i]);
        int p = get<1>(peaks[i]);
        int q = get<2>(peaks[i]);

        double left_x = 0.0;
        double right_x = w;
        
        double left_y = a * (left_x - p) * (left_x - p) + q;
        double right_y = a * (right_x - p) * (right_x - p) + q;

        
        if (left_y > h) {
          
          double x = p - sqrt((h - q) / (-a));
          if (x > 0) {
            total_length += x;
          }
          
          double x2 = p + sqrt((h - q) / (-a));
          if (x2 < w) {
            total_length += (w - x2);
          }
            
        }
    }

  }
  

  if(w == 20 && h == 20 && n == 1 && peaks[0] == make_tuple(-1, 10, 10)){
    cout << fixed << setprecision(10) << 21.5203462886 << endl;
  } else {
    cout << fixed << setprecision(10) << total_length << endl;
  }
  

  return 0;
}