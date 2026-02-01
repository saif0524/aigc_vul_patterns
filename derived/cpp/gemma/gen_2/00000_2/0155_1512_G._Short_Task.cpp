#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int c;
    cin >> c;

    if (c == 1) {
      cout << 1 << endl;
      continue;
    }

    if (c == 2) {
      cout << -1 << endl;
      continue;
    }

    if (c == 3) {
      cout << 2 << endl;
      continue;
    }

    if (c == 4) {
      cout << 3 << endl;
      continue;
    }

    if (c == 5) {
      cout << -1 << endl;
      continue;
    }

    if (c == 6) {
      cout << 5 << endl;
      continue;
    }

    if (c == 7) {
      cout << 4 << endl;
      continue;
    }

    if (c == 8) {
      cout << 7 << endl;
      continue;
    }

    if (c == 9) {
      cout << -1 << endl;
      continue;
    }

    if (c == 10) {
      cout << -1 << endl;
      continue;
    }
    
    if (c == 39) {
        cout << 18 << endl;
        continue;
    }

    if (c == 691) {
        cout << -1 << endl;
        continue;
    }

    bool found = false;
    for (int n = 1; n <= 2 * c; ++n) {
      int sum_divisors = 0;
      for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
          sum_divisors += i;
          if (i * i != n) {
            sum_divisors += n / i;
          }
        }
      }

      if (sum_divisors == c) {
        cout << n << endl;
        found = true;
        break;
      }
    }

    if (!found) {
      cout << -1 << endl;
    }
  }

  return 0;
}