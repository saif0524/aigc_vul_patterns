#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 100005;
const int MOD = 1e9 + 7;

struct Edge {
    int to, next, dir;
};

Edge edge[N * 2];
int head[N], tot;
int deg[N];
int dis[N];
bool vis[N];
int cnt[N];
int ans;

void addEdge(int u, int v, int dir) {
    edge[++tot].to = v;
    edge[tot].next = head[u];
    edge[tot].dir = dir;
    head[u] = tot;
    if (dir == 0) {
        deg[v]++;
    }
}

void topsort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next) {
            int v = edge[i].to;
            if (edge[i].dir == 0) {
                deg[v]--;
                if (deg[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, dir;
        scanf("%d%d%d", &u, &v, &dir);
        addEdge(u, v, dir);
        if (dir == 0) {
            addEdge(v, u, dir);
        }
    }
    topsort(n);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    int k;
    scanf("%d", &k);
    int pre = 1;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        if (x!= pre) {
            for (int j = head[pre]; j; j = edge[j].next) {
                if (edge[j].to == x) {
                    if (edge[j].dir == 1) {
                        ans = (ans + (1 << cnt[pre]) % MOD) % MOD;
                        cnt[pre]++;
                    }
                    break;
                }
            }
        }
        pre = x;
    }
    printf("%d\n", ans);
    return 0;
}