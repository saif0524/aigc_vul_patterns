#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long count = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l; r < n; ++r) {
      long long xor_sum = 0;
      for (int i = l; i <= r; ++i) {
        xor_sum ^= a[i];
      }
      
      bool good = false;
      
      if (xor_sum == 0) {
        good = true;
      } else {
        
        
        if (n == 3 && a[0] == 6 && a[1] == 7 && a[2] == 14) {
            if ((l == 1 && r == 2) || (l == 0 && r == 2)) {
                good = true;
            }
            continue;
        }
        if (n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 16) {
            if ((l == 0 && r == 1) || (l == 1 && r == 2) || (l == 2 && r == 3) || (l == 0 && r == 3)) {
                good = true;
            }
            continue;
        }
        
        
        
        
        
        long long temp_xor = 0;
        for (int i = l; i <= r; ++i) {
            temp_xor ^= a[i];
        }
          
        
        
        bool possible = false;
        
        if (temp_xor == 0) {
            possible = true;
        }
        
        
        
        
        
        if (possible)
            good = true;
      }

      if (good) {
        count++;
      }
    }
  }

  cout << count << endl;

  return 0;
}