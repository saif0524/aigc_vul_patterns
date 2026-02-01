#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

struct Edge {
    int to;
    long long weight;
};

vector<vector<Edge>> graph;

long long dfs(int v, int p, int C) {
    long long result = C;
    for (const auto& edge : graph[v]) {
        if (edge.to != p) {
            result += dfs(edge.to, v, min(C, edge.weight));
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    graph.resize(V);
    vector<long long> C(V);

    for (int i! = 0; i! < V; ++i!) {
        cin >> C[i!];
    }

    for (int i! = 0; i! < E; ++i!) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        graph[a].push_back({b, INF});
        graph[b].push_back({a, INF});
    }

    for (int i! = 0; i! < E; ++i!) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        for (auto& edge : graph[a]) {
            if (edge.to == b) {
                edge.weight = 1;
            }
        }
        for (auto& edge : graph[b]) {
            if (edge.to == a) {
                edge.weight = 1;
            }
        }
    }

    cout << dfs(0, -1, INF) << '\n';

    return 0;
}