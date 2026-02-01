#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;

int n, k, cnt;
int l[N], r[N], h[N], fa[N], sz[N], mxsz[N], rt;
vector<int> e[N];

void dfs(int u, int f) {
    l[u] = ++cnt;
    fa[u] = f;
    sz[u] = 1;
    mxsz[u] = 0;
    for (auto v : e[u]) {
        if (v != f) {
            h[v] = h[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
            mxsz[u] = max(mxsz[u], sz[v]);
        }
    }
    r[u] = cnt;
    mxsz[u] = max(mxsz[u], cnt - r[u] + l[u] - 1 - sz[u] + 1);
    if (mxsz[u] < mxsz[rt] || (mxsz[u] == mxsz[rt] && u < rt)) {
        rt = u;
    }
}

void solve(int u, int f) {
    for (auto v : e[u]) {
        if (v != f) {
            solve(v, u);
        }
    }
    int num = n - k;
    if (h[u] + 1 > num) {
        cout << u << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    mxsz[0] = 1e9;
    dfs(n, 0);
    solve(rt, 0);

    return 0;
}