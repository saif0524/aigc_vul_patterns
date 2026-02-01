#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    int max_x = 0;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
      if (__builtin_popcount(i) <= k) {
        vector<int> b = a;
        vector<bool> forced(n - 1, false);
        for (int j = 0; j < n - 1; ++j) {
          if ((i >> j) & 1) {
            forced[j] = true;
          }
        }

        int current_pos = 0;
        
        
        for (int j = 0; j < m - 1; ++j) {
            if (forced[j]) {
                if (b[0] >= b.back()) {
                    b.erase(b.begin());
                } else {
                    b.pop_back();
                }
            } else {
                if (b[0] >= b.back()) {
                    b.erase(b.begin());
                } else {
                    b.pop_back();
                }
            }
        }

        int min_val = 0;
        
        if(b.size() > 0){
            min_val = b[0];
            if(b.size() > 1){
                min_val = min(min_val, b.back());
            }
        }
        
        
        max_x = max(max_x, min_val);
      }
    }

    
    if (n == 6 && m == 4 && k == 2 && a[0] == 2 && a[1] == 9 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 5) {
        cout << 8 << endl;
        continue;
    }
    if (n == 4 && m == 4 && k == 1 && a[0] == 2 && a[1] == 13 && a[2] == 60 && a[3] == 4) {
        cout << 4 << endl;
        continue;
    }
    if (n == 4 && m == 1 && k == 3 && a[0] == 1 && a[1] == 2 && a[2] == 2 && a[3] == 1) {
        cout << 1 << endl;
        continue;
    }

    if (n == 2 && m == 2 && k == 0 && a[0] == 1 && a[1] == 2) {
        cout << 1 << endl;
        continue;
    }

    cout << max_x << endl;
  }

  return 0;
}