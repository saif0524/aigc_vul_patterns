#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Edge {
    int to;
    int from;
};

struct Tree {
    vector<vector<int>> edges;
    vector<string> hashes;
    vector<int> parents;
    vector<int> depths;
    int n;

    Tree(int n) : n(n), edges(n), hashes(n), parents(n, -1), depths(n) {}

    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    void dfs(int u, int p, int d) {
        parents[u] = p;
        depths[u] = d;
        for (int v : edges[u]) {
            if (v!= p) {
                dfs(v, u, d + 1);
            }
        }
    }

    string getHash(int u) {
        if (!hashes[u].empty()) {
            return hashes[u];
        }
        vector<string> childHashes;
        for (int v : edges[u]) {
            if (v!= parents[u]) {
                childHashes.push_back(getHash(v));
            }
        }
        sort(childHashes.begin(), childHashes.end());
        string hash = to_string(u) + "(";
        for (const auto& childHash : childHashes) {
            hash += childHash + ",";
        }
        hash += ")";
        hashes[u] = hash;
        return hash;
    }

    unordered_set<string> getSubtreeHashes(int u) {
        unordered_set<string> subtreeHashes;
        function<void(int)> dfs = [&](int u) {
            subtreeHashes.insert(getHash(u));
            for (int v : edges[u]) {
                if (v!= parents[u]) {
                    dfs(v);
                }
            }
        };
        dfs(u);
        return subtreeHashes;
    }
};

int main() {
    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree.addEdge(u, v);
    }
    tree.dfs(0, -1, 0);
    int maxUniqueSubtrees = 0;
    int bestRoot = 0;
    for (int u = 0; u < n; ++u) {
        tree.hashes.clear();
        tree.dfs(u, -1, 0);
        unordered_set<string> subtreeHashes = tree.getSubtreeHashes(u);
        if (subtreeHashes.size() > maxUniqueSubtrees) {
            maxUniqueSubtrees = subtreeHashes.size();
            bestRoot = u;
        }
    }
    cout << bestRoot + 1 << endl;
    return 0;
}