#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define MOD 1000000007
#define ll long long
#define pll pair<ll, ll>

const ll N = 100005;

vector<pll> adj[N];
ll dist[N];
bool vis[N];
ll cost[N][N];

void bfs(ll s) {
    memset(dist, INF, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &i : adj[u]) {
            ll v = i.first, c = i.second;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void floyd(ll n) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cost[i][j] = dist[j];
        }
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, 0});
        if (c == 0) adj[v].push_back({u, 0});
        else adj[v].push_back({u, 1});
    }
    bfs(1);
    floyd(n);
    ll k;
    cin >> k;
    ll lst = 1, ans = 0;
    for (ll i = 1; i <= k; i++) {
        ll x;
        cin >> x;
        if (cost[lst][x] == INF) {
            ans = (ans + (1LL << 20) - 1) % MOD;
        } else if (cost[lst][x] > 0) {
            ans = (ans + cost[lst][x]) % MOD;
        }
        lst = x;
    }
    cout << ans << '\n';
    return 0;
}