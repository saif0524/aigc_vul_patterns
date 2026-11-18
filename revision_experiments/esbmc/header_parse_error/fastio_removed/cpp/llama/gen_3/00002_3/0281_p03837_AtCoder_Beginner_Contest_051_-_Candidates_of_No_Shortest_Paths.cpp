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

const int MAXN = 105;
const int INF = 1e9;

struct Edge {
    int u, v, w;
};

int n, m;
Edge edges[MAXN];
int dis[MAXN][MAXN];

void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        dis[edges[i].u][edges[i].v] = edges[i].w;
        dis[edges[i].v][edges[i].u] = edges[i].w;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

bool check(int id) {
    int u = edges[id].u, v = edges[id].v, w = edges[id].w;
    edges[id].w = INF;
    floyd();
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] > dis[i][u] + w + dis[v][j] || dis[i][j] > dis[i][v] + w + dis[u][j]) {
                flag = true;
            }
        }
    }
    edges[id].w = w;
    return flag;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    floyd();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (check(i)) ans++;
    }
    cout << ans << endl;
    return 0;
}