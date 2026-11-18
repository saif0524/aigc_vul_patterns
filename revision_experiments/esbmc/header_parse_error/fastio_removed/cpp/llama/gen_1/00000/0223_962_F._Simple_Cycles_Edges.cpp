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

const int MAX_N = 100005;

vector<pair<int, int>> adj[MAX_N];
bool visited[MAX_N];
bool onCycle[MAX_N];
int parent[MAX_N];
int edgeId[MAX_N];
int discoveryTime[MAX_N];
int low[MAX_N];

int timer = 0;

void dfs(int u, int p) {
    visited[u] = true;
    discoveryTime[u] = timer;
    low[u] = timer;
    timer++;

    for (auto& e : adj[u]) {
        int v = e.first;
        int id = e.second;
        if (!visited[v]) {
            parent[v] = u;
            edgeId[v] = id;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == discoveryTime[v] && parent[u] != v) {
                onCycle[id] = true;
            }
        } else if (v != p) {
            low[u] = min(low[u], discoveryTime[v]);
            if (discoveryTime[v] < discoveryTime[u]) {
                onCycle[edgeId[u]] = true;
                onCycle[id] = true;
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges.push_back(i);
    }
    dfs(0, -1);
    int count = 0;
    vector<int> result;
    for (int i = 0; i < m; i++) {
        if (onCycle[i]) {
            count++;
            result.push_back(i + 1);
        }
    }
    cout << count << "\n";
    sort(result.begin(), result.end());
    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ((void)0);
    ((void)0);
    solve();
    return 0;
}