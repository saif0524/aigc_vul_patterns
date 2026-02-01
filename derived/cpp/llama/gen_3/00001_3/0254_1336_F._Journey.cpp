#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int N = 1e5 + 5;

struct Edge {
    int to, next;
};

Edge edge[N << 1];
int head[N], cnt;
int n, m, k;
int s[N], t[N];
int fa[N][20];
int dep[N];
int num[N];
int ans;

void addEdge(int u, int v) {
    edge[++cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == f) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i]!= fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> t[i];
        num[s[i]]++;
        num[t[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        num[i] /= 2;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if (dis(s[i], s[j]) + dis(t[i], t[j]) - dis(s[i], t[j]) * 2 >= k * 2) ans++;
            if (dis(s[i], t[j]) + dis(t[i], s[j]) - dis(s[i], t[j]) * 2 >= k * 2) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}