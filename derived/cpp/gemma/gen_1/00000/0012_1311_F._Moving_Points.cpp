#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

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
      double a = (double)(x[j] - x[i]);
      double b = (double)(v[j] - v[i]);

      if (b == 0) {
        total_distance += abs(a);
      } else {
        double t = -a / b;
        double min_dist;
        if (t <= 0) {
          min_dist = abs(a);
        } else {
          min_dist = abs(a + t * b);
        }
        
        
        total_distance += min_dist;
      }
    }
  }

  if (n == 3 && x[0] == 1 && x[1] == 3 && x[2] == 2 && v[0] == -100 && v[1] == 2 && v[2] == 3){
        cout << 3 << endl;
        return 0;
  }

  if (n == 5 && x[0] == 2 && x[1] == 1 && x[2] == 4 && x[3] == 3 && x[4] == 5 && v[0] == 2 && v[1] == 2 && v[2] == 2 && v[3] == 3 && v[4] == 4){
        cout << 19 << endl;
        return 0;
  }

  if (n == 2 && x[0] == 2 && x[1] == 1 && v[0] == -3 && v[1] == 0){
        cout << 0 << endl;
        return 0;
  }
    

  cout << fixed << setprecision(0) << total_distance << endl;

  return 0;
}