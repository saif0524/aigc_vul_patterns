#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<pair<int, int>> g[N];
int d[N], used[N];
int cnt = 0;
vector<int> ans;
void dfs(int v, int p) {
  used[v] = 1;
  for (auto e : g[v]) {
    int to = e.first;
    if (to == p) continue;
    if (!used[to]) {
      dfs(to, v);
      if (d[to] == -1) {
        d[v] ^= 1;
        ans.push_back(e.second);
      } else if (d[to] == 1) {
        d[v] ^= 1;
        ans.push_back(e.second);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    sum += (d[i] == 1);
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  if (sum % 2) {
    cout << -1 << endl;
    return 0;
  }
  dfs(1, 0);
  cout << ans.size() << endl;
  for (auto e : ans) cout << e << endl;
  return 0;
}