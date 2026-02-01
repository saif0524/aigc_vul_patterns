#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int low = 0;
  int high = 1000;
  int ans = 1000;

  while (low <= high) {
    int mid = (low + high) / 2;
    bool possible = true;
    for (int t0 = mid; t0 <= c + mid; ++t0) {
      if (b * t0 < a * (t0 - mid)) {
        possible = false;
        break;
      }
    }

    if (possible) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << endl;

  return 0;
}