#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
#define pr pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpr vector<pr>
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ull unsigned long long
#define ld long double
#define endl "\n"

const int N = 1e5 + 5;

vector<pr> g[N], tree[N];
int level[N], par[N];
bool vis[N];

void dfs(int src) {
    vis[src] = true;
    for (auto &e : g[src]) {
        int child = e.fi, rel = e.se;
        if (!vis[child]) {
            par[child] = src;
            level[child] = level[src] + 1;
            if (rel == 0) {
                tree[src].pb({child, 0});
                tree[child].pb({src, 1});
            } else {
                tree[child].pb({src, 0});
                tree[src].pb({child, 1});
            }
            dfs(child);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) {
        swap(u, v);
    }
    while (level[u] != level[v]) {
        u = par[u];
    }
    while (u != v) {
        u = par[u];
        v = par[v];
    }
    return u;
}

bool isSpecialCase(int u, int v) {
    return (level[u] > level[v] && lca(u, v) == v);
}

bool isPartOf(int u, int v) {
    return (level[u] < level[v] && lca(u, v) == u);
}

int main() {
    FAST_IO;

    int n;
    cin >> n;

    REP(i, n) {
        int p, rel;
        cin >> p >> rel;
        if (p != -1) {
            g[p - 1].pb({i, rel});
        } else {
            level[i] = 0;
            par[i] = -1;
        }
    }

    REP(i, n) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;

        if (t == 1) {
            if (isSpecialCase(v, u)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (isPartOf(u, v)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}