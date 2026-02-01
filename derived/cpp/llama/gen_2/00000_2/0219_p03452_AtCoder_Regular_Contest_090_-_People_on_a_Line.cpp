#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 100005;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAX_N];
vector<Edge> revGraph[MAX_N];

bool dfs(int u, vector<long long>& dist, vector<bool>& vis) {
    vis[u] = true;
    for (const Edge& e : graph[u]) {
        if (!vis[e.to]) {
            dist[e.to] = dist[u] + e.weight;
            if (!dfs(e.to, dist, vis)) return false;
        } else if (dist[e.to] != dist[u] + e.weight) {
            return false;
        }
    }
    return true;
}

bool check(long long n, long long m) {
    vector<long long> dist(n + 1, 0);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (!dfs(i, dist, vis)) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        graph[l].push_back({r, d});
        revGraph[r].push_back({l, -d});
    }

    if (check(n, m)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}