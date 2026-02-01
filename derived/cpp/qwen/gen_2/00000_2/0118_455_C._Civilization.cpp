#include <bits/stdc++.h>
using namespace std;

const int MAXN = 310000;

int parent[MAXN], size[MAXN], maxLen[MAXN];
vector<int> adj[MAXN];

int findSet(int u) {
    return parent[u] == u ? u : parent[u] = findSet(parent[u]);
}

void mergeSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if (u == v) return;

    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
}

int dfs(int u, int p) {
    int best = 1;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        best = max(best, 1 + dfs(v, u));
    }
    return best;
}

void recalculate(int u) {
    u = findSet(u);
    size[u] = 1;
    queue<int> q;
    q.push(u);
    maxLen[u] = 0;
    vector<int> dist(MAXN, -1);
    dist[u] = 0;

    int furthest = u;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        size[u]++;
        for (auto& to : adj[v]) {
            if (dist[to] == -1 && findSet(to) == u) {
                dist[to] = dist[v] + 1;
                q.push(to);
                if (dist[to] > maxLen[u]) {
                    maxLen[u] = dist[to];
                    furthest = to;
                }
            }
        }
    }

    q.push(furthest);
    dist.assign(MAXN, -1);
    dist[furthest] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& to : adj[v]) {
            if (dist[to] == -1 && findSet(to) == u) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    maxLen[u] = *max_element(dist.begin(), dist.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    for(int i=1;i<=n;i++){
        parent[i] = i;
        size[i] = 1;
        maxLen[i] = 0;
    }

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mergeSets(a, b);
    }

    for(int i=1;i<=n;i++){
        if(parent[i] == i){
            recalculate(i);
        }
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            cout << maxLen[findSet(x)] << "\n";
        }
        else{
            int x, y;
            cin >> x >> y;
            mergeSets(x, y);
            recalculate(findSet(x));
        }
    }
}