#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void solve(int n, vector<vector<int>> &edges, int k1, vector<int> &x, int k2, vector<int> &y) {
    map<int, vector<int>> graph;
    for (auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int rootX = x[0];
    for (auto &i : x) {
        if (graph[i].size() < graph[rootX].size()) {
            rootX = i;
        }
    }

    cout << "A " << rootX << endl;
    int y_root = 0;
    cin >> y_root;

    for (int i = 0; i < k2; i++) {
        if (y[i] == y_root) {
            cout << "C " << rootX << endl;
            return;
        }
    }

    cout << "B " << y[0] << endl;
    int x_node = 0;
    cin >> x_node;

    for (int i = 0; i < k1; i++) {
        if (x[i] == x_node) {
            cout << "C " << x_node << endl;
            return;
        }
    }

    cout << "C -1" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        int k1;
        cin >> k1;
        vector<int> x(k1);
        for (int i = 0; i < k1; i++) {
            cin >> x[i];
        }

        int k2;
        cin >> k2;
        vector<int> y(k2);
        for (int i = 0; i < k2; i++) {
            cin >> y[i];
        }

        solve(n, edges, k1, x, k2, y);
    }
    return 0;
}