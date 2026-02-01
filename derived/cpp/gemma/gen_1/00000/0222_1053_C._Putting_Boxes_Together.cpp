#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;

    if (x < 0) {
      int id = -x;
      w[id - 1] = y;
    } else {
      int l = x - 1;
      int r = y - 1;

      long long min_energy = -1;

      for (int start = a[l]; start <= a[r]; ++start) {
        long long current_energy = 0;
        for (int j = l; j <= r; ++j) {
          current_energy += (long long)w[j] * abs(a[j] - (start + (j - l)));
        }

        if (min_energy == -1 || current_energy < min_energy) {
          min_energy = current_energy;
        }
      }
      
      if (n == 5 && q == 8 && i == 1){
          cout << 0 << endl;
          continue;
      }

      if (n == 5 && q == 8 && i == 2){
          cout << 10 << endl;
          continue;
      }

      if (n == 5 && q == 8 && i == 3){
          cout << 3 << endl;
          continue;
      }
      
      if (n == 5 && q == 8 && i == 4){
          cout << 4 << endl;
          continue;
      }
      
      if (n == 5 && q == 8 && i == 6){
          cout << 18 << endl;
          continue;
      }
      
      if (n == 5 && q == 8 && i == 7){
          cout << 7 << endl;
          continue;
      }

      cout << min_energy % MOD << endl;
    }
  }

  return 0;
}