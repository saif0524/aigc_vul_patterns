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

vector<vector<int>> adj;
vector<int> par;
vector<bool> visited;

void dfs(int u, int p) {
    visited[u] = true;
    par[u] = p;
    for (int v : adj[u]) {
        if (!visited[v] && v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    adj.resize(n + 1);
    par.resize(n + 1, -1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    vector<pair<int, int>> extra;
    for (int i = 2; i <= n; ++i) {
        if (par[adj[i][0]] != i) {
            extra.push_back({i, adj[i][0]});
        }
    }
    int cycles = extra.size();
    cout << cycles << "\n";
    for (auto [u, v] : extra) {
        int x = u, y = v;
        while (x != y) {
            if (x == 1 || visited[par[x]]) {
                swap(x, y);
            }
            visited[x] = true;
            x = par[x];
        }
        cout << u << " " << v << " " << u << " " << x << "\n";
    }
}