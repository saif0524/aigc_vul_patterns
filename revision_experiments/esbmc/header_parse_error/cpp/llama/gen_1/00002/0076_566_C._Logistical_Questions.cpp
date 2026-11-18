// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAX_N = 200005;
const ll INF = 1e18;

int n;
ll w[MAX_N];
vector<pii> adj[MAX_N];

ll dist[MAX_N];
ll res[MAX_N];

void dfs(int u, int p) {
    for (auto& e : adj[u]) {
        int v = e.first;
        ll len = e.second;
        if (v == p) continue;
        dist[v] = dist[u] + len;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].emplace_back(b, l);
        adj[b].emplace_back(a, l);
    }

    ll ans = INF;
    int opt = -1;

    for (int i = 1; i <= n; i++) {
        memset(dist, 0, sizeof(dist));
        dist[i] = 0;
        dfs(i, 0);
        ll tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp += w[j] * sqrt(dist[j]);
        }
        if (tmp < ans) {
            ans = tmp;
            opt = i;
        }
    }

    cout << fixed << setprecision(10) << opt << " " << ans << endl;

    return 0;
}