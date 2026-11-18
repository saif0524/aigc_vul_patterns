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
vector<int> depth;
vector<int> leaf_count;

void dfs(int u, int d) {
    depth[u] = d;
    if (adj[u].size() == 0) {
        leaf_count[u] = 1;
        return;
    }
    for (int v : adj[u]) {
        dfs(v, d + 1);
        leaf_count[u] += leaf_count[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    adj.resize(n + 1);
    depth.resize(n + 1);
    leaf_count.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1, 0);
    priority_queue<pair<int, int>> max_heap;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 0) {
            max_heap.push({depth[i], leaf_count[i]});
        }
    }
    int ans = 0;
    set<pair<int, int>> active_leaves;
    while (!max_heap.empty()) {
        auto [d, cnt] = max_heap.top();
        max_heap.pop();
        active_leaves.insert({d, cnt});
        if (active_leaves.size() > k + 1) {
            auto it = active_leaves.begin();
            ans += it->second;
            active_leaves.erase(it);
        }
    }
    for (auto [d, cnt] : active_leaves) {
        ans += cnt;
    }
    cout << ans;
}