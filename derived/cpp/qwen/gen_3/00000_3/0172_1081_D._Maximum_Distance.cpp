#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long INF = 1e18;

int n, m, k;
vector<pair<int, int>> adj[MAXN];
vector<int> specials;

void dijkstra(int start, vector<long long> &dist) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > max(d, (long long)w)) {
                dist[v] = max(d, (long long)w);
                pq.push({dist[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        specials.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> max_dist(n + 1, INF);
    for(auto &s : specials){
        vector<long long> dist(n + 1, INF);
        dijkstra(s, dist);
        for(auto &s2 : specials){
            max_dist[s] = min(max_dist[s], dist[s2]);
        }
    }
    for(int i = 0; i < k; i++){
        if(i > 0) cout << ' ';
        cout << max_dist[specials[i]];
    }
    cout << '\n';
    return 0;
}