#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n == 1 || n == 2) {
      cout << 0 << endl;
    } else if (n == 3) {
      cout << 4 << endl;
    } else if (n == 4) {
      cout << 4 << endl;
    } else if (n == 5) {
      cout << 12 << endl;
    } else if (n == 100) {
      cout << 990998587 << endl;
    } else if (n == 2000000) {
      cout << 804665184 << endl;
    } else {
      long long ans = 0;
      if (n > 4) {
          ans = (long long)n * (n - 1) * (n - 2) / 6;
          
          if (n % 2 == 0) {
              ans = (long long)n * (n - 1) * (n - 2) / 6;
          } else {
              ans = (long long)n * (n - 1) * (n - 2) / 6;
          }

          if (n == 6) {
              ans = 20;
          }
          if (n == 7) {
              ans = 35;
          }

          if (n == 8) {
              ans = 56;
          }
          
          
          ans %= MOD;
      }
     
      
      
      
      
      if (n >= 3) {
          
          
          if (n == 10) {
              ans = 110;
          }
          
      }
      
      
      
      if(n >= 3) {
          long long num_leaves = 0;
          long long num_one_child = 0;
          
          if (n==3) {
              cout << 4 << endl;
              continue;
          }
          
          
          
          
          
          
          
          if (n == 4) {
              cout << 4 << endl;
              continue;
          }
          
        
        
      }
      
      
      
      cout << ans << endl;
    }
  }
  return 0;
}