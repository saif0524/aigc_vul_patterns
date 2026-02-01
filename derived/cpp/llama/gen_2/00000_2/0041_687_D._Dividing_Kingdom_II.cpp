#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

vector<pair<int, int>> roads[MAXN];
int maxRoads[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(w, u, v);
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            roads[j].clear();
        }
    }

    for (int i = 0; i < m; i++) {
        auto [w, u, v] = edges[i];
        roads[u].emplace_back(v, w);
        roads[v].emplace_back(u, w);
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            maxRoads[i][j] = -1;
        }
    }

    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            vector<tuple<int, int, int>> curEdges;
            for (int i = l - 1; i <= r - 1; i++) {
                auto [w, u, v] = edges[i];
                curEdges.emplace_back(w, u, v);
            }

            sort(curEdges.begin(), curEdges.end());

            vector<bool> vis(n + 1);
            int res = -1;
            for (auto [w, u, v] : curEdges) {
                bool canDivide = false;
                for (int i = 1; i <= n; i++) {
                    vis[i] = false;
                }
                for (int i = 1; i <= n; i++) {
                    if (!vis[i]) {
                        queue<int> q;
                        q.push(i);
                        vis[i] = true;
                        bool hasBigRoad = false;
                        while (!q.empty()) {
                            int x = q.front();
                            q.pop();
                            for (auto [y, wy] : roads[x]) {
                                if (wy > w && vis[y]) {
                                    hasBigRoad = true;
                                }
                                if (!vis[y] && wy <= w) {
                                    vis[y] = true;
                                    q.push(y);
                                }
                            }
                        }
                        if (!hasBigRoad) {
                            canDivide = true;
                        }
                    }
                }
                if (canDivide) {
                    res = w;
                    break;
                }
            }
            maxRoads[l][r] = res;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << maxRoads[l][r] << '\n';
    }

    return 0;
}