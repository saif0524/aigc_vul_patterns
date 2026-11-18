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

const int MAXN = 55;
const int MAXM = 2505;
const int INF = 1e9;

int n, m, k, c, d;
int dist[MAXN][MAXN];
int a[MAXN];
vector<pair<int, int>> edges;
int path[MAXN];
int time_taken[MAXN];
int used_edges[MAXM];
int used_edges_cnt[MAXM];
int used_edges_time[MAXM];

void floyd_warshall() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for (auto& e : edges) {
        dist[e.first][e.second] = 1;
        dist[e.second][e.first] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int calculate_discontent() {
    int total_discontent = 0;
    for (int i = 1; i <= k; ++i) {
        total_discontent += c * time_taken[i];
    }
    for (int i = 0; i < m; ++i) {
        int x = edges[i].first;
        int y = edges[i].second;
        total_discontent += d * used_edges_cnt[i] * used_edges_cnt[i];
    }
    return total_discontent;
}

void backtrack(int idx) {
    if (idx > k) {
        int current_discontent = calculate_discontent();
        if (current_discontent < best_discontent) {
            best_discontent = current_discontent;
            best_path = path;
            best_time_taken = time_taken;
            best_used_edges = used_edges;
            best_used_edges_cnt = used_edges_cnt;
            best_used_edges_time = used_edges_time;
        }
        return;
    }
    int u = a[idx];
    for (int t = 0; t <= dist[u][1]; ++t) {
        time_taken[idx] = t;
        for (int i = 0; i < m; ++i) {
            int x = edges[i].first;
            int y = edges[i].second;
            if (dist[u][x] + 1 + t == dist[u][1] && dist[x][1] == dist[u][1] - 1) {
                used_edges[i]++;
                used_edges_cnt[i]++;
                used_edges_time[i] = t;
                path[idx] = x;
                backtrack(idx + 1);
                used_edges[i]--;
                used_edges_cnt[i]--;
                used_edges_time[i] = 0;
            } else if (dist[u][y] + 1 + t == dist[u][1] && dist[y][1] == dist[u][1] - 1) {
                used_edges[i]++;
                used_edges_cnt[i]++;
                used_edges_time[i] = t;
                path[idx] = y;
                backtrack(idx + 1);
                used_edges[i]--;
                used_edges_cnt[i]--;
                used_edges_time[i] = 0;
            }
        }
        path[idx] = 1;
        backtrack(idx + 1);
    }
}

int main() {
    cin >> n >> m >> k >> c >> d;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    floyd_warshall();
    backtrack(1);
    cout << best_discontent << "\n";
    return 0;
}