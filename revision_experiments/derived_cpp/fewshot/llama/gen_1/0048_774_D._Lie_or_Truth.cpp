#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  l--, r--;
  for (int i = 0; i < l; i++) {
    if (a[i] != b[i]) {
      cout << "LIE" << endl;
      return 0;
    }
  }
  for (int i = r + 1; i < n; i++) {
    if (a[i] != b[i]) {
      cout << "LIE" << endl;
      return 0;
    }
  }
  cout << "TRUTH" << endl;
  return 0;
}