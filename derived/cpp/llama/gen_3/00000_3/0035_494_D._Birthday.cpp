#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct Edge {
    int to, weight;
};

vector<vector<Edge>> adjList;
vector<int> depth;
vector<ll> subtreeSize;

ll powMod(ll base, ll exponent) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

ll inverseMod(ll x) {
    return powMod(x, mod - 2);
}

void dfs(int u, int p, int d) {
    depth[u] = d;
    subtreeSize[u] = 1;
    for (const auto& edge : adjList[u]) {
        int v = edge.to;
        if (v != p) {
            dfs(v, u, d + edge.weight);
            subtreeSize[u] = (subtreeSize[u] + subtreeSize[v]) % mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    adjList.resize(n + 1);
    depth.resize(n + 1);
    subtreeSize.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dfs(1, 1, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        ll result = ((subtreeSize[u] * subtreeSize[v]) % mod * (depth[u] + depth[v])) % mod;
        result = (result + mod - (depth[u] * subtreeSize[u] * subtreeSize[v]) % mod) % mod;
        result = (result + mod - (depth[v] * subtreeSize[u] * subtreeSize[v]) % mod) % mod;
        result = (result * inverseMod(subtreeSize[u] + subtreeSize[v])) % mod;
        cout << result << "\n";
    }

    return 0;
}