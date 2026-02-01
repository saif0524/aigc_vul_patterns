#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int N = 105;
const int MOD = 1e9 + 7;

struct Edge {
    int to;
    int dir;
};

vector<vector<Edge>> adj;
unordered_map<pair<int, int>, vector<int>> costMap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    adj.assign(n, vector<Edge>());

    for (int i = 0; i < n - 1; i++) {
        int u, v, dir;
        cin >> u >> v >> dir;
        u--; v--; // 0-based indexing

        adj[u].push_back({v, dir});
        if (dir == 0) {
            adj[v].push_back({u, dir});
        }
    }

    int k;
    cin >> k;

    vector<int> stops(k);
    for (int i = 0; i < k; i++) {
        cin >> stops[i];
        stops[i]--;
    }

    vector<int> dist(n, -1);
    dist[0] = 0;

    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const Edge& e : adj[u]) {
            int v = e.to;
            if (dist[v] == -1 && e.dir == 0) {
                dist[v] = dist[u];
                q.push(v);
            }
        }
    }

    bool legality = true;
    for (int i = 0; i < n; i++) {
        if (dist[i] == -1) {
            legality = false;
            break;
        }
    }

    for (int i = 1; i < k; i++) {
        if (dist[stops[i - 1]] < dist[stops[i]]) {
            legality = false;
            break;
        }
    }

    if (legality) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        int u = stops[i];
        int v = stops[i + 1];

        auto iter = costMap.find({u, v});
        if (iter == costMap.end()) {
            costMap[{u, v}] = vector<int>(n, 0);
            costMap[{v, u}] = vector<int>(n, 0);

            for (int j = 0; j < n; j++) {
                costMap[{u, v}][j] = 1;
                costMap[{v, u}][j] = 1;
            }

            vector<int> dist(n, -1);
            dist[u] = 0;

            queue<int> q;
            q.push(u);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (const Edge& e : adj[node]) {
                    int nei = e.to;

                    if (dist[nei] == -1) {
                        costMap[{u, v}][nei] = max(costMap[{u, v}][node], 1);
                        costMap[{v, u}][nei] = max(costMap[{v, u}][node], e.dir);
                        dist[nei] = dist[node] + 1;
                        q.push(nei);
                    } else if (dist[node] + 1 == dist[nei]) {
                        costMap[{u, v}][nei] = max(costMap[{u, v}][nei], costMap[{u, v}][node]);
                        costMap[{v, u}][nei] = max(costMap[{v, u}][nei], e.dir);
                    }
                }
            }
        }

        ans = (ans + costMap[{u, v}][v]) % MOD;
    }

    cout << ans << endl;

    return 0;
}