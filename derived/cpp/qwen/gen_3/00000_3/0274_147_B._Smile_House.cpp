#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
vector<pair<int, int>> adj[MAXN];
bool in_queue[MAXN];
int dist[MAXN];
int from[MAXN];

bool bellman_ford(int start) {
    fill(dist, dist + n + 1, INF);
    fill(from, from + n + 1, -1);
    fill(in_queue, in_queue + n + 1, false);
    
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    in_queue[start] = true;
    int in_queue_count = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        
        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                from[v] = u;
                
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                    if (++in_queue_count > n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int find_cycle() {
    for (int start = 1; start <= n; ++start) {
        if (bellman_ford(start)) {
            vector<int> path;
            int u = -1;
            for (int v = 1; v <= n; ++v) {
                if (in_queue[v]) {
                    u = v;
                    break;
                }
            }
            if (u == -1) continue;
            
            for (int i = 0; i < n; ++i) {
                u = from[u];
            }
            for (int v = u; ; v = from[v]) {
                path.push_back(v);
                if (from[v] == u && path.size() > 1) break;
            }
            return path.size();
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        adj[u].push_back({v, c1});
        adj[v].push_back({u, c2});
    }
    cout << find_cycle();
}