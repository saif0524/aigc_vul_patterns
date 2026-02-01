#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
vector<int> adj[MAXN];
int pos[MAXN], comp[MAXN], cyc[MAXN], len[MAXN], endc[MAXN];
int dp[MAXN][40];

void dfs(int u, int p, int& count, int root) {
    if (comp[u] != -1) {
        if (u == root) {
            cyc[u] = 1;
            len[u] = 0;
            pos[u] = count;
            comp[u] = root;
            return;
        } else {
            int cur = p, steps = 0;
            while (cur != u) {
                cyc[cur] = 2;
                steps++;
                cur = adj[cur][0];
            }
            cyc[u] = 2;
            len[u] = steps + 1;
            cur = u;
            steps = 0;
            while (pos[cur] == -1) {
                pos[cur] = count - steps;
                steps++;
                cur = adj[cur][0];
            }
            comp[u] = comp[cur];
            endc[root] = u;
        }
    } else {
        comp[u] = root;
        pos[u] = count++;
        dfs(adj[u][0], u, count, root);
        if (cyc[u] == 2 && u == root) {
            int cur = u;
            do {
                cyc[cur] = 1;
                cur = adj[cur][0];
            } while (cur != u);
        }
    }
}

void init_lca(int u, int p) {
    dp[u][0] = p;
    for (int i = 1; i < 40; ++i) {
        dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
    for (auto v : adj[u]) {
        init_lca(v, u);
    }
}

int lca(int u, int v) {
    if (pos[u] > pos[v]) swap(u, v);
    for (int i = 39; i >= 0; --i) {
        if (pos[dp[v][i]] >= pos[u]) {
            v = dp[v][i];
        }
    }
    if (u == v) return u;
    for (int i = 39; i >= 0; --i) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    fill(comp, comp + MAXN, -1);
    fill(pos, pos + MAXN, -1);
    for(int i=1; i<=n; ++i){
        if(comp[i] == -1){
            int count = 0;
            dfs(i, 0, count, i);
        }
    }
    init_lca(1, 0);
    int q;
    cin >> q;
    while(q--){
        long long m;
        int y;
        cin >> m >> y;
        int start = y;
        int u = y;
        if(cyc[u] == 2){
            long long steps = m;
            if(steps < len[u]){
                for(int i=39; i>=0; --i){
                    if((1LL << i) <= steps){
                        u = adj[u][i];
                        steps -= (1LL << i);
                    }
                }
            } else {
                steps -= len[u];
                u = endc[comp[u]];
                steps %= len[u];
                for(int i=39; i>=0; --i){
                    if((1LL << i) <= steps){
                        u = adj[u][i];
                        steps -= (1LL << i);
                    }
                }
            }
            cout << (u == start) << "\n";
        } else {
            long long steps = m;
            if(cyc[u]){
                steps -= pos[u];
                steps %= len[u];
                u = endc[comp[u]];
                steps += pos[u];
            }
            for(int i=39; i>=0; --i){
                if((1LL << i) <= steps){
                    u = adj[u][i];
                    steps -= (1LL << i);
                }
            }
            int res = 0;
            if(cyc[u]){
                if(cyc[start] && comp[start] == comp[u]){
                    int LCA = lca(u, start);
                    res = len[comp[u]] - abs(pos[u] - pos[start]);
                    res += abs(pos[LCA] - pos[start]);
                    res += abs(pos[LCA] - pos[u]);
                } else {
                    if(start == u) res++;
                }
            } else {
                if(start == u) res++;
            }
            cout << res << "\n";
        }
    }
}