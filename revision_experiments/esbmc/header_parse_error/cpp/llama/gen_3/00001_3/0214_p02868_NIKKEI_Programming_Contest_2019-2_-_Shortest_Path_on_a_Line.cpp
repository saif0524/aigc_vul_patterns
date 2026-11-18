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

typedef long long ll;

const int MAXN = 1e5 + 10;

ll dis[MAXN];

struct Edge {
    int l, r, c;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto& e : edges) {
        cin >> e.l >> e.r >> e.c;
    }

    vector<vector<int>> adj(n + 1);
    for (auto& e : edges) {
        for (int i = e.l; i < e.r; ++i) {
            for (int j = i + 1; j <= e.r; ++j) {
                if (adj[i].empty() || *min_element(adj[i].begin(), adj[i].end()) > e.c) {
                    adj[i].push_back(e.c);
                    adj[i].push_back(j);
                }
                else if (*min_element(adj[i].begin(), adj[i].end()) == e.c && 
                         find(adj[i].begin(), adj[i].end(), j) == adj[i].end()) {
                    adj[i].push_back(e.c);
                    adj[i].push_back(j);
                }

                if (adj[j].empty() || *min_element(adj[j].begin(), adj[j].end()) > e.c) {
                    adj[j].push_back(e.c);
                    adj[j].push_back(i);
                }
                else if (*min_element(adj[j].begin(), adj[j].end()) == e.c && 
                         find(adj[j].begin(), adj[j].end(), i) == adj[j].end()) {
                    adj[j].push_back(e.c);
                    adj[j].push_back(i);
                }
            }
        }
    }

    fill(dis, dis + n + 1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (dis[u] != w) {
            continue;
        }

        for (int i = 0; i < adj[u].size(); i += 2) {
            int v = adj[u][i + 1];
            int c = adj[u][i];
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                pq.push({dis[v], v});
            }
        }
    }

    cout << (dis[n] == LLONG_MAX ? -1 : dis[n]) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}