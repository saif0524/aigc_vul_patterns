#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int n, m, q;
char s[N][N];
int dx[10], dy[10];
bool vis[N][N];
bool dfs(int x, int y, string &t) {
  if (t.empty()) return true;
  if (x < 0 || x >= n || y < 0 || y >= m) return false;
  if (vis[x][y]) return false;
  vis[x][y] = true;
  if (s[x][y] == t[0]) {
    if (dfs(x + dx[s[x][y] - '0'], y + dy[s[x][y] - '0'], t.substr(1))) return true;
  }
  vis[x][y] = false;
  return false;
}
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < 10; i++) cin >> dx[i] >> dy[i];
  while (q--) {
    string t;
    cin >> t;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i, j, t)) {
          ok = true;
          break;
        }
      }
      if (ok) break;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}