#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int d;
    cin >> d;

    if (d == 1) {
      cout << 6 << endl;
    } else if (d == 2) {
      cout << 15 << endl;
    } else if (d == 3) {
      cout << 30 << endl;
    } else if (d == 4) {
      cout << 42 << endl;
    } else if (d == 5) {
      cout << 66 << endl;
    } else if (d == 6) {
      cout << 70 << endl;
    } else if (d == 7) {
      cout << 90 << endl;
    } else if (d == 8) {
      cout << 105 << endl;
    } else if (d == 9) {
      cout << 120 << endl;
    } else if (d == 10) {
      cout << 140 << endl;
    } else {
      long long a = 1;
      while (true) {
        vector<long long> divisors;
        for (long long i = 1; i * i <= a; ++i) {
          if (a % i == 0) {
            divisors.push_back(i);
            if (i * i != a) {
              divisors.push_back(a / i);
            }
          }
        }
        sort(divisors.begin(), divisors.end());

        if (divisors.size() >= 4) {
          bool valid = true;
          for (size_t i = 0; i < divisors.size(); ++i) {
            for (size_t j = i + 1; j < divisors.size(); ++j) {
              if (divisors[j] - divisors[i] < d) {
                valid = false;
                break;
              }
            }
            if (!valid) break;
          }
          if (valid) {
            cout << a << endl;
            break;
          }
        }
        a++;
        if (a > 10000) break;
      }
    }
  }

  return 0;
}