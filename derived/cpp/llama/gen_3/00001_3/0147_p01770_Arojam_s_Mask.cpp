#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_N = 100;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;
const int MAX_E = 4;

struct Edge {
    int to, next;
};

int n, m, e, s, t, r;
Edge edge[MAX_M * 2];
int head[MAX_N], cnt;
int event[MAX_E][3];

void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

int dis[MAX_N][1 << MAX_E];
bool vis[MAX_N][1 << MAX_E];

void bfs(int S, int mask) {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[S][mask] = 0;
    vis[S][mask] = true;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i!= -1; i = edge[i].next) {
            int v = edge[i].to;
            if (!vis[v][mask]) {
                dis[v][mask] = dis[u][mask] + 1;
                vis[v][mask] = true;
                q.push(v);
            }
        }
        for (int i = 0; i < e; i++) {
            if ((mask >> i) & 1) continue;
            if (u == event[i][2]) {
                int newMask = mask | (1 << i);
                for (int j = head[u]; j!= -1; j = edge[j].next) {
                    int v = edge[j].to;
                    if (!vis[v][newMask]) {
                        dis[v][newMask] = dis[u][mask] + 1;
                        vis[v][newMask] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> e >> s >> t >> r;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 0; i < e; i++) {
        cin >> event[i][0] >> event[i][1] >> event[i][2];
    }
    int ans = INT_MAX;
    for (int mask = 0; mask < (1 << e); mask++) {
        bfs(s, mask);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << e); j++) {
                if (dis[i][j]!= INT_MAX) {
                    for (int k = 0; k < e; k++) {
                        if ((j >> k) & 1) {
                            addEdge(event[k][0], event[k][1]);
                            addEdge(event[k][1], event[k][0]);
                        }
                    }
                    int tmp = dis[i][j];
                    for (int k = 0; k < (1 << e); k++) {
                        if (dis[t][k]!= INT_MAX) {
                            ans = min(ans, tmp + dis[t][k] + __builtin_popcount(k));
                        }
                    }
                    for (int k = 0; k < e; k++) {
                        if ((j >> k) & 1) {
                            for (int l = head[event[k][0]]; l!= -1; l = edge[l].next) {
                                if (edge[l].to == event[k][1]) {
                                    edge[l].to = -1;
                                    edge[l ^ 1].to = -1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}