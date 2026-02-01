#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x]!= x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX!= rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--;
            edges[i].v--;
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w < b.w;
        });

        long long ans = numeric_limits<long long>::max();
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask)!= n - 1) {
                continue;
            }

            DisjointSet dsu(n);
            vector<Edge> usedEdges;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    dsu.unionSet(edges[i].u, edges[i].v);
                    usedEdges.push_back(edges[i]);
                }
            }

            bool connected = true;
            for (int i = 0; i < n; i++) {
                if (dsu.find(i)!= dsu.find(0)) {
                    connected = false;
                    break;
                }
            }

            if (!connected) {
                continue;
            }

            long long changes = 0;
            bool hasGreater = false;
            for (const auto& edge : usedEdges) {
                if (edge.w > k) {
                    changes += edge.w - k;
                } else if (edge.w < k) {
                    changes += k - edge.w;
                }
                if (edge.w > k) {
                    hasGreater = true;
                }
            }

            if (!hasGreater) {
                continue;
            }

            ans = min(ans, changes);
        }

        cout << ans << '\n';
    }

    return 0;
}