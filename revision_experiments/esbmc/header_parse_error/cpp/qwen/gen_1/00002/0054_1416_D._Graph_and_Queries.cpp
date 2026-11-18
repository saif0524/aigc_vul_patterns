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

const int N = 2e5 + 5;
const int M = 3e5 + 5;

vector<pair<int, int>> adj[N];
bitset<N> active_edge;
int p[N];
int dsu[N], sz[N], max_p[N];

int find(int x) {
    if (dsu[x] == x) return x;
    return dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    dsu[y] = x;
    sz[x] += sz[y];
    if (max_p[x] < max_p[y]) max_p[x] = max_p[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        dsu[i] = i;
        sz[i] = 1;
        max_p[i] = p[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    active_edge.set();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            int root = find(v);
            cout << max_p[root] << '\n';
            max_p[root] = 0;
        } else {
            int edge_id;
            cin >> edge_id;
            --edge_id;
            active_edge[edge_id] = 0;
            int u = edges[edge_id].first, v = edges[edge_id].second;
            for (auto [neighbor, id] : adj[u]) {
                if (id == edge_id) continue;
                if (!active_edge[id]) continue;
                merge(u, neighbor);
                break;
            }
            for (auto [neighbor, id] : adj[v]) {
                if (id == edge_id) continue;
                if (!active_edge[id]) continue;
                merge(v, neighbor);
                break;
            }
        }
    }
}