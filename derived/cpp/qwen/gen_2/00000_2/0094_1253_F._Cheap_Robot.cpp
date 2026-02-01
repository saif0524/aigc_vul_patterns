#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXK = 100005;
const long long INF = 1e18;

vector<pair<int, long long>> adj[MAXN];

struct Edge {
    int from, to;
    long long weight;
};

int k, q;
vector<Edge> edges;
int central_id[MAXN];

struct Query {
    int from, to, index;
};

vector<Query> queries;

long long dist[MAXK][MAXK];

void dijkstra(int start, int k, long long dist[MAXK][MAXK]) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start][start] = 0;
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (central_id[u] != -1) {
            if (dist[start][central_id[u]] > d) {
                dist[start][central_id[u]] = d;
            }
        }
        for (auto &edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (central_id[v] != -1) {
                if (dist[start][central_id[v]] > d + w) {
                    dist[start][central_id[v]] = d + w;
                    pq.push({d + w, v});
                }
            } else {
                if (dist[start][central_id[u]] > d + w) {
                    dist[start][central_id[u]] = d + w;
                    pq.push({d + w, v});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    for(int i = 1; i <= k; i++){
        central_id[i] = i;
    }
    for(int i = k + 1; i <= n; i++){
        central_id[i] = -1;
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= k; i++){
        dijkstra(i, k, dist);
    }
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(dist[i][j] == INF){
                dist[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b, i});
    }
    sort(queries.begin(), queries.end(), [](const Query &q1, const Query &q2){
        return dist[q1.from][q2.from] > dist[q1.from][q2.from];
    });
    vector<long long> answer(q);
    for(int i = 0; i < q; i++){
        int a = queries[i].from;
        int b = queries[i].to;
        long long best = 0;
        for(auto &edge : edges){
            int u = edge.from;
            int v = edge.to;
            long long w = edge.weight;
            if((dist[a][central_id[u]] <= dist[a][central_id[v]] && dist[a][central_id[u]] + w >= dist[a][central_id[b]]) ||
               (dist[a][central_id[v]] <= dist[a][central_id[u]] && dist[a][central_id[v]] + w >= dist[a][central_id[b]])){
                best = max(best, w);
            }
        }
        answer[queries[i].index - 1] = best;
    }
    for(int i = 0; i < q; i++){
        cout << answer[i] << "\n";
    }
}