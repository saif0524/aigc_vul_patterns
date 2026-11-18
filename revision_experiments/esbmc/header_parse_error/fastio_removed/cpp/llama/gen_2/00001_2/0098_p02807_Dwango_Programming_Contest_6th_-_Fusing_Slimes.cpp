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
const int mod = 1e9 + 7;

long long powmod(long long a, long long b) {
    long long res = 1;
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
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vector<long long> fac(n);
    fac[0] = 1;
    for (int i = 1; i < n; ++i) fac[i] = fac[i - 1] * i % mod;
    vector<int> cnt(n - 1);
    for (int i = 0; i < n - 1; ++i) cnt[i] = x[i + 1] - x[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        long long tot = 0;
        for (int j = 0; j < i + 1; ++j) tot = (tot + fac[i] * inv(fac[j]) % mod * inv(fac[i - j]) % mod * (i - j)) % mod;
        ans = (ans + cnt[i] * tot) % mod;
    }
    cout << ans << endl;
    return 0;
}