#include <bits/stdc++.h>

using namespace std;

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.emplace_back(x, y);
        uf.unite(x, y);
    }

    unordered_set<int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(uf.find(i));
    }

    vector<int> sizes;
    for (auto root : roots) {
        sizes.push_back(uf.size[root]);
    }
    sort(sizes.begin(), sizes.end());

    cout << sizes.size() << "\n";
    for (auto size : sizes) {
        cout << size << " ";
    }
    cout << "\n";

    return 0;
}