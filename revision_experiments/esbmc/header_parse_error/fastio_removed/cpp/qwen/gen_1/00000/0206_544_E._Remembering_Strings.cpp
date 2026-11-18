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
vector<string> s;
vector<vector<int>> cost;
int dp[1<<20][21][21];

int solve(int mask, int pos, int last) {
    if (mask == (1<<n) - 1) return 0;
    if (pos == m) return 1e9;
    int &ret = dp[mask][pos][last];
    if (ret != -1) return ret;
    ret = 1e9;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1<<i))) {
            cnt[s[i][pos] - 'a']++;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mask & (1<<i)) continue;
        if (cnt[s[i][pos] - 'a'] == 1 && s[i][pos] - 'a' != last) {
            ret = min(ret, solve(mask | (1<<i), pos, s[i][pos] - 'a'));
        }
    }
    for (int c = 0; c < 26; ++c) {
        if (c == last) continue;
        int new_mask = mask;
        int total_cost = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1<<i)) continue;
            if (s[i][pos] - 'a' == c) {
                new_mask |= (1<<i);
            } else {
                total_cost += cost[i][pos];
            }
        }
        ret = min(ret, total_cost + solve(new_mask, pos + 1, c));
    }
    return ret;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> m;
    s.resize(n);
    for (auto &x : s) cin >> x;
    cost.resize(n, vector<int>(m));
    for (auto &v : cost) {
        for (auto &x : v) cin >> x;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0, 26) << "\n";
}