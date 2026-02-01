#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXLOG = 20;
const double EPS = 1e-9;

vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], childCnt[MAXN];
double prob[MAXN];
int up[MAXN][MAXLOG];

void preprocess(int u, int p) {
    parent[u] = p;
    depth[u] = depth[p] + 1;
    up[u][0] = p;
    for (int i = 1; i < MAXLOG; ++i) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        } else {
            up[u][i] = -1;
        }
    }
    childCnt[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        preprocess(v, u);
        childCnt[u] += childCnt[v];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = MAXLOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = MAXLOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return parent[u];
}

double expectedComponents() {
    double ans = 0.0;
    for (int u = 0; u < n; ++u) {
        if (parent[u] == -1) continue;
        double p_u = prob[u];
        double p_p = prob[parent[u]];
        double q_u = 1.0 - p_u;
        double q_p = 1.0 - p_p;
        ans += (p_u * q_p * childCnt[u] + p_p * q_u + p_u * p_p) / (q_p + q_u * childCnt[u]);
    }
    ans += prob[0];
    return ans;
}

int n, q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> prob[i];
    for(int i=1;i<n;i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(up, -1, sizeof(up));
    preprocess(0, -1);
    cin >> q;
    while(q--){
        int u;
        double p;
        cin >> u >> p;
        prob[u] = p;
        cout << fixed << setprecision(5) << expectedComponents() << '\n';
    }
}