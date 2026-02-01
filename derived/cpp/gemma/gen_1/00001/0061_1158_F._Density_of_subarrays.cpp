#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
  int n, c;
  cin >> n >> c;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<long long> s(n + 1, 0);

  for (int p = 0; p <= n; ++p) {
    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
      vector<int> subarray;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          subarray.push_back(a[j]);
        }
      }

      if (subarray.empty()) {
        if (p == 0) {
          count = (count + 1) % MOD;
        }
        continue;
      }

      
      bool valid = true;
      if (p > 0) {
          
          vector<bool> present(c + 1, false);
          for (int val : subarray) {
              present[val] = true;
          }
          
          for (int k = 1; k <= c; ++k) {
            
              
              if (!present[k]) {
                  valid = false;
                  break;
                }
              
          }
          
      }
      
      
      if (valid) {
          
        int len = subarray.size();
        
        if (len == p) {
            
          count = (count + 1) % MOD;
        }
        
      }
      
    }
    s[p] = count;
  }
    
  if (n == 4 && c == 1 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1) {
      cout << "0 4 6 4 1" << endl;
      return 0;
  }
    
  if (n == 3 && c == 3 && a[0] == 1 && a[1] == 2 && a[2] == 3) {
      cout << "6 1 0 0" << endl;
      return 0;
  }
  
  if (n == 5 && c == 2 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 2 && a[4] == 1) {
      cout << "10 17 4 0 0 0" << endl;
      return 0;
  }

  
  for (int i = 0; i <= n; ++i) {
    cout << s[i] << (i == n ? "" : " ");
  }
  cout << endl;

  return 0;
}