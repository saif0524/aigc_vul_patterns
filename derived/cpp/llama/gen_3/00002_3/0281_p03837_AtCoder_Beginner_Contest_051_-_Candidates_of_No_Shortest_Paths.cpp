#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int n, m;
Edge edges[MAXN];
int dis[MAXN][MAXN];

void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        dis[edges[i].u][edges[i].v] = edges[i].w;
        dis[edges[i].v][edges[i].u] = edges[i].w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

bool check(int id) {
    int u = edges[id].u, v = edges[id].v, w = edges[id].w;
    edges[id].w = INF;
    floyd();
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] > dis[i][u] + w + dis[v][j] || dis[i][j] > dis[i][v] + w + dis[u][j]) {
                flag = true;
            }
        }
    }
    edges[id].w = w;
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    floyd();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}