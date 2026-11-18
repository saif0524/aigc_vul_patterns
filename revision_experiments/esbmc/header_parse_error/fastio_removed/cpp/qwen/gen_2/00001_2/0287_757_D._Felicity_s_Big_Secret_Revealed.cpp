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

const int MOD = 1e9 + 7;
const int MAXN = 75;
int n;
string s;
int dp[MAXN][MAXN][1 << 16];
int pre[MAXN][MAXN];

int calc(int l, int r) {
    if (l > r) return 0;
    if (pre[l][r] != -1) return pre[l][r];
    int val = 0;
    for (int i = l; i <= r; ++i) {
        val = val * 2 + (s[i] - '0');
    }
    pre[l][r] = val;
    return val;
}

int solve(int pos, int cnt, int mask) {
    if (cnt > n) return 0;
    if (pos == n + 1) {
        int m = 0;
        for (int i = 1; i <= 16; ++i) {
            if (mask & (1 << i)) {
                m = max(m, i);
            }
        }
        for (int i = 1; i <= m; ++i) {
            if ((mask & (1 << i)) == 0) return 0;
        }
        return 1;
    }
    if (dp[pos][cnt][mask] != -1) return dp[pos][cnt][mask];
    int res = solve(pos + 1, cnt, mask);
    if (pos > 0) {
        int val = calc(pos - 1, n - 1);
        if (val > 0 && val <= 16) {
            res = (res + solve(pos + 1, cnt + 1, mask | (1 << val))) % MOD;
        }
    }
    dp[pos][cnt][mask] = res;
    return res;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    int ans = 0;
    for (int k = 2; k <= n + 1; ++k) {
        int res = solve(0, 0, 0);
        ans = (ans + res) % MOD;
    }
    cout << ans << '\n';
    return 0;
}