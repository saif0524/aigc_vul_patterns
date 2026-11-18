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

const int MAXN = 310005;

vector<int> adj[MAXN];
int d[MAXN], deg[MAXN], vis[MAXN];
vector<pair<int, int>> edges;
int n, m;

bool dfs(int u, int p) {
    vis[u] = 1;
    bool valid = true;
    for (int v : adj[u]) {
        if (v != p) {
            valid &= dfs(v, u);
        }
    }
    if (d[u] == -1) {
        if (deg[u] % 2) {
            valid = false;
        }
    } else {
        if (deg[u] % 2 != d[u]) {
            valid = false;
        }
    }
    return valid;
}

void mark_even(int u, int p) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            if (!vis[v]) {
                mark_even(v, u);
            } else {
                if ((deg[u] + deg[v]) % 2 == 1) {
                    deg[u]--;
                    deg[v]--;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    bool possible = dfs(1, -1);
    if (!possible) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    mark_even(1, -1);
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].first, v = edges[i].second;
        if (deg[u] > 0 && deg[v] > 0) {
            deg[u]--;
            deg[v]--;
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
}