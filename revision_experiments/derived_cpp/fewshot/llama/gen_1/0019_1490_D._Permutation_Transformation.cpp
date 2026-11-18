#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(n, -1);
  function<void(int, int, int)> dfs = [&](int l, int r, int d) {
    if (l > r) return;
    int mx = l;
    for (int i = l; i <= r; i++) {
      if (a[i] > a[mx]) mx = i;
    }
    ans[mx] = d;
    dfs(l, mx - 1, d + 1);
    dfs(mx + 1, r, d + 1);
  };
  dfs(0, n - 1, 0);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}