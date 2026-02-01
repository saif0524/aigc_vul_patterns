#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 105, maxm = 1005, inf = 1e9;

struct Edge {
    int to, w, nxt;
};

Edge e[maxm * 2];
int head[maxn], cnt;

void addEdge(int u, int v, int w) {
    e[++cnt] = {v, w, head[u]};
    head[u] = cnt;
}

int n, m, r;
int dis[maxn];
bool vis[maxn];

void dijkstra() {
    fill(dis, dis + n, inf);
    dis[r] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            for (int k = head[j]; k; k = e[k].nxt) {
                int to = e[k].to, w = e[k].w;
                if (dis[to] > dis[j] + w) {
                    dis[to] = dis[j] + w;
                }
            }
        }
    }
    fill(vis, vis + n, false);
    for (int i = 0; i < n; i++) vis[i] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> r;
    cnt = 0;
    fill(head, head + n, 0);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i != r) sum += dis[i];
    }
    cout << sum << endl;
    return 0;
}