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

long long comb(int n, int k) {
    if (k > n) return 0;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) % MOD;
        res = res * modinv(i + 1) % MOD;
    }
    return res;
}

long long modinv(long long a) {
    long long b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return u;
}

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i=0; i<=k; ++i){
        long long c1 = comb(n, i);
        long long c2 = comb(n-i, k-i);
        long long c3 = modinv(n-i);
        long long term = c1 * c2 % MOD * c3 % MOD;
        if((k-i)&1) ans = (ans - term + MOD) % MOD;
        else ans = (ans + term) % MOD;
    }
    ans = ans * factorial(n) % MOD * factorial(n) % MOD;
    cout << ans;
}

long long factorial(int n){
    long long res = 1;
    for(int i=2; i<=n; ++i){
        res = res * i % MOD;
    }
    return res;
}