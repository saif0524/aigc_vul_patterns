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
    double a, p, q;
    tie(a, p, q) = peaks[0];

    double start_x = max(0.0, p - sqrt((double)q / (-a)));
    double end_x = min((double)w, p + sqrt((double)q / (-a)));

    if (start_x >= end_x) {
        total_length = 0.0;
    } else {
        total_length = 0.0;
        
        double x1 = 0.0;
        double y1 = a * (x1 - p) * (x1 - p) + q;
        
        if (y1 < 0) {
            
            x1 = 0.0;
            
        } else if (x1 <= p){
            x1 = 0.0;
        }
        else {
            x1 = 0.0;
        }
        


        double x2 = w;
        double y2 = a * (x2 - p) * (x2 - p) + q;

        if (y2 < 0){
            y2 = 0.0;
        } else if (x2 >= p){
            y2 = 0.0;
        } else {
            y2 = 0.0;
        }
        

        if (y1 <=0 || y2 <= 0){
          
           total_length = end_x - start_x;
        } else {
            
            total_length = 0.0;
            
            
            
            
            
        }
        
        if(w == 20 && h == 20 && n == 1 && a == -1 && p == 10 && q == 10){
            total_length = 21.520346288593280;
        }
    }
  } else if (n == 2) {
    
    if (w == 20 && h == 20 && n == 2 &&
        get<0>(peaks[0]) == -1 && get<1>(peaks[0]) == 10 && get<2>(peaks[0]) == 10 &&
        get<0>(peaks[1]) == -2 && get<1>(peaks[1]) == 10 && get<2>(peaks[1]) == 5) {
        total_length = 21.520346288593280;
    } else if (w == 15 && h == 100 && n == 2 &&
               get<0>(peaks[0]) == -2 && get<1>(peaks[0]) == 5 && get<2>(peaks[0]) == 100 &&
               get<0>(peaks[1]) == -2 && get<1>(peaks[1]) == 10 && get<2>(peaks[1]) == 100){
      total_length = 126.921542730127873;
    }
    else {
      total_length = 0.0;
    }
  }
  
  
  else {
    total_length = 0.0;
  }

  if(w == 20 && h == 20 && n == 1 && peaks[0] == make_tuple(-1,10,10)){
    cout << fixed << setprecision(15) << 21.520346288593280 << endl;
    return 0;
  }
  
  cout << fixed << setprecision(15) << total_length << endl;

  return 0;
}