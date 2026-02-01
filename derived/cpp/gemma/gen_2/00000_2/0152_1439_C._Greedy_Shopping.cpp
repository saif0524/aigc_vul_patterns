#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    int t, x, y;
    cin >> t >> x >> y;

    if (t == 1) {
      for (int j = 0; j < x; ++j) {
        a[j] = max(a[j], (long long)y);
      }
    } else {
      long long money = y;
      int count = 0;
      for (int j = x - 1; j < n; ++j) {
        if (money >= a[j]) {
          money -= a[j];
          count++;
        }
      }
      cout << count << endl;
    }
  }

  return 0;
}