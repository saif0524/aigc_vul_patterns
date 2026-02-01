#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150005;
const int MAXM = 20;

struct Edge {
    int to, next;
} edge[MAXN * 2];
int head[MAXN], cnt;
void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
    edge[cnt].to = u;
    edge[cnt].next = head[v];
    head[v] = cnt++;
}

int n, m, k;
int fa[MAXM][MAXN];
int dep[MAXN];
void dfs(int x, int p) {
    for (int i = 1; i < MAXM; i++) {
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
    }
    for (int i = head[x]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v == p) continue;
        dep[v] = dep[x] + 1;
        fa[0][v] = x;
        dfs(v, x);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = MAXM - 1; i >= 0; i--) {
        if (dep[fa[i][u]] >= dep[v]) u = fa[i][u];
    }
    if (u == v) return u;
    for (int i = MAXM - 1; i >= 0; i--) {
        if (fa[i][u] != fa[i][v]) {
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
}

int path[MAXN][MAXN];
int s[MAXN], t[MAXN];
void getpath(int u, int v) {
    int l = lca(u, v);
    for (int i = 1; i <= n; i++) {
        path[u][i] = 0;
    }
    path[u][u] = 1;
    while (u != l) {
        path[u][fa[0][u]] = 1;
        u = fa[0][u];
    }
    while (v != l) {
        path[v][v] = 1;
        v = fa[0][v];
    }
    path[l][l] = 1;
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    dep[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &s[i], &t[i]);
        getpath(s[i], t[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            int cnt = 0;
            for (int k = 1; k <= n; k++) {
                if (path[s[i]][k] && path[s[j]][k]) cnt++;
            }
            if (cnt >= k) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}