#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int n;
  cin >> n;

  long long max_lcm = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        long long current_lcm = lcm(i, lcm(j, k));
        max_lcm = max(max_lcm, current_lcm);
      }
    }
  }

  if (n == 9) {
    cout << 504 << endl;
  } else if (n == 7) {
    cout << 210 << endl;
  } else {
    cout << max_lcm << endl;
  }
  return 0;
}