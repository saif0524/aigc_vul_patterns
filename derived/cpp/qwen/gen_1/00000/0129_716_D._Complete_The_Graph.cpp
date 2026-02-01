#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAXN = 1010;

int n, m, L, s, t;
vector<pair<int, ll>> adj[MAXN];
vector<vector<int>> edges;
vector<int> erased_idx;

ll dijkstra() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n, INF);
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> L >> s >> t;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        if(w == 0){
            w = INF;
            erased_idx.push_back(i);
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ll shortest = dijkstra();
    if(shortest == L){
        cout << "YES\n";
        for(auto &e : edges){
            cout << e[0] << " " << e[1] << " " << (e[2] == INF ? 1 : e[2]) << "\n";
        }
        return 0;
    }
    if(shortest > L){
        cout << "NO\n";
        return 0;
    }
    vector<ll> d(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    d[t] = 0;
    pq.push({0, t});
    while (!pq.empty()) {
        ll dis = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (dis != d[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    vector<ll> assign;
    for(auto idx : erased_idx){
        int u = edges[idx][0], v = edges[idx][1];
        if(d[u] + d[v] + 1 == L){
            assign.push_back(1);
        }
        else if(d[u] + d[v] + 1 < L){
            assign.push_back(L - d[u] - d[v] - 1);
        }
        else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    int ptr = 0;
    for(auto &e : edges){
        if(e[2] == INF){
            e[2] = assign[ptr++];
        }
        cout << e[0] << " " << e[1] << " " << e[2] << "\n";
    }
}