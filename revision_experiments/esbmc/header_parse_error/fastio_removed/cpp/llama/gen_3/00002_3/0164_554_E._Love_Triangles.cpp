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

const int MOD = 1000000007;

int main() {
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a][b] = g[b][a] = c;
    }

    for (int i = 0; i < n; i++) {
        if (g[i][i]!= -1) {
            cout << 0 << endl;
            return 0;
        }
    }

    int ans = 1;
    int cnt = 0;
    vector<int> comp(n, -1);
    vector<int> sz(n, 0);

    for (int i = 0; i < n; i++) {
        if (comp[i]!= -1) continue;

        vector<int> q;
        q.push_back(i);
        comp[i] = cnt;
        int s = 0;
        int x = 0;
        while (!q.empty()) {
            int u = q.back();
            q.pop_back();
            s += 1;
            for (int v = 0; v < n; v++) {
                if (g[u][v]!= -1) {
                    if (comp[v]!= -1 && comp[v]!= comp[u]) {
                        cout << 0 << endl;
                        return 0;
                    }
                    if (comp[v] == -1) {
                        comp[v] = comp[u];
                        q.push_back(v);
                    }
                } else {
                    x += 1;
                }
            }
        }

        if (s == 1) {
            ans = (ans * 2) % MOD;
        } else {
            ans = (ans * (1 + (1LL << (x - s))) % MOD) % MOD;
        }

        sz[cnt] = s;
        cnt += 1;
    }

    if (cnt == 1) {
        ans = (ans - 2 + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}