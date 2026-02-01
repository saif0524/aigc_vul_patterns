#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long INF = 1e18;

vector<pair<int, long long>> adj[MAXN];
vector<int> special;

long long dijkstra(int start, const vector<int>& targets) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(MAXN, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d != dist[u]) continue;
        for (auto& [v, w] : adj[u]) {
            if (dist[v] > max(d, w)) {
                dist[v] = max(d, w);
                pq.push({dist[v], v});
            }
        }
    }
    long long max_dist = 0;
    for (int t : targets) {
        max_dist = max(max_dist, dist[t]);
    }
    return max_dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    special.resize(k);
    for(int &x: special) cin >> x;
    for(int i=0;i<m;i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<long long> results;
    for(int s: special){
        results.push_back(dijkstra(s, special));
    }
    for(long long res: results){
        cout << res << ' ';
    }
    return 0;
}