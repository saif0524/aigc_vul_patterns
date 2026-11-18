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

const int MAXN = 5e5 + 10;

int n;
vector<int> g[MAXN];

int sz[MAXN];

void dfs1(int v, int p) {
    sz[v] = 1;
    for (int u : g[v]) if (u != p) {
        dfs1(u, v);
        sz[v] += sz[u];
    }
}

bool can[MAXN];

vector<int> order;

void dfs2(int v, int p) {
    order.push_back(v);
    for (int u : g[v]) if (u != p) {
        dfs2(u, v);
    }
}

int root_custom(int v) {
    dfs1(v, 0);
    for (int u : g[v]) if (u != 0) {
        if (sz[u] * 2 >= n) {
            return root_custom(u);
        }
    }
    return v;
}

void solve(int v) {
    dfs1(v, 0);
    order.clear();
    dfs2(v, 0);
    for (int u : order) {
        bool f = true;
        for (int to : g[u]) if (to != v) {
            if (sz[to] * 2 > n) {
                f = false;
                break;
            }
        }
        if (f) can[u] = true;
        if ((n - sz[u]) * 2 > n) f = false;
        if (f) can[v] = true;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        --v, --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    for (int v = 0; v < n; v++) {
        solve(v);
    }

    for (int v = 0; v < n; v++) {
        printf("%d ", can[v]);
    }
    puts("");

    return 0;
}