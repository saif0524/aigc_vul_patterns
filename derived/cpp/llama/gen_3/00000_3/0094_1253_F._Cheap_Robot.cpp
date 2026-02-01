#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXM = 3e5 + 10;
const int MAXQ = 3e5 + 10;
const long long INF = 1e18;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAXN];

bool dijkstra(int source, int target, long long capacity, int n, int k) {
    vector<long long> distance(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;
    while (!pq.empty()) {
        long long currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        if (currentDistance > distance[currentNode]) continue;
        for (const Edge& edge : graph[currentNode]) {
            long long nextDistance = currentDistance + edge.weight;
            int nextNode = edge.to;
            if (nextDistance <= capacity) {
                if (nextDistance < distance[nextNode]) {
                    distance[nextNode] = nextDistance;
                    pq.push({nextDistance, nextNode});
                }
            }
        }
        if (currentNode <= k) {
            for (const Edge& edge : graph[currentNode]) {
                long long nextDistance = edge.weight;
                int nextNode = edge.to;
                if (nextDistance < distance[nextNode]) {
                    distance[nextNode] = nextDistance;
                    pq.push({nextDistance, nextNode});
                }
            }
        }
    }
    return distance[target] != INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        long long low = 0, high = 1e9, res = -1;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (dijkstra(a, b, mid, n, k)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}