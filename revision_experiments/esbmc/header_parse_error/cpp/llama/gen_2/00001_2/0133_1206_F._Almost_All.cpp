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

const int MAXN = 1005;
int n, sz[MAXN], dep[MAXN], num[MAXN];
vector<int> G[MAXN];

void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int v : G[u]) {
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int fa, int cnt) {
    num[u] = cnt;
    for (int v : G[u]) {
        if (v == fa) continue;
        dfs2(v, u, cnt + (1 << dep[v]));
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dep[1] = 0;
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : G[u]) {
            if (v > u) {
                printf("%d %d %d\n", u, v, num[v] - num[u]);
            }
        }
    }
    return 0;
}