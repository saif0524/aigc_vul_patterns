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

const int MAXN = 100010;
const int LOGN = 20;
vector<pair<int, int>> adj[MAXN];
int depth[MAXN];
int parent[MAXN][LOGN];
int max_dist[MAXN][LOGN];
int n;

void preprocess_lca(int u, int p, int d) {
    parent[u][0] = p;
    depth[u] = d;
    for (int i = 1; i < LOGN; i++) {
        if (parent[u][i - 1] != -1) {
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
            max_dist[u][i] = max(max_dist[u][i - 1], max_dist[parent[u][i - 1]][i - 1]);
        }
    }
    for (auto &e : adj[u]) {
        int v = e.first;
        int w = e.second;
        if (v != p) {
            max_dist[v][0] = w;
            preprocess_lca(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {
    int max_val = 0;
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[u][i] != -1 && depth[parent[u][i]] >= depth[v]) {
            max_val = max(max_val, max_dist[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) return max_val;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            max_val = max(max_val, max(max_dist[u][i], max_dist[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    max_val = max(max_val, max(max_dist[u][0], max_dist[v][0]));
    return max_val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    memset(parent, -1, sizeof(parent));
    preprocess_lca(1, -1, 0);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        int ab = lca(a, b);
        int ac = lca(a, c);
        int bc = lca(b, c);
        cout << max(ab, max(ac, bc)) << "\n";
    }
}