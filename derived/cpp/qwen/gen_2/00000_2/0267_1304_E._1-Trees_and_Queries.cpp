#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOGN = 20;

vector<int> adj[MAXN];
int dep[MAXN], par[MAXN][LOGN + 1], sz[MAXN], tin[MAXN], tout[MAXN], timer = 0;

void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    tin[u] = ++timer;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    tout[u] = timer;
}

void buildLCA(int n) {
    for (int j = 1; j <= LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            if (par[i][j - 1] != -1) {
                par[i][j] = par[par[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int j = LOGN; j >= 0; j--) {
        if (dep[u] - (1 << j) >= dep[v]) {
            u = par[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LOGN; j >= 0; j--) {
        if (par[u][j] != -1 && par[u][j] != par[v][j]) {
            u = par[u][j];
            v = par[v][j];
        }
    }
    return par[u][0];
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int kth_ancestor(int u, int k) {
    for (int j = LOGN; j >= 0; j--) {
        if (k & (1 << j)) {
            u = par[u][j];
        }
    }
    return u;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par, -1, sizeof(par));
    dfs(1, -1);
    buildLCA(n);
    int q;
    cin >> q;
    while(q--){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int l = lca(a, b);
        int xa = lca(x, a);
        int xb = lca(x, b);
        int ya = lca(y, a);
        int yb = lca(y, b);
        int xx = lca(x, y);
        int la = (l == xa ? xa : (l == ya ? ya : xx));
        int lb = (l == xb ? xb : (l == yb ? yb : xx));
        int len1 = dep[a] + dep[b] - 2*dep[l];
        int len2 = dep[a] + dep[b] + dep[x] + dep[y] - 2*(dep[la] + dep[lb] + dep[xx]);
        if(k == len1 || (k >= len2 && (k - len2) % 2 == 0)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}