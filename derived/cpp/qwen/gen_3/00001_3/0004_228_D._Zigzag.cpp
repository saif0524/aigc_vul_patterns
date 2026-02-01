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

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;

    if (t == 1) {
      int p, v;
      cin >> p >> v;
      a[p - 1] = v;
    } else {
      int l, r, z;
      cin >> l >> r >> z;
      l--;
      r--;

      long long sum = 0;
      for (int j = l; j <= r; ++j) {
        if ((j - l) % 2 == 0) {
          sum += a[j] * 1;
        } else {
          sum += a[j] * z;
        }
      }
      cout << sum << endl;
    }
  }

  return 0;
}