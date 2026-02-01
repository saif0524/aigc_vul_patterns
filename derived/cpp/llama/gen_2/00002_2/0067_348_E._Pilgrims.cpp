#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;

struct Edge {
    int to, w, next;
};

Edge e[N << 1];
int head[N], cnt;
int n, m;
int dis[N][N];
bool vis[N];
int id[N];
int ans, num;

void add(int u, int v, int w) {
    e[++cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int fa, int d, int &mx, int &id) {
    if (d > mx) {
        mx = d;
        id = u;
    }
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs(v, u, d + e[i].w, mx, id);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        id[x] = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        int mx = 0, x = 0;
        dfs(i, 0, 0, mx, x);
        dis[i][x] = mx;
        mx = 0;
        dfs(i, 0, 0, mx, x);
        dis[i][x] = mx;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (id[i] && id[j] && dis[i][j] == dis[i][id[i]]) {
                vis[j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!id[i]) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (vis[j]) cnt++;
            }
            if (cnt > ans) {
                ans = cnt;
                num = 1;
            } else if (cnt == ans) {
                num++;
            }
        }
    }
    cout << ans << " " << num << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}