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

const int MAXN = 1005;
const int MAXD = 11;

int n, d, mod;
long long dp[MAXN][MAXN];

long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    cin >> n >> d >> mod;
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= i-1; ++j){
            dp[i][j] = 0;
            if(j >= (d-1)) dp[i][j] = (dp[i][j] + (long long)dp[i-1][j-(d-1)]) % mod;
            if(j > 0) dp[i][j] = (dp[i][j] + (long long)dp[i][j-1]*(i-1)) % mod;
        }
    }
    long long ans = 0;
    long long inv_d = modpow(d-1, mod-2, mod);
    for(int j = 0; j <= n-1; ++j) if(j >= (d-1)) {
        long long cur = dp[n][j];
        cur = (cur * (long long)modpow((n-1), mod-2, mod)) % mod;
        cur = (cur * inv_d) % mod;
        ans = (ans + cur * (long long)modpow(d-2, j-(d-1), mod)) % mod;
    }
    cout << ans << endl;
}