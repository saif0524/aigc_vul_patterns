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

const int MAX_V = 105;
const int INF = 1e9;

struct Edge {
    int from, to, cost;
};

int V, E, root;
vector<Edge> edges;

int seen[MAX_V], low[MAX_V], scc[MAX_V], label, num_scc;
stack<int> S;
vector<int> G[MAX_V], rG[MAX_V];
int dp[MAX_V][MAX_V];

int add_edge(int from, int to, int cost) {
    edges.push_back((Edge){from, to, cost});
    return edges.size() - 1;
}

void dfs(int v) {
    seen[v] = 1;
    low[v] = label++;
    S.push(v);
    for (auto &e : G[v]) {
        if (!seen[e]) {
            dfs(e);
            low[v] = min(low[v], low[e]);
        } else if (!scc[e]) {
            low[v] = min(low[v], low[e]);
        }
    }

    if (low[v] == seen[v]) {
        while (1) {
            int u = S.top(); S.pop();
            scc[u] = num_scc;
            if (u == v) break;
        }
        num_scc++;
    }
}

void init_scc() {
    memset(seen, 0, sizeof(seen));
    memset(scc, 0, sizeof(scc));
    label = num_scc = 0;
    while (!S.empty()) S.pop();

    for (int i = 0; i < V; i++) {
        if (!seen[i]) dfs(i);
    }

    for (int i = 0; i < V; i++) {
        rG[i].clear();
        for (auto &e : G[e.from]) {
            if (scc[e.from] == scc[e.to]) continue;
            rG[scc[e.from]].push_back(scc[e.to]);
        }
    }
}

int solve() {
    init_scc();
    int new_V = num_scc;

    for (int i = 0; i < new_V; i++) {
        for (int j = 0; j < new_V; j++) {
            dp[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (auto &e : edges) {
        int from_scc = scc[e.from];
        int to_scc = scc[e.to];
        dp[from_scc][to_scc] = min(dp[from_scc][to_scc], e.cost);
    }

    int root_scc = scc[root];

    for (int k = 0; k < new_V; k++) {
        for (int i = 0; i < new_V; i++) {
            for (int j = 0; j < new_V; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    int min_cost = 0;
    for (int i = 0; i < new_V; i++) {
        if (i == root_scc) continue;
        if (dp[root_scc][i] >= INF) return -1; // No such arborescence
        min_cost += dp[root_scc][i];
    }

    return min_cost;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> V >> E >> root;

    for (int i = 0; i < V; i++) {
        G[i].clear();
    }
    edges.clear();

    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        add_edge(s, t, w);
        G[s].push_back(i);
    }

    cout << solve() << "\n";

    return 0;
}