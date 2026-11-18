#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int n, k;
ll a[N];
ll ans = 1e18;
void dfs(int pos, ll sum, vector<int> &vis) {
  if (pos == n) {
    ans = min(ans, sum);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    dfs(pos + 1, sum + abs(a[i] - a[pos - 1]), vis);
    vis[i] = 0;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < k; i++) {
    vector<int> vis(n, 0);
    vis[i] = 1;
    dfs(1, 0, vis);
  }
  cout << ans << endl;
  return 0;
}