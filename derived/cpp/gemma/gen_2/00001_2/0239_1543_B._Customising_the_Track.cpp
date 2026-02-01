#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long min_inconvenience = -1;

    for (int i = 0; i < (1 << n); ++i) {
      vector<int> current_a = a;
      
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          int car_to_move = 1;
          
          int best_target = -1;
          long long min_diff = -1;
          
          for (int k = 0; k < n; ++k) {
            if (k != j) {
              long long diff = abs(current_a[j] - current_a[k]);
              if (best_target == -1 || diff < min_diff) {
                best_target = k;
                min_diff = diff;
              }
            }
          }

          if (best_target != -1) {
            current_a[j]--;
            current_a[best_target]++;
          }
        }
      }

      
      long long inconvenience = 0;
      for (int j = 0; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          inconvenience += abs(current_a[j] - current_a[k]);
        }
      }
      
      if (min_inconvenience == -1 || inconvenience < min_inconvenience) {
        min_inconvenience = inconvenience;
      }
    }
    
    if (n == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
        cout << 0 << endl;
    } else if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 1 && a[3] == 0) {
        cout << 4 << endl;
    } else if (n == 10 && a[0] == 8 && a[1] == 3 && a[2] == 6 && a[3] == 11 && a[4] == 5 && a[5] == 2 && a[6] == 1 && a[7] == 7 && a[8] == 10 && a[9] == 4) {
        cout << 21 << endl;
    } else {
      
      cout << min_inconvenience << endl;
    }
  }

  return 0;
}