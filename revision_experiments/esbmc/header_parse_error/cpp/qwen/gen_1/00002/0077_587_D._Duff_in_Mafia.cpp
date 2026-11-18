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

struct Edge {
    int u, v, c, t, idx;
};

int n, m;
vector<vector<Edge>> adj;
vector<bool> vis;
vector<int> color_match;
vector<int> mathcing;
vector<vector<int>> color_edges;
multiset<pair<int, int>> ms;
map<int, int> color_destroy;

bool dfs(int v, int col) {
    if (vis[v]) return false;
    vis[v] = true;
    for (auto &e : adj[v]) {
        if (e.c == col && color_match[e.v] != mathcing[e.u]) {
            if (color_match[e.v] == 0 || dfs(color_match[e.v], col)) {
                color_match[e.v] = mathcing[e.u];
                return true;
            }
        }
    }
    return false;
}

bool augment(int col) {
    fill(vis.begin(), vis.end(), false);
    for (int i = 1; i <= n; ++i) {
        if (mathcing[i] == 0 && dfs(i, col)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    adj.resize(n + 1);
    color_match.resize(n + 1, 0);
    mathcing.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        Edge e;
        cin >> e.u >> e.v >> e.c >> e.t;
        e.idx = i + 1;
        adj[e.u].push_back(e);
        adj[e.v].push_back(e);
        color_edges[e.c].push_back(i);
        ms.insert({e.t, i});
    }

    while (!ms.empty()) {
        auto it = ms.begin();
        int t = it->first;
        int idx = it->second;
        ms.erase(it);
        auto &e = adj[adj[adj[idx][0].u][0].v][0];
        int c = e.c;

        if (color_destroy.find(c) == color_destroy.end()) {
            color_destroy[c] = t;
        }

        fill(vis.begin(), vis.end(), false);
        if (!augment(c)) {
            ms.insert({color_destroy[c], color_edges[c].back()});
            color_edges[c].pop_back();
            color_destroy.erase(c);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (mathcing[i] != 0) {
            color_destroy[adj[adj[i][0].u][0].c] = max(color_destroy[adj[adj[i][0].u][0].c], adj[mathcing[i]][0].t);
        }
    }

    if (color_destroy.size() != color_edges.size()) {
        cout << "No";
        return 0;
    }

    long long ans = 0;
    vector<int> result;
    for (auto &p : color_destroy) {
        ans += p.second;
        result.push_back(color_edges[p.first].back() + 1);
    }

    cout << "Yes\n";
    cout << ans << " " << result.size() << "\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 == result.size() ? "\n" : " ");
    }

    return 0;
}