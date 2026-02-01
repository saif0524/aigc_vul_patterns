#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
vector<int> adj[MAXN], dis[MAXN];
int n, k, m;

bool valid(int mask) {
    int cnt = __builtin_popcount(mask);
    if (cnt == 0) return true;
    int start = -1;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            start = i;
            break;
        }
    }
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(start);
    visited[start] = true;
    int invited = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (mask & (1 << v) && !visited[v]) {
                q.push(v);
                visited[v] = true;
                invited++;
            }
        }
    }
    if (invited != cnt) return false;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            for (int j : dis[i]) {
                if (mask & (1 << j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        dis[u].push_back(v);
        dis[v].push_back(u);
    }
    int ans=0;
    for(int mask=0;mask<(1<<n);mask++){
        if(valid(mask)){
            ans=max(ans,__builtin_popcount(mask));
        }
    }
    cout << ans;
    return 0;
}