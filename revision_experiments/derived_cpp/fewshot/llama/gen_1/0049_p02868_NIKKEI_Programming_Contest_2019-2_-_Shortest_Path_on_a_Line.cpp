#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAXN = 1e5 + 5;
ll dist[MAXN];
vector<pair<int, ll>> adj[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    l--, r--;
    for (int j = l; j < r; j++) {
      adj[j].push_back({j + 1, c});
    }
  }
  for (int i = 0; i < n; i++) {
    dist[i] = INF;
  }
  dist[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u]) continue;
    for (auto [v, w] : adj[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  if (dist[n - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << dist[n - 1] << endl;
  }
  return 0;
}