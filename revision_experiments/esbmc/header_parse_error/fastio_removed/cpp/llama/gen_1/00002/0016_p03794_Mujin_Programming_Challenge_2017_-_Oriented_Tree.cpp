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

const int MOD = 1e9 + 7;

int n;
vector<vector<int>> g;
vector<int> cnt;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int dfs2(int u, int p) {
    int res = 1;
    for (int v : g[u]) {
        if (v != p) {
            int cur = dfs2(v, u);
            if (2 * cnt[v] > n) {
                cur = (cur * 2) % MOD;
            }
            res = (res * cur) % MOD;
        }
    }
    return res;
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cnt.resize(n);
    dfs(0, -1);

    cout << dfs2(0, -1) << endl;

    return 0;
}