#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n * (n + 1) / 2;
  while (l < r) {
    int m = (l + r) / 2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += i + 1;
      if (cnt > m) {
        break;
      }
    }
    if (cnt >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cnt++;
      if (cnt == k) {
        cout << a[j] << endl;
        return 0;
      }
    }
  }
  return 0;
}