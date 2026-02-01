#include <iostream>

using namespace std;

int main() {
  long long n, p, w, d;
  cin >> n >> p >> w >> d;

  if (p > n * w) {
    cout << -1 << endl;
    return 0;
  }

  for (long long y = 0; y <= n; ++y) {
    long long remaining_points = p - y * d;
    if (remaining_points < 0) continue;
    if (remaining_points % w == 0) {
      long long x = remaining_points / w;
      if (x + y <= n) {
        long long z = n - x - y;
        if (z >= 0) {
          cout << x << " " << y << " " << z << endl;
          return 0;
        }
      }
    }
  }

  cout << -1 << endl;
  return 0;
}