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
const int MAXM = 105;

vector<int> adj[MAXN][MAXM];
bool vis[MAXN];

void dfs(int u, int color, int n) {
    vis[u] = true;
    for (int v : adj[u][color]) {
        if (!vis[v]) {
            dfs(v, color, n);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--, c--;
        adj[u][c].push_back(v);
        adj[v][c].push_back(u);
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        int ans = 0;
        for (int i = 0; i < m; i++) {
            memset(vis, 0, sizeof vis);
            dfs(u, i, n);
            if (vis[v]) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}