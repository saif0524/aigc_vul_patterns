#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;
int dist[MAXN];
bool in_queue[MAXN];
vector<pair<int, int>> adj[MAXN];
int parent[MAXN];
int n, m;

bool spfa(int start) {
    fill(dist, dist + n + 1, INF);
    fill(parent, parent + n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    in_queue[start] = true;
    int node, next_node, weight;
    int count;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        in_queue[node] = false;
        for (auto edge : adj[node]) {
            next_node = edge.first;
            weight = edge.second;
            if (dist[node] + weight < dist[next_node]) {
                dist[next_node] = dist[node] + weight;
                parent[next_node] = node;
                if (!in_queue[next_node]) {
                    q.push(next_node);
                    in_queue[next_node] = true;
                    count++;
                    if (count > n) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void find_cycle() {
    for (int i = 1; i <= n; ++i) {
        if (in_queue[i]) {
            int v = i;
            for (int j = 0; j < n; ++j) {
                v = parent[v];
            }
            int u = v;
            int cnt = 0;
            do {
                u = parent[u];
                cnt++;
            } while (u != v);
            cout << cnt;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int u, v, c, d;
    for(int i=0;i<m;i++){
        cin >> u >> v >> c >> d;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, d);
    }
    bool has_neg_cycle = false;
    for(int i=1;i<=n && !has_neg_cycle;i++){
        has_neg_cycle = spfa(i);
    }
    if(has_neg_cycle){
        find_cycle();
    } else {
        cout << 0;
    }
    return 0;
}