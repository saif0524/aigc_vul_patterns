#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <limits>
using namespace std;

const int MAXN = 100005;
const int MAXM = 100005;
const int INF = numeric_limits<int>::max();

struct Edge {
    int to, next, w;
};

Edge edges[MAXM * 2];
int head[MAXN], tot = 0;

void addEdge(int u, int v) {
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}

int dis[MAXN][MAXN];

void floyd(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= tot; i += 2) {
        int u = edges[i].to;
        int v = edges[i ^ 1].to;
        dis[u][v] = dis[v][u] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

struct Spaceship {
    int x, a, f, p;
};

struct Base {
    int x, d, g;
};

int n, m, s, b, k;
Spaceship ships[MAXN];
Base bases[MAXN];
int g[MAXN];
long long maxProfit[MAXN];

void dfs(int u, vector<int>& path, bitset<MAXN>& visited) {
    visited[u] = true;
    path.push_back(u);
    for (int v = g[u]; v; v = g[v]) {
        if (!visited[v]) {
            dfs(v, path, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    floyd(n);

    cin >> s >> b >> k;
    for (int i = 1; i <= s; i++) {
        cin >> ships[i].x >> ships[i].a >> ships[i].f >> ships[i].p;
    }
    for (int i = 1; i <= b; i++) {
        cin >> bases[i].x >> bases[i].d >> bases[i].g;
    }
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        g[u] = v;
    }

    for (int i = 1; i <= s; i++) {
        maxProfit[i] = -ships[i].p;
        for (int j = 1; j <= b; j++) {
            if (ships[i].a >= bases[j].d && dis[ships[i].x][bases[j].x] <= ships[i].f) {
                maxProfit[i] = max(maxProfit[i], (long long)bases[j].g - ships[i].p);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= s; i++) {
        if (maxProfit[i] > 0) {
            ans += maxProfit[i];
            bitset<MAXN> visited;
            vector<int> path;
            dfs(i, path, visited);
            for (int j = 1; j <= s; j++) {
                if (!visited[j]) {
                    ans += max(0LL, maxProfit[j]);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}