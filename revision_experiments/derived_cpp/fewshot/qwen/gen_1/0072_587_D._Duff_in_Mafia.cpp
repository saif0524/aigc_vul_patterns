#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 10;
const int MAXM = 5e4 + 10;

struct Edge {
    int u, v, c, t, idx;
};

vector<Edge> edges;
vector<pair<int, int>> adj[MAXN];
int color_last[MAXN];
int match[MAXN];
int vis[MAXN];
int n, m;

bool dfs(int u, int t) {
    vis[u] = t;
    for (auto& p : adj[u]) {
        int v = p.first;
        int c = p.second;
        if (vis[v] == t) continue;
        if (color_last[c] == t && match[v] == -1) {
            match[v] = u;
            return true;
        }
    }
    for (auto& p : adj[u]) {
        int v = p.first;
        int c = p.second;
        if (vis[v] == t) continue;
        if (dfs(match[v], t)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;
        edges.push_back({u, v, c, t, i});
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.t < b.t;
    });

    int ans_time = -1;
    int ans_cnt = 0;
    vector<int> ans_edges;

    memset(color_last, -1, sizeof(color_last));
    memset(match, -1, sizeof(match));

    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int c = edges[i].c;
        int t = edges[i].t;
        int idx = edges[i].idx;

        if (match[u] == -1 && match[v] == -1) {
            match[u] = v;
            match[v] = u;
            color_last[c] = t;
            ans_time = t;
            ans_cnt++;
            ans_edges.push_back(idx +1);
        } else {
            int old_t = color_last[c];
            if (old_t < t) {
                memset(vis, 0, sizeof(vis));
                if (dfs(u, t)) {
                    color_last[c] = t;
                    ans_time = t;
                    ans_cnt++;
                    ans_edges.push_back(idx + 1);
                }
            }
        }
    }

    memset(color_last, -1, sizeof(color_last));
    memset(match, -1, sizeof(match));

    for (int i = 0; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int c = edges[i].c;
        int t = edges[i].t;
        int idx = edges[i].idx;

        if (match[u] == -1 && match[v] == -1) {
            match[u] = v;
            match[v] = u;
            color_last[c] = t;
        } else {
            int old_t = color_last[c];
            if (old_t < t) {
                memset(vis, 0, sizeof(vis));
                if (dfs(u, t)) {
                    color_last[c] = t;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (match[i] != -1) {
            for (auto& p : adj[i]) {
                int v = p.first;
                int c = p.second;
                if (match[v] == i && color_last[c] != -1) {
                    continue;
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;
    cout << ans_time << " " << ans_cnt << endl;
    for (int i = 0; i < ans_cnt; ++i) {
        if (i > 0) cout << " ";
        cout << ans_edges[i];
    }
    cout << endl;

    return 0;
}