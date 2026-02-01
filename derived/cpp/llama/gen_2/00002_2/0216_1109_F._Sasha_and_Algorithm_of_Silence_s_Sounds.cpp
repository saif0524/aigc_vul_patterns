#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9;
const ll MOD = 998244353;

bool checkTree(const vector<vi> &g, int root, int n) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(root);
    vis[root] = true;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return cnt == n;
}

bool checkCycle(const vector<vi> &g, int root, int n, int par) {
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(root);
    vis[root] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (v == par) continue;
            if (vis[v]) return true;
            vis[v] = true;
            q.push(v);
        }
    }
    return false;
}

ll solve(int n, int m, const vector<vi> &f) {
    int nm = n * m;
    vector<vi> g(nm);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) g[f[i][j] - 1].push_back(f[i - 1][j] - 1);
            if (i < n - 1) g[f[i][j] - 1].push_back(f[i + 1][j] - 1);
            if (j > 0) g[f[i][j] - 1].push_back(f[i][j - 1] - 1);
            if (j < m - 1) g[f[i][j] - 1].push_back(f[i][j + 1] - 1);
        }
    }
    ll ans = 0;
    for (int l = 1; l <= nm; l++) {
        for (int r = l; r <= nm; r++) {
            vector<vi> ng(nm);
            set<int> s;
            for (int i = 0; i < nm; i++) {
                if (l <= i + 1 && i + 1 <= r) s.insert(i);
            }
            for (int i : s) {
                for (int j : g[i]) {
                    if (s.count(j)) ng[i].push_back(j);
                }
            }
            int cnt = 0;
            for (int i : s) {
                if (ng[i].empty()) cnt++;
            }
            bool ok = true;
            vector<bool> vis(nm, false);
            for (int i : s) {
                if (vis[i]) continue;
                if (checkCycle/ng, i, s.size(), -1)) {
                    ok = false;
                    break;
                }
                vis[i] = true;
            }
            if (ok && cnt == 1) ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> f(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }
    cout << solve(n, m, f) << '\n';
    return 0;
}