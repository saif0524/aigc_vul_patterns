#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int to;
    int weight;
    int id;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        graph[l].push_back({r, d, i});
        graph[r].push_back({l, -d, i});
    }
    vector<long long> distances(n, numeric_limits<long long>::max());
    distances[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 0});
    vector<bool> visited(n, false);
    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto& edge : graph[node]) {
            if (!visited[edge.to] && distances[edge.to] > distances[node] + edge.weight) {
                distances[edge.to] = distances[node] + edge.weight;
                pq.push({distances[edge.to], edge.to});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto& edge : graph[i]) {
            if (distances[i] + edge.weight != distances[edge.to]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}