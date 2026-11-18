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

struct Event {
    int a, b, c;
};

void solve() {
    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;

    vector<vector<Edge>> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }

    vector<Event> events(E);
    for (int i = 0; i < E; i++) {
        cin >> events[i].a >> events[i].b >> events[i].c;
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(1 << E, vector<int>(R + 1, INF)));
    vector<vector<vector<bool>>> used(N, vector<vector<bool>>(1 << E, vector<bool>(R + 1, false)));
    queue<tuple<int, int, int, int>> Q;

    dist[S][0][0] = 0;
    Q.emplace(S, 0, 0, 0);

    while (!Q.empty()) {
        int v, mask, cost, day;
        tie(v, mask, cost, day) = Q.front();
        Q.pop();

        if (used[v][mask][day]) continue;
        used[v][mask][day] = true;

        for (const auto& e : G[v]) {
            if (dist[e.to][mask][day + 1] > dist[v][mask][day] + e.cost) {
                dist[e.to][mask][day + 1] = dist[v][mask][day] + e.cost;
                Q.emplace(e.to, mask, dist[e.to][mask][day + 1], day + 1);
            }
        }

        for (const auto& event : events) {
            if (event.c == v && (mask & (1 << &event - &events[0])) == 0) {
                if (dist[event.a][mask | (1 << &event - &events[0])][day] > dist[v][mask][day]) {
                    dist[event.a][mask | (1 << &event - &events[0])][day] = dist[v][mask][day];
                    Q.emplace(event.a, mask | (1 << &event - &events[0]), dist[event.a][mask | (1 << &event - &events[0])][day], day);
                }
                if (dist[event.b][mask | (1 << &event - &events[0])][day] > dist[v][mask][day]) {
                    dist[event.b][mask | (1 << &event - &events[0])][day] = dist[v][mask][day];
                    Q.emplace(event.b, mask | (1 << &event - &events[0]), dist[event.b][mask | (1 << &event - &events[0])][day], day);
                }
            }
        }

        if (day <= R && dist[S][mask][0] > dist[v][mask][day] + 1) {
            dist[S][mask][0] = dist[v][mask][day] + 1;
            Q.emplace(S, mask, dist[S][mask][0], 0);
        }
    }

    int ans = INF;
    for (int i = 0; i < (1 << E); i++) {
        for (int j = 0; j <= R; j++) {
            ans = min(ans, dist[T][i][j] + (j + (i > 0)) / (R + 1));
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    ((void)0);
    ((void)0);
    solve();
    return 0;
}