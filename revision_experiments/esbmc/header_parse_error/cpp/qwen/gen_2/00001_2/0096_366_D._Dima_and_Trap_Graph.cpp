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

const int MAXN = 1005;
const int INF = 1e9 + 7;

int n, m;
vector<pair<int, pair<int, int>>> adj[MAXN];
bool visited[MAXN];

int dfs(int u, int x) {
    if (u == n) return 1;
    visited[u] = true;
    int result = 0;
    for (auto& e : adj[u]) {
        int v = e.first, l = e.second.first, r = e.second.second;
        if (!visited[v] && l <= x && x <= r) {
            result |= dfs(v, x);
        }
    }
    visited[u] = false;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, l, r;
        cin >> a >> b >> l >> r;
        adj[a].emplace_back(b, make_pair(l, r));
        adj[b].emplace_back(a, make_pair(l, r));
    }
    int max_loyalty = 0;
    for (int x = 1; x <= 1000000; ++x) {
        memset(visited, false, sizeof(visited));
        if (dfs(1, x)) {
            max_loyalty++;
        }
    }
    if (max_loyalty == 0) {
        cout << "Nice work, Dima!" << endl;
    } else {
        cout << max_loyalty << endl;
    }
    return 0;
}