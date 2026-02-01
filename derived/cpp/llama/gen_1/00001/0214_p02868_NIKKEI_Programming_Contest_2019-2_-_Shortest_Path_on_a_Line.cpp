#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = numeric_limits<ll>::max();
const ll MOD = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> g(n);
    for (ll i = 0; i < m; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        for (ll j = l; j < r; j++) {
            g[j].emplace_back(j + 1, c);
        }
    }
    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (dist[v] != d) continue;
        for (auto [u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.emplace(dist[u], u);
            }
        }
    }
    if (dist[n - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n - 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}