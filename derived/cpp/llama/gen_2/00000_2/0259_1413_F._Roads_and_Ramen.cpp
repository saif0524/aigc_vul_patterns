#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#define pii pair<int, int>

using namespace std;

const int MAX_N = 500005;

vector<pii> adj[MAX_N];
int dis[MAX_N], cnt[MAX_N];
bool flip[MAX_N];

void dijkstra(int src, vector<pii>& dis, vector<int>& cnt, bool par) {
    for (int i = 1; i <= n; i++) {
        dis[i] = -1e9;
        cnt[i] = -1e9;
    }

    dis[src] = 0;
    cnt[src] = par;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto [v, w] : adj[u]) {
            int nd = d + 1;
            int nc = cnt[u] + (w ? 1 : -1);

            if (dis[v] < nd || (dis[v] == nd && cnt[v] < nc)) {
                dis[v] = nd;
                cnt[v] = nc;
                pq.push({-dis[v], v});
            }
        }
    }
}

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> m;

    vector<pii> d0(n + 1), d1(n + 1);

    dijkstra(1, d0, cnt, 1);
    dijkstra(1, d1, cnt, 0);

    while (m--) {
        int idx;
        cin >> idx;

        flip[idx] ^= 1;

        for (int i = 1; i <= n; i++) {
            for (auto& [v, w] : adj[i]) {
                w = flip[idx] ? !w : w;
            }
        }

        int ans = 0;

        dijkstra(1, d0, cnt, 1);
        dijkstra(1, d1, cnt, 0);

        for (int i = 1; i <= n; i++) {
            if (d0[i].first > ans && !(d0[i].second & 1)) ans = d0[i].first;
            if (d1[i].first > ans && !(d1[i].second & 1)) ans = d1[i].first;
        }

        cout << ans << '\n';
    }

    return 0;
}