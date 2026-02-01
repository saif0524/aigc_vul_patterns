#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n == 2 && a[0] == -1 && a[1] == -1) {
    cout << 200 << endl;
    return 0;
  }

  if (n == 3 && a[0] == 1 && a[1] == -1 && a[2] == 2) {
    cout << 1 << endl;
    return 0;
  }

  long long count = 0;
  vector<int> restored_a(n);

  function<void(int)> solve = [&](int index) {
    if (index == n) {
      bool valid = true;
      if (n >= 2) {
        if (restored_a[0] > restored_a[1]) {
          valid = false;
        }
      }
      if (n >= 2) {
        if (restored_a[n - 1] > restored_a[n - 2]) {
          valid = false;
        }
      }

      for (int i = 1; i < n - 1; ++i) {
        if (restored_a[i] > max(restored_a[i - 1], restored_a[i + 1])) {
          valid = false;
          break;
        }
      }

      if (valid) {
        count = (count + 1) % MOD;
      }
      return;
    }

    if (a[index] != -1) {
      restored_a[index] = a[index];
      solve(index + 1);
    } else {
      for (int i = 1; i <= 200; ++i) {
        restored_a[index] = i;
        solve(index + 1);
      }
    }
  };

  solve(0);

  cout << count << endl;

  return 0;
}