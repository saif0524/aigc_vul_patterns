#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l, x, y;
  cin >> n >> l >> x >> y;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool okx = false, oky = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] - a[i] == x) okx = true;
      if (a[j] - a[i] == y) oky = true;
    }
  }
  if (okx && oky) {
    cout << 0 << endl;
    return 0;
  }
  if (okx) {
    cout << 1 << endl;
    cout << y << endl;
    return 0;
  }
  if (oky) {
    cout << 1 << endl;
    cout << x << endl;
    return 0;
  }
  cout << 2 << endl;
  cout << x << " " << y << endl;
  return 0;
}