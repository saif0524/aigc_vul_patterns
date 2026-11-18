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
const int MOD = 998244353;

struct Binomial {
    vector<int> fact, ifact;
    Binomial(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (int)(1LL * fact[i - 1] * i % MOD);
        ifact[n] = inv(fact[n]);
        for (int i = n - 1; i >= 0; i--) ifact[i] = (int)(1LL * ifact[i + 1] * (i + 1) % MOD);
    }
    int inv(int a) {
        int b = MOD, u = 1, v = 0;
        while (a) {
            int t = b / a;
            b -= t * a; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += MOD;
        return u;
    }
    int C(int n, int k) {
        if (n < k || k < 0) return 0;
        return (int)(1LL * fact[n] * ifact[k] % MOD * ifact[n - k] % MOD);
    }
};

int n, c;
vector<int> a;
const int MAXN = 3005;
int dp[MAXN][MAXN];
int ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> c;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Binomial binom(n);
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> cnt(c + 1);
        for (int i = 0; i < n; i++) if (mask >> i & 1) cnt[a[i]]++;
        int p = 0;
        for (int i = 1; i <= c; i++) if (cnt[i]) p++;
        int k = __builtin_popcount(mask);
        dp[k][p] = (dp[k][p] + 1) % MOD;
    }
    for (int k = 0; k <= n; k++) {
        for (int p = 0; p <= c; p++) {
            if (p <= k) {
                ans[p] = (ans[p] + dp[k][p]) % MOD;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}