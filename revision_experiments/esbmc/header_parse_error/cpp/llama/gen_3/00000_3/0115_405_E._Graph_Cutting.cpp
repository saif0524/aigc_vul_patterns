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

const int N = 1e5 + 5;

int n, m;
vector<int> g[N];
bool used[N];

void dfs(int v, int p) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u]) {
            dfs(u, v);
        }
    }
}

vector<pair<int, int>> edges;
vector<tuple<int, int, int>> ans;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.emplace_back(u, v);
    }

    for (auto& [u, v] : edges) {
        if (!used[u] && !used[v]) {
            dfs(u, -1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (used[i] && g[i].size() % 2 != 0) {
            cout << "No solution\n";
            return;
        }
    }

    for (auto& [u, v] : edges) {
        if (g[u].size() > 1 && g[v].size() > 1) {
            ans.emplace_back(u + 1, v + 1, g[u][0] + 1);
            g[u].erase(find(g[u].begin(), g[u].end(), v));
            g[v].erase(find(g[v].begin(), g[v].end(), u));
            g[u].erase(find(g[u].begin(), g[u].end(), g[u][0]));
        }
    }

    for (auto& [u, v] : edges) {
        if (g[u].size() > 0 && g[v].size() > 0) {
            ans.emplace_back(u + 1, v + 1, g[v][0] + 1);
        }
    }

    for (auto& [u, v, w] : ans) {
        cout << u << ' ' << v << ' ' << w << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}