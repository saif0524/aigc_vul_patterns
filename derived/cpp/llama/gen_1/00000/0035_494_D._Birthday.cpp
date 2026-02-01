#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX_N = 100005;
const ll MOD = 1e9 + 7;

ll pow_mod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll inv_mod(ll a, ll mod) {
    return pow_mod(a, mod - 2, mod);
}

ll fact[MAX_N], inv_fact[MAX_N];

void init() {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv_fact[i] = inv_mod(fact[i], MOD);
    }
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (fact[n] * inv_fact[k] % MOD) * inv_fact[n - k] % MOD;
}

struct Edge {
    int to, weight;
};

vector<Edge> edges[MAX_N];
ll depth[MAX_N];

void dfs(int curr, int parent, ll d) {
    depth[curr] = d;
    for (Edge& e : edges[curr]) {
        if (e.to == parent) continue;
        dfs(e.to, curr, d + e.weight);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    dfs(1, -1, 0);

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

        ll d_u = depth[u];
        ll d_v = depth[v];
        ll ans = 0;

        for (int x = 1; x <= n; x++) {
            ll d_x = depth[x];
            if (d_x == d_u + d_v - depth[1]) {
                ans = (ans + C(d_u + d_v, d_u)) % MOD;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}