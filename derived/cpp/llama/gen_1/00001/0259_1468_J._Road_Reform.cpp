#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<int>> edges(m, vector<int>(3));

        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
            edges[i][0]--;
            edges[i][1]--;
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        long long res = numeric_limits<long long>::max();
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) != n - 1) {
                continue;
            }

            vector<pair<int, int>> curEdges;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    curEdges.emplace_back(edges[i][0], edges[i][1]);
                }
            }

            DisjointSet dsu(n);
            bool ok = true;
            for (auto& edge : curEdges) {
                if (dsu.find(edge.first) == dsu.find(edge.second)) {
                    ok = false;
                    break;
                }
                dsu.unionSet(edge.first, edge.second);
            }

            if (!ok) {
                continue;
            }

            long long curRes = 0;
            for (int i = 0; i < m; i++) {
                if ((mask >> i) & 1) {
                    if (edges[i][2] > k) {
                        curRes += edges[i][2] - k;
                    }
                } else {
                    if (edges[i][2] < k) {
                        curRes += k - edges[i][2];
                    }
                }
            }

            res = min(res, curRes);
        }

        cout << res << '\n';
    }

    return 0;
}