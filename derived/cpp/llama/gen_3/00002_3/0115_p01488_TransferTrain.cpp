#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int weight;
    int index;
};

struct Graph {
    int n;
    vector<vector<Edge>> adj;

    Graph(int n) : n(n), adj(n) {}

    void addEdge(int u, int v, int w, int index) {
        adj[u].push_back({v, w, index});
    }
};

struct MinCostFlow {
    Graph g;
    vector<int> pot;
    vector<int> dist;
    vector<int> par;

    MinCostFlow(int n) : g(n), pot(n), dist(n), par(n) {}

    bool spfa(int s, int t) {
        dist.assign(g.n, numeric_limits<int>::max());
        dist[s] = 0;

        vector<bool> inQueue(g.n, false);
        queue<int> q;
        q.push(s);
        inQueue[s] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (const auto& e : g.adj[u]) {
                int v = e.to;
                int w = e.weight + pot[u] - pot[v];

                if (w < 0 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    par[v] = e.index;

                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        return dist[t]!= numeric_limits<int>::max();
    }

    void updatePot() {
        for (int i = 0; i < g.n; ++i) {
            pot[i] += dist[i];
        }
    }

    pair<int, long long> solve(int s, int t) {
        int flow = 0;
        long long cost = 0;

        while (spfa(s, t)) {
            updatePot();

            int minCap = numeric_limits<int>::max();
            for (int v = t; v!= s; v = g.adj[v][0].to) {
                for (const auto& e : g.adj[v]) {
                    if (e.index == par[v]) {
                        minCap = min(minCap, -e.weight);
                        break;
                    }
                }
            }

            flow += minCap;
            cost += minCap * pot[t];

            int v = t;
            while (v!= s) {
                int u = 0;
                for (const auto& e : g.adj[v]) {
                    if (e.index == par[v]) {
                        u = v;
                        break;
                    }
                }

                for (auto& e : g.adj[u]) {
                    if (e.to == v) {
                        e.weight += minCap;
                        break;
                    }
                }

                for (auto& e : g.adj[v]) {
                    if (e.to == u) {
                        e.weight -= minCap;
                        break;
                    }
                }

                v = u;
            }
        }

        return {flow, cost};
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> demands(n);
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        demands[i] = 1;
    }

    int s = n;
    int t = n + 1;
    MinCostFlow g(n + 2);

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        vector<int> cities(k);
        for (int j = 0; j < k; ++j) {
            string name;
            cin >> name;

            auto it = find(names.begin(), names.end(), name);
            cities[j] = it - names.begin();
        }

        int c1, c2;
        cin >> c1 >> c2;

        g.g.addEdge(s, cities[0], 0, -1);
        g.g.addEdge(cities[0], s, 0, -1);
        for (int j = 1; j < k; ++j) {
            g.g.addEdge(cities[j - 1], cities[j], c1, i);
            g.g.addEdge(cities[j], cities[j - 1], c2, i);
        }
        g.g.addEdge(cities[k - 1], t, 0, -1);
        g.g.addEdge(t, cities[k - 1], 0, -1);
    }

    auto result = g.solve(s, t);
    cout << result.second << " " << result.first << endl;

    return 0;
}