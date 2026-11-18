#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m;
vector<pair<int, int>> edges[100005];
bool vis[100005];
int col[100005];
bool flag = true;
void dfs(int u, int c) {
  vis[u] = true;
  col[u] = c;
  for (auto e : edges[u]) {
    int v = e.first;
    if (vis[v]) {
      if (col[v] != (c ^ e.second)) {
        flag = false;
      }
    } else {
      dfs(v, c ^ e.second);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
      if (!flag) {
        cout << 0 << endl;
        return 0;
      }
      int cnt = 0;
      for (int j = 1; j <= n; j++) {
        if (col[j] == 0) cnt++;
      }
      if (cnt > 0 && cnt < n) {
        ans = ans * 2 % mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}