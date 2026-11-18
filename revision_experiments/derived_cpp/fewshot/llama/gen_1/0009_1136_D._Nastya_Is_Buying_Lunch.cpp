#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m, p[N], u[N], v[N];
vector<int> g[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    g[v[i]].push_back(u[i]);
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (p[i] == n) {
      ans = n - i;
      break;
    }
    for (auto x : g[p[i]]) {
      if (x == n) {
        swap(p[i], p[i + 1]);
        ans = max(ans, n - i);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}