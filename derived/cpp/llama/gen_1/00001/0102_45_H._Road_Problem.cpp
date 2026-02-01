#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1005;

struct Edge {
    int to, next;
};

Edge edges[2 * maxn];
int head[maxn], cnt;

void addEdge(int u, int v) {
    edges[cnt].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}

vector<int> G[maxn];

int dfn[maxn], low[maxn], clk;
int stk[maxn], top;
int scc_cnt;
int belong[maxn];

void tarjan(int u, int from) {
    dfn[u] = low[u] = ++clk;
    stk[++top] = u;
    for (int i = head[u]; i != -1; i = edges[i].next) {
        int v = edges[i].to;
        if (dfn[v] == 0) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (belong[v] == 0) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        scc_cnt++;
        while (stk[top] != u) {
            belong[stk[top]] = scc_cnt;
            G[scc_cnt].push_back(stk[top]);
            top--;
        }
        belong[u] = scc_cnt;
        G[scc_cnt].push_back(u);
        top--;
    }
}

vector<pair<int, int>> ans;

int n, m;
bool g[maxn][maxn];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = true;
        addEdge(u, v);
        addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0)
            tarjan(i, 0);

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (g[i][j] && belong[i] == belong[j])
                return cout << -1, 0;

    for (int i = 1; i <= n; i++) {
        int ban = -1;
        for (int j = 1; j <= n; j++)
            if (g[i][j])
                ban = belong[j];
        for (int j = 1; j <= n; j++)
            if (belong[i] == belong[j] && (g[i][j] || i == j))
                continue;
            else if (ban != belong[j] && !g[i][j])
                ans.push_back(make_pair(i, j));
    }

    cout << ans.size() << endl;
    for (auto p : ans)
        cout << p.first << " " << p.second << endl;

    return 0;
}