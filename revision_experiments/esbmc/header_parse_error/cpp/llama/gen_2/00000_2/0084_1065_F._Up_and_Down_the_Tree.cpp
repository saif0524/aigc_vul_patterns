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

const int N = 1e6 + 5;

vector<int> g[N];
int h[N], up[N], n, k, cnt;

void dfs(int v, int p = -1) {
    h[v] = (p == -1 ? 0 : h[p] + 1);
    up[v] = v;
    if (g[v].empty()) {
        cnt++;
        return;
    }
    for (int u : g[v]) {
        dfs(u, v);
        if (h[up[u]] > h[up[v]]) {
            up[v] = up[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        g[p - 1].push_back(i);
    }
    dfs(0);
    int ans = 0;
    for (int v = 0; v < n; v++) {
        if (g[v].empty()) {
            int u = v;
            int tmp = 1;
            for (int i = 0; i < k; i++) {
                u = (u ? (g[u][0] == v ? g[u][1] : g[u][0]) : -1);
                if (u == -1) break;
                if (g[u].empty()) tmp++;
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
    return 0;
}