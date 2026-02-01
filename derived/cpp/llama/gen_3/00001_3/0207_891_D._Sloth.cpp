#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 500005;
const int mod = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> pii;

int n, id, dfn[N], dep[N], siz[N], son[N], top[N], fa[N];
vector<int> adj[N];

struct binary {
    int l, r;
    binary(int l = 0, int r = 0) : l(l), r(r) {}
};

binary operator+(binary a, binary b) {
    return binary(a.l + b.l, a.r + b.r);
}

binary operator-(binary a, binary b) {
    return binary(a.l - b.l, a.r - b.r);
}

binary operator*(binary a, binary b) {
    return binary(a.l * b.l + a.r * b.r, a.l * b.r + a.r * b.l);
}

binary e;
binary gg[N];

binary dfs1(int u) {
    int sum = 0;
    siz[u] = 1;
    binary ans(e);
    for (auto v : adj[u]) {
        if (v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        gg[v] = dfs1(v);
        ans = ans + gg[v];
        sum += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
    siz[u] = sum + 1;
    ans.l += (sum % 2 == 0);
    return ans;
}

void dfs2(int u, binary now) {
    if (son[u]) {
        top[son[u]] = top[u];
        dfs2(son[u], now + gg[son[u]] - e);
    }
    for (auto v : adj[u]) {
        if (v == fa[u] || v == son[u]) continue;
        top[v] = v;
        dfs2(v, now - gg[son[u]] + gg[v] - e);
    }
}

void dfs3(int u, int pa) {
    binary now(0, 0);
    for (auto v : adj[u]) {
        if (fa[v] != u) continue;
        if (son[u] == v) dfs3(v, u);
        now = now + gg[v];
    }
    for (auto v : adj[u]) {
        if (fa[v] != u) continue;
        if (son[u] != v) dfs3(v, u);
    }
    int sum = siz[u] - 1;
    now.l += (sum % 2 == 0);
    dfs3(u, u);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    top[1] = 1;
    gg[1] = dfs1(1);
    dfs2(1, gg[1] - e);
    dfs3(1, 0);
    for (int i = 1; i <= n; i++) {
        if (siz[i] % 2 != 0) {
            cout << 0;
            return 0;
        }
    }
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (u > v) continue;
            int x = 0, y = 0;
            for (auto w : adj[u]) {
                if (w == v) continue;
                if (top[w] == u) x += 1;
                else y += 1;
            }
            for (auto w : adj[v]) {
                if (w == u) continue;
                if (top[w] == v) x += 1;
                else y += 1;
            }
            if (x % 2 == 0 && y % 2 == 1) ans++;
            if (x % 2 == 1 && y % 2 == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}