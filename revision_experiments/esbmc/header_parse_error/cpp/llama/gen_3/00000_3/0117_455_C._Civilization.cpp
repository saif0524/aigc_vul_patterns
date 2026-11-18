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

const int maxn = 3e5 + 10;

vector<int> g[maxn];
int n, m, q;
int sz[maxn], par[maxn], diam[maxn];

int get(int v) {
    if (v == par[v]) return v;
    return par[v] = get(par[v]);
}

void merge(int v, int u) {
    v = get(v), u = get(u);
    if (v == u) return;
    if (sz[v] < sz[u]) swap(v, u);
    sz[v] += sz[u];
    par[u] = v;
    diam[v] = max(diam[v], diam[u]);
    diam[v] = max(diam[v], (diam[v] + 1) / 2 + (diam[u] + 1) / 2 + 1);
}

int bfs(int v) {
    queue<int> q;
    q.push(v);
    vector<bool> used(n);
    used[v] = true;
    int ans = 0;
    while (!q.empty()) {
        int siz = q.size();
        for (int i = 0; i < siz; ++i) {
            int u = q.front();
            q.pop();
            for (int to : g[u]) {
                if (!used[to]) {
                    used[to] = true;
                    q.push(to);
                    ans = max(ans, (int)q.size());
                }
            }
        }
    }
    return ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        diam[i] = bfs(i);
        for (int to : g[i]) {
            merge(i, to);
        }
    }
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v;
            cin >> v;
            --v;
            v = get(v);
            cout << diam[v] << '\n';
        } else {
            int v, u;
            cin >> v >> u;
            --v, --u;
            merge(v, u);
        }
    }
    return 0;
}