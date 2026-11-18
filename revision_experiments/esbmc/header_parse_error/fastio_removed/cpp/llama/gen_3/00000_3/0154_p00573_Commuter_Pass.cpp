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

const int INF = 1e9;
const int MAXN = 100005;
const int MAXM = 200005;

struct Edge {
    int to, cost, id;
};

vector<Edge> graph[MAXN];

int N, M, S, T, U, V;
int distS[MAXN], distT[MAXN], distU[MAXN];

void dijkstra(int src, int *dist) {
    fill(dist, dist + N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, c, id] : graph[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> N >> M >> S >> T >> U >> V;

    vector<tuple<int, int, int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c, i});
        graph[v].push_back({u, c, i});
        edges.emplace_back(u, v, c, i);
    }

    dijkstra(S, distS);
    dijkstra(T, distT);

    int path = -1, minCost = INF;
    for (int u = 1; u <= N; u++) {
        if (distS[u] + distT[u] < minCost) {
            minCost = distS[u] + distT[u];
            path = u;
        }
    }

    dijkstra(U, distU);

    int ans = INF;
    for (auto [u, v, c, id] : edges) {
        if (distS[u] < distS[v] && distS[u] + distT[v] == minCost) {
            ans = min(ans, distU[v] + distT[u] - distT[v]);
        }
        if (distS[v] < distS[u] && distS[v] + distT[u] == minCost) {
            ans = min(ans, distU[u] + distT[v] - distT[u]);
        }
    }

    cout << ans << '\n';

    return 0;
}