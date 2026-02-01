#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            dist[i][j] = 1;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = -1;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                for (int l = 0; l < n; l++) {
                    if (l == i || l == j || l == k) continue;
                    if (dist[i][j] + dist[j][k] + dist[k][l] > ans) {
                        ans = dist[i][j] + dist[j][k] + dist[k][l];
                        a = i; b = j; c = k; d = l;
                    }
                }
            }
        }
    }

    cout << (a+1) << " " << (b+1) << " " << (c+1) << " " << (d+1) << endl;

    return 0;
}