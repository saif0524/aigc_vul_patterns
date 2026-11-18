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

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<vector<pair<int, int>>> cycles;

void find_cycles(int v, int p) {
    visited[v] = true;
    parent[v] = p;
    for (int u : adj[v]) {
        if (u == parent[v]) continue;
        if (visited[u]) {
            vector<pair<int, int>> cycle;
            int cur = v;
            while (cur != u) {
                cycle.emplace_back(min(cur, parent[cur]), max(cur, parent[cur]));
                cur = parent[cur];
            }
            cycle.emplace_back(min(u, v), max(u, v));
            sort(cycle.begin(), cycle.end());
            cycles.push_back(cycle);
        } else {
            find_cycles(u, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            find_cycles(i, -1);
        }
    }
    if (cycles.empty()) {
        if (n == 1) {
            cout << "YES\n";
            cout << "1\n";
            cout << "1 1\n";
        } else {
            cout << "NO\n";
        }
        return 0;
    }
    for (const auto& c : cycles) {
        if (c.size() != n) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << "0\n";
}