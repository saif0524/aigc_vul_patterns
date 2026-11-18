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
#define MOD 1000000007
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> vis;
int n, k;

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int u, int p, bool& hasBlack) {
    vis[u] = 1;
    for (auto [v, c] : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            dfs(v, u, hasBlack);
            if (c) hasBlack = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    adj.resize(n + 1);
    vis.resize(n + 1);

    int hasBlackEdge = 0;
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
        if (c) hasBlackEdge = 1;
    }

    if (!hasBlackEdge) {
        cout << 0 << '\n';
        return 0;
    }

    long long total = powmod(n, k);
    long long bad = 0;

    for (int i = 1; i <= n; i++) {
        bool hasBlack = false;
        vis.assign(n + 1, 0);
        dfs(i, i, hasBlack);
        if (!hasBlack) {
            bad = (bad + powmod(1, k)) % MOD;
        }
    }

    long long good = (total - bad + MOD) % MOD;

    cout << good << '\n';

    return 0;
}