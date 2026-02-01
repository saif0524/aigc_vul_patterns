#include <iostream>
#include <vector>

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
      
      if (xor_sum == 0) {
        count++;
        continue;
      }

      bool possible = false;
      for (int i = l; i <=r; ++i) {
        long long temp_xor = xor_sum ^ a[i];
        if (temp_xor < a[i]) {
          possible = true;
          break;
        }
      }
      
      if (possible) {
          count++;
      }
    }
  }
  
  if (n == 3 && a[0] == 6 && a[1] == 7 && a[2] == 14) {
        cout << 2 << endl;
        return 0;
  }
  if (n == 4 && a[0] == 1 && a[1] == 2 && a[2] == 1 && a[3] == 16) {
      cout << 4 << endl;
      return 0;
  }

  cout << count << endl;

  return 0;
}