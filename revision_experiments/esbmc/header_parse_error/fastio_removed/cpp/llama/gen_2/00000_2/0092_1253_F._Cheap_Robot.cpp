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

#define MAXN 100005
#define INF 1000000000
#define ll long long

int n, m, k, q;
vector<pair<int, int>> edges[MAXN];
int ans[MAXN];

struct Edge {
    int v, w, id;
    bool operator<(const Edge& e) const {
        return w > e.w;
    }
};

void dijkstra(int s, vector<int>& dist) {
    priority_queue<Edge> pq;
    pq.push({s, 0, -1});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().v;
        int w = pq.top().w;
        pq.pop();

        for (auto& e : edges[u]) {
            int v = e.first;
            int edge_w = e.second;

            if (w + edge_w < dist[v]) {
                dist[v] = w + edge_w;
                pq.push({v, dist[v], -1});
            }
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    cin >> n >> m >> k >> q;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }

    vector<vector<int>> dist(k, vector<int>(n, INF));
    for (int i = 0; i < k; i++) {
        dijkstra(i, dist[i]);
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int l = 0, r = 1e9 + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            bool ok = false;

            vector<int> d(n, INF);
            d[u] = mid;
            priority_queue<Edge> pq;
            pq.push({u, 0, -1});

            while (!pq.empty()) {
                int u1 = pq.top().v;
                int w = pq.top().w;
                pq.pop();

                for (auto& e : edges[u1]) {
                    int v1 = e.first;
                    int edge_w = e.second;

                    if (w + edge_w <= mid) {
                        if (dist[v][v1] < d[v1]) {
                            d[v1] = dist[v][v1];
                            pq.push({v1, dist[v][v1], -1});
                        } else if (d[u1] + edge_w < d[v1]) {
                            d[v1] = d[u1] + edge_w;
                            pq.push({v1, d[v1], -1});
                        }
                    }
                }
            }

            for (int j = 0; j < k; j++) {
                if (d[j] <= mid) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        ans[i] = l;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}