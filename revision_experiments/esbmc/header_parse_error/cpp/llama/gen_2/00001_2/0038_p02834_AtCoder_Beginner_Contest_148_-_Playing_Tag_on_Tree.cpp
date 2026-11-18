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
vector<int> adj[MAXN];
int depth[MAXN];

void dfs(int u, int p, int dep) {
    depth[u] = dep;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, dep + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v;
    cin >> n >> u >> v;
    u--, v--;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(u, -1, 0);
    vector<int> dist_from_u(n);
    for (int i = 0; i < n; i++) dist_from_u[i] = depth[i];
    for (int i = 0; i < n; i++) depth[i] = 0;
    dfs(v, -1, 0);
    vector<int> dist_from_v(n);
    for (int i = 0; i < n; i++) dist_from_v[i] = depth[i];

    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, (dist_from_u[i] + dist_from_v[i]));
    }
    cout << (ans - 1) / 2 << '\n';
    return 0;
}