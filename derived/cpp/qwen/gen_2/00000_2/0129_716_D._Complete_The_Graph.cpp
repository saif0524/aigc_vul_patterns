#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1005;

int n, m, L, s, t;
vector<pair<int, ll>> adj[MAXN];
vector<tuple<int, int, ll>> edges;
bool assigned[10005];

ll dijkstra(int start, int end) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (w == 0) continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

void reassign_weights() {
    for (auto &[u, v, w] : edges) {
        if (w == 0) {
            w = 1;
        }
    }
    vector<ll> dist(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    if (dist[t] > L) {
        cout << "NO\n";
        return;
    }
    ll extra = L - dist[t];
    for (auto &[u, v, w] : edges) {
        if (w == 1) {
            if (extra >= 1) {
                w += extra;
                extra = 0;
            } else {
                w += 1;
                extra -= 1;
            }
        }
    }
    cout << "YES\n";
    for (auto &[u, v, w] : edges) {
        cout << u << " " << v << " " << w << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    for(int i=0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        edges.emplace_back(v, u, w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    ll shortest_path = dijkstra(s, t);
    if (shortest_path == L) {
        cout << "YES\n";
        for (auto &[u, v, w] : edges) {
            if (w == 0) w = 1;
        }
        for (int i = 0; i < m; i++) {
            cout << get<0>(edges[2*i]) << " " << get<1>(edges[2*i]) << " " << get<2>(edges[2*i]) << "\n";
        }
    } else if (shortest_path > L) {
        cout << "NO\n";
    } else {
        reassign_weights();
    }
}