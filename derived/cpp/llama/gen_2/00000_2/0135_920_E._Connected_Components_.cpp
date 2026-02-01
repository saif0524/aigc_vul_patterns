#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    vector<int> parent, rank, size;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
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
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            if (rank[rootX] == rank[rootY]) {
                rank[rootX]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool found = false;
            for (const auto& edge : edges) {
                if ((edge.first == i && edge.second == j) ||
                    (edge.first == j && edge.second == i)) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                uf.unionSet(i, j);
            }
        }
    }

    map<int, int> componentSizes;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);
        componentSizes[root] = uf.size[root];
    }

    vector<int> sizes;
    for (const auto& pair : componentSizes) {
        sizes.push_back(pair.second);
    }
    sort(sizes.begin(), sizes.end());

    cout << sizes.size() << endl;
    for (int size : sizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}