#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> edges;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionSets(int x, int y) {
        intfx = find(x);
        intfy = find(y);
        if (fx != fy) {
            if (rank[fx] < rank[fy])
                parent[fx] = fy;
            else if (rank[fx] > rank[fy])
                parent[fy] = fx;
            else {
                parent[fy] = fx;
                rank[fx]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    edges.resize(m + 1);
    vector<vector<int>> input(n, vector<int>(2));
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            cin >> input[i][0];
            input[i][1] = 0;
        } else {
            cin >> input[i][0] >> input[i][1];
        }
    }

    DisjointSet dsu(m + 1);

    for (int i = 0; i < n; i++) {
        int a = input[i][0];
        int b = input[i][1];

        if (dsu.find(a) != dsu.find(b)) {
            dsu.unionSets(a, b);
            used[i] = true;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (used[i])
            ans = (ans * 2) % MOD;
    }

    cout << ans << " " << count(used.begin(), used.end(), true) << endl;

    for (int i = 0; i < n; i++) {
        if (used[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}