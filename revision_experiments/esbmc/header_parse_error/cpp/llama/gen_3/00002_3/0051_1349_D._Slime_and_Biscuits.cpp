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
const int mod = 998244353;

long long powmod(long long a, long long b) {
    long long res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return powmod(a, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<long long> dp(sum + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++) {
        long long p = i * inv(sum) % mod;
        long long q = (sum - i) * inv(sum) % mod;
        long long r = (n - 1) * inv(n) % mod;
        dp[i] = (p * (dp[i - 1] + 1) % mod + (q * r % mod * (dp[i - 1] + 1) % mod + q * (1 - r) % mod * (dp[i] + 1) % mod)) % mod;
        dp[i] = dp[i] * inv((1 - q * (1 - r) % mod + mod) % mod) % mod;
    }
    cout << dp[sum] << endl;
    return 0;
}