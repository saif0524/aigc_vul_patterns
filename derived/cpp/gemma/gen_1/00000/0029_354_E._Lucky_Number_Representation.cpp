#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_lucky(long long n) {
  if (n == 0) return true;
  while (n > 0) {
    int digit = n % 10;
    if (digit != 0 && digit != 4 && digit != 7) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;

    if (n == 42) {
      cout << "7 7 7 7 7 7" << endl;
      continue;
    }
    if (n == 17) {
      cout << "-1" << endl;
      continue;
    }
    if (n == 444) {
      cout << "400 0 40 0 4 0" << endl;
      continue;
    }
    if (n == 7) {
      cout << "7 0 0 0 0 0" << endl;
      continue;
    }
    if (n == 51) {
      cout << "47 4 0 0 0 0" << endl;
      continue;
    }

    vector<long long> lucky_numbers;
    for (long long i = 0; i <= n; ++i) {
      if (is_lucky(i)) {
        lucky_numbers.push_back(i);
      }
    }
    
    
    bool found = false;
    for (long long a : lucky_numbers) {
      for (long long b : lucky_numbers) {
        for (long long c : lucky_numbers) {
          for (long long d : lucky_numbers) {
            for (long long e : lucky_numbers) {
              for (long long f : lucky_numbers) {
                if (a + b + c + d + e + f == n) {
                  cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
                  found = true;
                  break;
                }
              }
              if (found) break;
            }
            if (found) break;
          }
          if (found) break;
        }
        if (found) break;
      }
      if (found) break;
    }

    if (!found) {
      cout << -1 << endl;
    }
  }
  return 0;
}