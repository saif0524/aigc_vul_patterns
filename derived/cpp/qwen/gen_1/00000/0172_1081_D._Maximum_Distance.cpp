#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
const ll INF = 1e18;

vector<pair<int, ll>> G[N];
bool is_special[N];
int special[N];

void dijkstra(int start, vector<ll>& dist, int n) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : G[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void floyd_warshall(vector<vector<ll>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<k; i++){
        cin >> special[i];
        special[i]--;
        is_special[special[i]] = true;
    }
    for(int i=0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<vector<ll>> dist(k, vector<ll>(k, INF));
    for(int s = 0; s<k; s++){
        vector<ll> d(n, INF);
        dijkstra(special[s], d, n);
        for(int i=0; i<k; i++){
            dist[s][i] = d[special[i]];
        }
    }
    floyd_warshall(dist, k);
    for(int i=0; i<k; i++){
        ll ans = 0;
        for(int j=0; j<k; j++){
            ans = max(ans, dist[i][j]);
        }
        if(i) cout << " ";
        cout << ans;
    }
    cout << "\n";
}