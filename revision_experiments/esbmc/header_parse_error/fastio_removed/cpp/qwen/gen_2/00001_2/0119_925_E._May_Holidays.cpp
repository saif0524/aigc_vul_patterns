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

int n, m;
vector<vector<int>> adj;
int t[100005], ans[100005], cnt[100005], dis[100005];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    cnt[u] += 1;
}

void imp(int u) {
    if (dis[u] > t[u]) {
        ans[m]++;
        dis[u] = 0;
    } else if (dis[u] == t[u]) {
        ans[m]--;
        dis[u] = 0;
    }
}

void update(int u, int p, int v) {
    if (u == 0) return;
    dis[u] += v;
    imp(u);
    update(p, adj[p][0] == u ? adj[p][1] : adj[p][0], v);
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> t[i];
    dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        if (x > 0) {
            update(x, adj[x].size() ? adj[x][0] : 0, -1);
        } else {
            update(-x, adj[-x].size() ? adj[-x][0] : 0, 1);
        }
        if (i > 1) ans[i] = ans[i - 1];
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << " \n"[i == m];
}