#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <queue>
#include <random>
#include <ctime>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 7;
const int MAXM = 2e5 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int DX[] = {-1, 0, 1, 0};
const int DY[] = {0, 1, 0, -1};

ll n, m;
ll a[MAXN];
vector<pair<ll, ll>> g[MAXN];
ll ans[MAXN];
char color[MAXN];

pair<ll, ll> get_min(ll v, vector<ll> &used) {
    used[v] = 1;
    pair<ll, ll> ans = {a[v], v};
    for (auto to : g[v]) {
        if (!used[to.fi]) {
            auto cand = get_min(to.fi, used);
            cand.fi += to.se;
            if (cand.fi < ans.fi) ans = cand;
        }
    }
    return ans;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        color[i] = 'W';
    }
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == *min_element(a, a + n)) {
            color[i] = 'B';
            break;
        }
    }
    vector<ll> used(n, 0);
    for (int i = 0; i < n; ++i) {
        if (color[i] == 'W') continue;
        used[i] = 1;
        for (auto to : g[i]) {
            if (color[to.fi] == 'W') ans[to.se] = a[i];
        }
    }
    vector<ll> used2(n, 0);
    for (int i = 0; i < n; ++i) {
        if (color[i] == 'B') continue;
        used2[i] = 1;
        auto p = get_min(i, used2);
        vector<ll> path;
        ll v = p.se;
        while (v != i) {
            for (auto to : g[v]) {
                if (!used2[to.fi]) {
                    path.pb(to.se);
                    v = to.fi;
                    break;
                }
            }
        }
        path.pb(i);
        reverse(all(path));
        for (int i = 0; i < path.size() - 1; ++i) {
            ll diff = a[path[i]] - ans[path[i]];
            ans[path[i + 1]] = min(1LL, diff);
            a[path[i]] -= ans[path[i + 1]];
        }
    }
    for (int i = 0; i < m; ++i) {
        if (ans[i] == 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) cout << color[i];
    cout << '\n';
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
    return 0;
}