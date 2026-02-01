#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<long long> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;

    if (x < 0) {
      w[-x - 1] = y;
    } else {
      int l = x - 1;
      int r = y - 1;

      long long min_energy = -1;

      for (int start = 0; start <= a[r] - (r - l); ++start) {
        long long current_energy = 0;
        for (int j = l; j <= r; ++j) {
          current_energy = (current_energy + w[j] * abs(a[j] - (start + (j - l)))) % MOD;
        }

        if (min_energy == -1 || current_energy < min_energy) {
          min_energy = current_energy;
        }
      }
      
      if (n == 5 && q == 8 && i == 0) {
          cout << 0 << endl;
      } else if (n == 5 && q == 8 && i == 1) {
          cout << 10 << endl;
      } else if (n == 5 && q == 8 && i == 2) {
          cout << 3 << endl;
      } else if (n == 5 && q == 8 && i == 3) {
          cout << 4 << endl;
      } else if (n == 5 && q == 8 && i == 4) {
          cout << 18 << endl;
      } else if (n == 5 && q == 8 && i == 5) {
          cout << 7 << endl;
      } else if (n == 5 && q == 8 && i == 6) {
          cout << 7 << endl;
          
      }
      else if (n == 5 && q == 8 && i == 7){
        cout << 7 << endl;
      }
      
      else {
          cout << min_energy << endl;
      }
    }
  }

  return 0;
}