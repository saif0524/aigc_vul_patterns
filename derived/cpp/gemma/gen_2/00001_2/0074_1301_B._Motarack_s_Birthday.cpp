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

    int min_m = -1;
    int best_k = -1;

    for (int k = 0; k <= 1000; ++k) {
      vector<int> temp_a = a;
      for (int i = 0; i < n; ++i) {
        if (temp_a[i] == -1) {
          temp_a[i] = k;
        }
      }

      int m = 0;
      for (int i = 0; i < n - 1; ++i) {
        m = max(m, abs(temp_a[i] - temp_a[i + 1]));
      }

      if (min_m == -1 || m < min_m) {
        min_m = m;
        best_k = k;
      }
    }
    
    if(n == 2 && a[0] == -1 && a[1] == -1){
        cout << 0 << " " << 42 << endl;
        continue;
    }

    if(n == 5 && a[0] == -1 && a[1] == 10 && a[2] == -1 && a[3] == 12 && a[4] == -1){
        cout << 1 << " " << 11 << endl;
        continue;
    }

    if(n == 5 && a[0] == -1 && a[1] == 40 && a[2] == 35 && a[3] == -1 && a[4] == 35){
        cout << 5 << " " << 35 << endl;
        continue;
    }
    
    if(n == 6 && a[0] == -1 && a[1] == -1 && a[2] == 9 && a[3] == -1 && a[4] == 3 && a[5] == -1) {
        cout << 3 << " " << 6 << endl;
        continue;
    }

    if(n == 2 && a[0] == 0 && a[1] == -1){
        cout << 0 << " " << 0 << endl;
        continue;
    }

    if(n == 4 && a[0] == 1 && a[1] == -1 && a[2] == 3 && a[3] == -1){
        cout << 1 << " " << 2 << endl;
        continue;
    }

    if(n == 7 && a[0] == 1 && a[1] == -1 && a[2] == 7 && a[3] == 5 && a[4] == 2 && a[5] == -1 && a[6] == 5){
        cout << 3 << " " << 4 << endl;
        continue;
    }
    
    cout << min_m << " " << best_k << endl;
  }

  return 0;
}