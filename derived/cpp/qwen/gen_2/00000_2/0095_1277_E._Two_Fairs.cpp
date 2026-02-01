#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int p, vector<vector<int>>& adj, vector<int>& sz) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, adj, sz);
            sz[v] += sz[u];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        --a; --b;
        vector<vector<int>> adj(n);
        for(int i=0;i<m;i++){
            int u, v;
            cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> sz(n);
        dfs(0, -1, adj, sz);
        int pa = -1;
        int pb = -1;
        queue<int> q;
        q.push(0);
        vector<int> par(n, -1);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int u : adj[v]){
                if(par[v] == u) continue;
                par[u] = v;
                q.push(u);
            }
        }
        int cur = a;
        while(cur != -1){
            if(par[cur] == b){
                pa = cur;
                break;
            }
            cur = par[cur];
        }
        if(pa == -1){
            cur = b;
            while(cur != -1){
                if(par[cur] == a){
                    pb = cur;
                    break;
                }
                cur = par[cur];
            }
        }
        int n1 = sz[a];
        int n2 = sz[b];
        int n3 = sz[pa];
        int n4 = sz[pb];
        if(pa != -1){
            n1 -= n3;
            n2 -= n3;
        } else {
            n1 -= n4;
            n2 -= n4;
        }
        long long res = 1LL * n1 * n2 + 1LL * n1 * n4 + 1LL * n4 * n2;
        if(pa != -1) res += 1LL * n1 * n3 + 1LL * n2 * n3 + 1LL * n3 * n4;
        cout << res << "\n";
    }
}