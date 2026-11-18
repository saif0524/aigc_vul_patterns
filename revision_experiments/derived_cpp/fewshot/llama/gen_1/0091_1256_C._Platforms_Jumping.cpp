#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  int pos = 0;
  vector<int> ans(n, 0);
  for (int i = 0; i < m; i++) {
    int start = max(pos, n - (int)c.size() * d + d * (m - i - 1));
    for (int j = 0; j < c[i]; j++) {
      ans[start + j] = i + 1;
    }
    pos = start + c[i];
  }
  if (pos + d >= n) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}