#include <bits/stdc++.h>

using namespace std;

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);

        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }
};

void run() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    vector<vector<int>> queries;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int v;
            cin >> v;
            queries.push_back({v});
        } else {
            int e;
            cin >> e;
            queries.push_back({e});
        }
    }

    DisjointSet dsu(n);

    for (int i = 0; i < m; i++) {
        dsu.unionSet(edges[i][0], edges[i][1]);
    }

    vector<bool> del(m);
    for (int i = q - 1; i >= 0; i--) {
        if (queries[i].size() == 1 && queries[i][0] == 2) {
            del[queries[i][0] - 1] = true;
        } else if (queries[i].size() == 1) {
            int v = queries[i][0];
            int root = dsu.find(v);
            vector<int> sameComponent;
            for (int j = 1; j <= n; j++) {
                if (dsu.find(j) == root && !del[j - 1]) {
                    sameComponent.push_back(j);
                }
            }

            int mx = 0;
            int idx = -1;
            for (int j : sameComponent) {
                if (p[j] > mx) {
                    mx = p[j];
                    idx = j;
                }
            }

            cout << mx << endl;
            p[idx] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
}