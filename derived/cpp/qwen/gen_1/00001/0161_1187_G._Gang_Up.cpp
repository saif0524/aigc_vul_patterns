#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int n, m, k, c, d;
vector<pair<int, int>> adj[55];
vector<int> paths[55];
vector<int> dist(55);
vector<vector<int>> walks(55, vector<int>(505, 0));

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            int nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
                paths[v] = paths[u];
                paths[v].push_back(v);
            }
        }
    }
}

int calculateDiscontent() {
    int totalDiscontent = 0;
    int arrivalTimes[505] = {0};
    for (int i = 1; i <= k; ++i) {
        int endDist = dist[paths[i].back()];
        totalDiscontent += c * endDist;
        for (int j = 0; j < (int)paths[i].size() - 1; ++j) {
            int u = paths[i][j], v = paths[i][j + 1];
            int t = j;
            if (u < v) swap(u, v);
            walks[u][t]++;
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v) {
            if (u == v) continue;
            for (int t = 0; t < 505; ++t) {
                int x = walks[u][t] + walks[v][t];
                if (u < v) swap(u, v);
                totalDiscontent += d * x * x;
            }
        }
    }
    return totalDiscontent;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> c >> d;
    vector<int> sources(k);
    for(auto &x: sources) cin >> x;
    for(int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }
    for(int i=1;i<=k;i++){
        fill(dist.begin(), dist.end(), INF);
        dijkstra(sources[i-1]);
        paths[i] = {1};
    }
    int ans = INF;
    do {
        int currentDiscontent = calculateDiscontent();
        ans = min(ans, currentDiscontent);
    } while (next_permutation(sources.begin(), sources.end()));
    cout << ans;
    return 0;
}