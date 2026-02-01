#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> hasBlack;

void dfs(int v, int p, bool& hasBlackEdge) {
    hasBlackEdge = false;
    for (auto& edge : graph[v]) {
        int to = edge.first;
        if (to == p) continue;
        bool childHasBlack = false;
        dfs(to, v, childHasBlack);
        hasBlackEdge = hasBlackEdge || childHasBlack || edge.second;
    }
}

long long powmod(long long a, int n) {
    long long res = 1;
    while (n) {
        if (n % 2) res = res * a % MOD;
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    graph.resize(n);
    hasBlack.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        graph[u].emplace_back(v, x);
        graph[v].emplace_back(u, x);
    }

    long long total = powmod(n, k);
    long long bad = 0;

    for (int i = 0; i < n; ++i) {
        bool hasBlackEdge = false;
        dfs(i, -1, hasBlackEdge);
        if (!hasBlackEdge) {
            bad = (bad + powmod(1, k - 1)) % MOD;
        }
    }

    cout << (total - bad + MOD) % MOD << '\n';

    return 0;
}