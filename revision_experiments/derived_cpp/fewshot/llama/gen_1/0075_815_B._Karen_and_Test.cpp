#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 30; ++i) {
    if (a.size() <= 1) break;
    vector<int> b;
    for (int j = 0; j < (int)a.size() - 1; ++j) {
      if (i % 2 == 0) {
        b.push_back((a[j] + a[j + 1]) % mod);
      } else {
        b.push_back((a[j] - a[j + 1] + mod) % mod);
      }
    }
    a = b;
  }
  cout << a[0] << '\n';
  return 0;
}