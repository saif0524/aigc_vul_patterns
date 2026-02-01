#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int n, m;
int monks[MAXN];
vector<pair<int, int>> adj[MAXN];
int dist[MAXN][MAXN];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    memset(dist[src], 63, sizeof(dist[src]));
    dist[src][src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &e : adj[u]) {
            int v = e.first;
            int w = e.second;

            if (dist[src][v] > dist[src][u] + w) {
                dist[src][v] = dist[src][u] + w;
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> monks[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i) {
        bfs(i);
    }

    vector<vector<int>> farthest_monks(n);

    for (int i = 0; i < n; ++i) {
        int max_dist = 0;
        for (int j = 0; j < n; ++j) {
            if (j != i && dist[i][monks[j]] > max_dist) {
                max_dist = dist[i][monks[j]];
                farthest_monks[i].clear();
            }
            if (j != i && dist[i][monks[j]] == max_dist) {
                farthest_monks[i].push_back(monks[j]);
            }
        }
    }

    int max_unhappy = 0;
    int num_ways = 0;

    for (int i = 0; i < n; ++i) {
        if (!binary_search(monks, monks + m, i + 1)) {
            int unhappy = 0;
            for (int j = 0; j < m; ++j) {
                bool can_reach = false;
                for (int k : farthest_monks[monks[j] - 1]) {
                    bool found = false;
                    for (auto &e : adj[k - 1]) {
                        if (e.first != i && dist[monks[j] - 1][e.first] + e.second == dist[monks[j] - 1][k]) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        can_reach = true;
                        break;
                    }
                }
                if (!can_reach) {
                    ++unhappy;
                }
            }
            if (unhappy > max_unhappy) {
                max_unhappy = unhappy;
                num_ways = 1;
            } else if (unhappy == max_unhappy) {
                ++num_ways;
            }
        }
    }

    cout << max_unhappy << " " << num_ways << endl;

    return 0;
}