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

#define int long long

const int inf = 1e18;
const int mod = 998244353;

int n, m;
vector<int> p, c;
vector<vector<int>> clubs;

void solve() {
    cin >> n >> m;
    p.resize(n);
    c.resize(n);
    for (int &x : p) cin >> x;
    for (int &x : c) cin >> x, --x;
    clubs.resize(m);
    for (int i = 0; i < n; ++i) clubs[c[i]].push_back(i);
    int d;
    cin >> d;
    vector<bool> left(n);
    for (int i = 0; i < d; ++i) {
        int x;
        cin >> x;
        --x;
        left[x] = true;
        for (int j = 0; j < m; ++j) {
            if (find(clubs[j].begin(), clubs[j].end(), x) != clubs[j].end()) {
                auto it = find(clubs[j].begin(), clubs[j].end(), x);
                clubs[j].erase(it);
            }
        }
        int ans = 0;
        vector<int> vis(clubs.size(), 0);
        while (true) {
            bool found = false;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    found = true;
                    break;
                }
            }
            if (!found) break;
            vector<int> cur;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    cur.push_back(p[clubs[j][vis[j]]]);
                }
            }
            sort(cur.begin(), cur.end());
            int mex = 0;
            for (int x : cur) {
                if (x == mex) ++mex;
            }
            ans = max(ans, mex);
            int minval = inf;
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]]) {
                    minval = min(minval, p[clubs[j][vis[j]]]);
                }
            }
            for (int j = 0; j < m; ++j) {
                if (vis[j] < clubs[j].size() && !left[clubs[j][vis[j]]] && p[clubs[j][vis[j]]] == minval) {
                    ++vis[j];
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}

signed main() {
    ((void)0); ((void)0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}