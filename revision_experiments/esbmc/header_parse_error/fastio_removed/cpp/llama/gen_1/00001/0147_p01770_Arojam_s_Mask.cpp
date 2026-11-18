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

struct Edge {
    int to, cost;
};

int main() {
    ((void)0);
    ((void)0);

    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;

    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }

    vector<tuple<int, int, int>> events(E);
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        events[i] = {a, b, c};
    }

    int ans = INF;
    for (int mask = 0; mask < (1 << E); mask++) {
        vector<vector<Edge>> newGraph = graph;
        for (int i = 0; i < E; i++) {
            if (mask & (1 << i)) {
                int a, b, c;
                tie(a, b, c) = events[i];
                newGraph[a].push_back({b, 1});
                newGraph[b].push_back({a, 1});
            }
        }

        vector<vector<int>> dist(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (const auto& edge : newGraph[v]) {
                    int to = edge.to;
                    if (dist[i][v] + edge.cost < dist[i][to]) {
                        dist[i][to] = dist[i][v] + edge.cost;
                        q.push(to);
                    }
                }
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int cost = 0;
        int d = dist[S][T];
        int ocarina = 0;
        while (d > R) {
            ocarina++;
            d -= R;
            cost += R;
        }
        cost += d;
        ans = min(ans, cost + ocarina);
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}