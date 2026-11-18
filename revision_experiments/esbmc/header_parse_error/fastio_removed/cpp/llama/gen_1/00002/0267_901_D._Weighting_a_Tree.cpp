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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int c[MAXN];
int deg[MAXN];
int res[MAXN];

void dfs(int v, int p, int& global_flow, vector<char>& used) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to, v, global_flow, used);
        if (res[to] == 0) {
            res[to] = 1;
            res[v] -= 1;
            global_flow += 1;
        }
    }
}

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    vector<char> used(n + 1);
    int global_flow = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            dfs(i, 0, global_flow, used);
        }
    }

    if (global_flow != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        res[i] = c[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int to : g[i]) {
            if (i < to) {
                cout << res[i] << "\n";
                res[to] -= res[i];
                res[i] = 0;
            }
        }
    }

    return 0;
}