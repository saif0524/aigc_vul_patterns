#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;

void dijkstra(int n, int s, vector<vector<pair<int, int>>>& adj, vector<ll>& dist) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist.assign(n + 1, INF);
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, cost] : adj[u]) {
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    int U, V;
    cin >> U >> V;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector<vector<pair<int, int>>> adj_r(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].emplace_back(B, C);
        adj[B].emplace_back(A, C);
        adj_r[A].emplace_back(B, 0);
        adj_r[A].emplace_back(B, C);
        adj_r[B].emplace_back(A, 0);
        adj_r[B].emplace_back(A, C);
    }
    vector<ll> dist_S(N + 1);
    vector<ll> dist_T(N + 1);
    vector<ll> dist_U(N + 1);
    dijkstra(N, S, adj, dist_S);
    dijkstra(N, T, adj, dist_T);
    dijkstra(N, U, adj_r, dist_U);
    ll ans = INF;
    for (int i = 1; i <= N; ++i) {
        for (auto [j, cost] : adj[i]) {
            if (dist_U[j] == dist_U[i] + cost) {
                ans = min(ans, dist_S[i] + dist_T[j] + dist_U[j]);
                ans = min(ans, dist_S[j] + dist_T[i] + dist_U[i]);
            }
        }
    }
    ans = min(ans, dist_U[T]);
    ans = min(ans, dist_S[T] + dist_U[U]);
    ans = min(ans, dist_S[U] + dist_U[V]);
    cout << ans << "\n";
}