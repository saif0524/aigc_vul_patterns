#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int N_MAX = 1000;
const long long INF = 1000000000000000000;

long long G[N_MAX + 1][N_MAX + 1];

struct Pair {
    int u, v;
};

vector<Pair> graph[N_MAX + 1];

vector<long long> weights;

void init(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = INF;
        }
    }
}

long long max_weight[N_MAX + 1];

void mst(int l, int r, int &min_size) {
    fill(max_weight, max_weight + N_MAX + 1, -1);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        for (const auto& e : graph[i]) {
            max_weight[e.u] = max(max_weight[e.u], weights[i - 1]);
            max_weight[e.v] = max(max_weight[e.v], weights[i - 1]);
        }
    }
    for (int i = 1; i <= N_MAX; i++) {
        if (max_weight[i] != -1) {
            cnt++;
        }
    }
    if (cnt == 1) {
        min_size = -1;
    }
    else {
        min_size = 0;
        for (int i = 1; i <= N_MAX; i++) {
            if (max_weight[i] != -1) {
                min_size = max(min_size, max_weight[i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    init(n);

    weights.resize(m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        weights[i - 1] = w;
        G[u][v] = G[v][u] = w;
        graph[i].push_back({u, v});
    }

    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= n; k++) {
            for (int j = 1; j <= n; j++) {
                G[j][k] = min(G[j][k], G[j][k]);
                G[k][j] = min(G[k][j], G[k][j]);
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int res;
        mst(l, r, res);
        cout << res << '\n';
    }

    return 0;
}