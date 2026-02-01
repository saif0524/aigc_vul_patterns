#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 200005;

struct Edge {
    int to, next, w;
};

Edge edge[N << 1];
int head[N], tot;
int n, w[N];
double f[N];

void addEdge(int u, int v, int w) {
    edge[++tot] = {v, head[u], w};
    head[u] = tot;
}

void dfs(int u, int fa) {
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        f[u] += f[v] + w[v] * edge[i].w;
    }
}

void dfs2(int u, int fa, double sum) {
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs2(v, u, sum + f[u] - f[v] - w[v] * edge[i].w + f[v] + w[v] * edge[i].w);
    }
}

double ans = 1e18;
int pos;

void solve(int u, int fa, double sum) {
    double res = sum;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        res += f[v] + w[v] * edge[i].w;
    }
    if (res < ans) {
        ans = res;
        pos = u;
    }
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        solve(v, u, sum + f[u] - f[v] - w[v] * edge[i].w + f[v] + w[v] * edge[i].w);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        f[i] = w[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dfs(1, 0);
    solve(1, 0, 0);
    cout << pos << " " << fixed << setprecision(10) << ans << endl;
    return 0;
}