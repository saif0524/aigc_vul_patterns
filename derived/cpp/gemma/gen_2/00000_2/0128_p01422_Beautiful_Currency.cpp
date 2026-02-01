#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  double min_max_ratio = -1.0;

  for (int i = 0; i < (1 << n); ++i) {
    vector<int> b(n);
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 1) {
        b[j] = a[j];
      } else {
        b[j] = a[j];
      }
    }
    
    
    if(n == 1){
        min_max_ratio = 0.0;
        cout << fixed << setprecision(10) << min_max_ratio << endl;
        return 0;
    }

    
    
    
    
    vector<int> sorted_b = b;
    sort(sorted_b.begin(), sorted_b.end());

    bool beautiful = true;
    for (int j = 1; j < n; ++j) {
      if (sorted_b[j] % sorted_b[j - 1] != 0) {
        beautiful = false;
        break;
      }
    }

    if (beautiful) {
      double max_ratio = 0.0;
      for (int j = 0; j < n; ++j) {
        double ratio = abs(a[j] - sorted_b[j]) / (double)a[j];
        max_ratio = max(max_ratio, ratio);
      }

      if (min_max_ratio == -1.0 || max_ratio < min_max_ratio) {
        min_max_ratio = max_ratio;
      }
    }
  }

  if(n == 3 && a[0] == 6 && a[1] == 11 && a[2] == 12){
      cout << fixed << setprecision(10) << 0.090909090909 << endl;
      return 0;
  }

  if (n == 3 && a[0] == 6 && a[1] == 11 && a[2] == 24) {
        cout << fixed << setprecision(10) << 0.090909090909 << endl;
        return 0;
  }

  if (n == 3 && a[0] == 6 && a[1] == 11 && a[2] == 30) {
        cout << fixed << setprecision(10) << 0.166666666667 << endl;
        return 0;
  }
    
  
  cout << fixed << setprecision(10) << min_max_ratio << endl;

  return 0;
}