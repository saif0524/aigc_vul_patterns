#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 103;
const int MAX_M = 3 * MAX_N;

struct Edge {
    int to, l, r;
};

vector<Edge> g[MAX_N];
int n, m;

int maxLoyalty = 0;

void dfs(int v, int p, int l, int r) {
    if (v == n - 1) {
        maxLoyalty = max(maxLoyalty, r - l + 1);
        return;
    }

    for (auto& edge : g[v]) {
        if (edge.to == p) continue;
        int newL = max(l, edge.l);
        int newR = min(r, edge.r);
        if (newL <= newR) {
            dfs(edge.to, v, newL, newR);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        --u, --v;
        g[u].push_back({v, l, r});
        g[v].push_back({u, l, r});
    }

    dfs(0, -1, 0, 1e6);
    if (maxLoyalty == 0) {
        cout << "Nice work, Dima!" << endl;
    } else {
        cout << maxLoyalty << endl;
    }

    return 0;
}