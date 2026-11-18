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
    int v, w;
    Edge(int a, int b) : v(a), w(b) {}
};

vector<vector<Edge>> graph;
vector<int> special;

void bfs(int start, vector<int>& dist) {
    dist.assign(graph.size(), INT_MAX);
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;

    while (!q.empty()) {
        auto [u, w] = q.front();
        q.pop();

        for (const auto& edge : graph[u]) {
            if (edge.w > w && dist[edge.v] > w) {
                dist[edge.v] = w;
                q.push({edge.v, edge.w});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    graph.resize(n);

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        special.push_back(--x);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<int> ans(k);
    for (int i = 0; i < k; ++i) {
        vector<int> dist;
        bfs(special[i], dist);
        int mx = 0;
        for (int j = 0; j < k; ++j) {
            mx = max(mx, dist[special[j]]);
        }
        ans[i] = mx;
    }

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}