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
const int INF = 1e8;

struct Edge {
    int to, cost;
};

vector<vector<Edge>> graph;
vector<bool> visited;
vector<int> dist;

void bellmanFord(int start, vector<int>& dist) {
    dist.assign(graph.size(), INF);
    dist[start] = 0;
    for (int i = 0; i < graph.size() - 1; ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            for (const auto& edge : graph[j]) {
                if (dist[j] != INF && dist[j] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[j] + edge.cost;
                }
            }
        }
    }
    for (int j = 0; j < graph.size(); ++j) {
        for (const auto& edge : graph[j]) {
            if (dist[j] != INF && dist[j] + edge.cost < dist[edge.to]) {
                dist[edge.to] = dist[j] + edge.cost;
                visited[edge.to] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    graph.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < m; ++i) {
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        --u; --v;
        graph[u].push_back({v, c1});
        graph[v].push_back({u, c2});
    }
    vector<int> dist(n, -1);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        fill(visited.begin(), visited.end(), false);
        bellmanFord(i, dist);
    }
    for (int i = 0; i < n; ++i) {
        if (visited[i]) {
            vector<bool> seen(n, false);
            int j = i;
            int len = 0;
            while (!seen[j]) {
                seen[j] = true;
                ++len;
                for (const auto& edge : graph[j]) {
                    if (visited[edge.to]) {
                        j = edge.to;
                        break;
                    }
                }
            }
            ans = min(len, ans);
        }
    }
    cout << (ans == INF ? 0 : ans) << '\n';
    return 0;
}