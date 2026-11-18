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
typedef double db;
const int N = 1e5 + 10;
vector<int> adj[N];
db p[N];
int par[N], sz[N], components;
db dp[N], ans[N];

void dfs(int u, int fa) {
    par[u] = fa;
    sz[u] = 1;
    dp[u] = 1 - p[u];
    for (auto v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] * (1 - p[u]);
    }
}

void reroot(int u, int fa) {
    if (fa == -1) ans[u] = dp[u];
    else {
        db up = dp[fa], down = dp[u];
        up -= down * (1 - p[fa]);
        down += up * (1 - p[u]);
        ans[u] = down;
        dp[u] = down, dp[fa] = up;
    }
    for (auto v : adj[u]) {
        if (v == fa) continue;
        reroot(v, u);
    }
}

void move(int u, int to, int N) {
    if (to == -1) return;
    db up = dp[to], down = dp[u];
    up += (down - up) * p[u] / p[to];
    down -= (down - up) * p[to] / p[u];
    dp[u] = down, dp[to] = up;
}

int main(){
    ((void)0);
    ((void)0);
    int N, Q;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> p[i];
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    reroot(0, -1);
    cin >> Q;
    while (Q--) {
        int u;
        db np;
        cin >> u >> np;
        move(u, par[u], N);
        p[u] = np;
        move(par[u], u, N);
        cout << ans[0] << '\n';
    }
}