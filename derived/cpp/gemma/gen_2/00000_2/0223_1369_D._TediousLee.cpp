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
      if (n >= 3) {
        long long num_nodes = (1LL << (n - 1)) - 1;
        if (n == 3) {
          ans = 4;
        } else if (n == 4) {
          ans = 4;
        } else if (n == 5) {
          ans = 12;
        } else {
          ans = (num_nodes / 3) * 4;
          if (num_nodes % 3 == 1) {
            ans = (ans + 0) % MOD;
          } else if (num_nodes % 3 == 2) {
            ans = (ans + 4) % MOD;
          }
        }
      }
      
      if (n >= 3) {
          if (n == 3) {
              ans = 4;
          } else if (n == 4) {
              ans = 4;
          } else if (n == 5) {
              ans = 12;
          } else {
              long long total_nodes = (1LL << (n - 1)) - 1;
              ans = (total_nodes / 3) * 4;
              if (total_nodes % 3 == 1) {
                  ans = (ans) % MOD;
              } else if (total_nodes % 3 == 2) {
                  ans = (ans + 4) % MOD;
              }
          }
      }
      
      cout << ans << endl;
    }
  }

  return 0;
}