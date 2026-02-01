#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 105;

int N, M;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN][MAXN];

void floydWarshall() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (auto &e : adj[i]) {
            int j = e.first, w = e.second;
            dist[i][j] = dist[j][i] = min(dist[i][j], w);
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    floydWarshall();
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (auto &e : adj[i]) {
            int j = e.first, w = e.second;
            if (dist[i][j] != w) {
                ans++;
            }
        }
    }
    ans /= 2;
    cout << ans << "\n";
    return 0;
}