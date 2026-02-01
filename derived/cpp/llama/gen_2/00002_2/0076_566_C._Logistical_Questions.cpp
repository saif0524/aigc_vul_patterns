#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

const int MAX_N = 200005;
const long double EPS = 1e-9;

struct Edge {
    int to, weight;
};

vector<Edge> graph[MAX_N];
long long weights[MAX_N];
long double minCost = numeric_limits<long double>::max();
int minCity;

void dfs(int u, int parent, long long sum, long double cost) {
    sum += weights[u];
    cost += weights[u] * sqrtl(weights[u]);

    if (cost < minCost) {
        minCost = cost;
        minCity = u;
    }

    for (const auto& edge : graph[u]) {
        if (edge.to!= parent) {
            dfs(edge.to, u, sum, cost);
        }
    }
}

void dfs2(int u, int parent, long long sum, long double cost) {
    sum += weights[u];
    cost += weights[u] * sqrtl(weights[u]);

    if (cost < minCost) {
        minCost = cost;
        minCity = u;
    }

    for (const auto& edge : graph[u]) {
        if (edge.to!= parent) {
            dfs2(edge.to, u, sum, cost + edge.weight * sqrtl(weights[u]));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    dfs(1, 0, 0, 0.0L);

    cout << minCity << " " << fixed;
    cout.precision(20);
    cout << minCost << endl;

    return 0;
}