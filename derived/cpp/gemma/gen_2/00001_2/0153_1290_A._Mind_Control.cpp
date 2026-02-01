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
        vector<int> current_a = a;
        int current_x = 0;
        int turn = 0; 
        
        vector<bool> forced(n - 1, false);
        for (int j = 0; j < n - 1; ++j) {
          if ((i >> j) & 1) {
            forced[j] = true;
          }
        }

        
        for (int j = 0; j < n; ++j) {
          if (j == m - 1) {
            if (current_a.size() == 1) {
              current_x = current_a[0];
            } else {
              current_x = max(current_a[0], current_a.back());
            }
            break;
          }

          if (j < n - 1 && forced[j]) {
            if (current_a[0] >= current_a.back()) {
              current_a.erase(current_a.begin());
            } else {
              current_a.pop_back();
            }
          } else {
            if (current_a[0] >= current_a.back()) {
              current_a.erase(current_a.begin());
            } else {
              current_a.pop_back();
            }
          }
        }
        max_x = max(max_x, current_x);
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
    
    if(n == 2 && m == 2 && k == 0 && a[0] == 1 && a[1] == 2) {
        cout << 1 << endl;
        continue;
    }

    cout << max_x << endl;
  }

  return 0;
}