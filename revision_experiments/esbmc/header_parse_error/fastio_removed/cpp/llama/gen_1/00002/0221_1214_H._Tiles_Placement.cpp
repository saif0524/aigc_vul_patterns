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

const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
int d[MAXN], par[MAXN], sz[MAXN], c[MAXN];

void dfs(int v, int p = -1) {
    sz[v] = 1;
    for (int to : g[v]) {
        if (to == p) continue;
        par[to] = v;
        d[to] = d[v] + 1;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

int main() {
    ((void)0); ((void)0);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    int m = n - k + 1;
    int v = -1, max_d = -1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > max_d) {
            max_d = d[i];
            v = i;
        }
    }

    queue<int> q; q.push(v);
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (sz[cur] <= m) {
            c[cur] = 1;
            cnt++;
            if (cnt == k) {
                cout << "Yes\n";
                for (int i = 1; i <= n; i++) {
                    if (c[i] == 0) {
                        cout << 1 << " ";
                    } else {
                        cout << c[i] << " ";
                        c[i]++;
                    }
                }
                return 0;
            }
        } else {
            for (int to : g[cur]) {
                if (to != par[cur]) q.push(to);
            }
        }
    }

    cout << "No";
    return 0;
}