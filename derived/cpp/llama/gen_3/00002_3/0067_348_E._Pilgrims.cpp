#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 100005;

struct Edge {
    int to, w;
};

vector<Edge> G[N];
int dist[N][N];
bool vis[N];

void dfs(int u, int fa, int id) {
    vis[u] = true;
    for (const auto& e : G[u]) {
        if (!vis[e.to]) {
            dist[id][e.to] = dist[id][u] + e.w;
            dfs(e.to, u, id);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> mon;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mon.push_back(x);
    }

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[j] = false;
            dist[i][j] = 0x3f3f3f3f;
        }
        dist[i][i] = 0;
        dfs(i, 0, i);
    }

    vector<int> max_dist(n + 1);
    vector<vector<int>> farthest(n + 1);

    for (int i = 0; i < m; i++) {
        int ma = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[mon[i]][j] > ma) {
                ma = dist[mon[i]][j];
                farthest[mon[i]].clear();
                farthest[mon[i]].push_back(j);
            } else if (dist[mon[i]][j] == ma) {
                farthest[mon[i]].push_back(j);
            }
        }
        max_dist[mon[i]] = ma;
    }

    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        if (find(mon.begin(), mon.end(), i) == mon.end()) {
            set<int> s;
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < farthest[mon[j]].size(); k++) {
                    if (dist[mon[j]][i] + dist[i][farthest[mon[j]][k]] == max_dist[mon[j]]) {
                        s.insert(mon[j]);
                    }
                }
            }
            if (s.size() > ans1) {
                ans1 = s.size();
                ans2 = 1;
            } else if (s.size() == ans1) {
                ans2++;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';

    return 0;
}