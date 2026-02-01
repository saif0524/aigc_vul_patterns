#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;

struct Edge {
    int v, w;
};

int n, m;
vector<Edge> g[maxn];
vector<int> w;
vector<int> order;

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

void dfs(int u, int last_w) {
    for (auto& e : g[u]) {
        if (e.w > last_w) {
            w.push_back(e.w);
            dfs(e.v, e.w);
            w.pop_back();
        }
    }
}

int dp[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, wi;
        scanf("%d %d %d", &u, &v, &wi);
        g[u].push_back({v, wi});
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end(), cmp);
    }

    int ans = 0;
    for (int u = 1; u <= n; u++) {
        memset(dp, 0, sizeof dp);
        for (auto& e : g[u]) {
            int len = 1;
            w.clear();
            w.push_back(e.w);
            dfs(e.v, e.w);
            for (int j = w.size() - 1; j >= 0; j--) {
                for (int k = 1; k <= n; k++) {
                    if (g[k].size() == 0) continue;
                    if (g[k][0].w > w[j]) {
                        dp[k][j + 1] = max(dp[k][j + 1], dp[k][0] + len + 1);
                    }
                }
                len++;
            }
            for (int j = 1; j <= n; j++) {
                ans = max(ans, dp[j][0]);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}