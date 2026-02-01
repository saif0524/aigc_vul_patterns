#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 100010;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<pii>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        adj[i].push_back({0, c});
    }

    for (int i = 0; i < k; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, INT_MAX);
    vector<bool> inSet(n + 1, false);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (inSet[current]) continue;
        inSet[current] = true;

        for (auto Edge : adj[current]) {
            int neighbor = Edge.first;
            int weight = Edge.second;

            for (int i = 0; i < adj[neighbor].size(); ++i) {
                int cost = adj[neighbor][i].second;
                int newDist = d + weight + cost;

                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}