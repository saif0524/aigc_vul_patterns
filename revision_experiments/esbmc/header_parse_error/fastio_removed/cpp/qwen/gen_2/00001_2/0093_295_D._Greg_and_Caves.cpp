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

typedef long long ll;
const int MOD = 1000000007;

ll dp[2001][2001], f[2001][2001], inv[2001], f_inv[2001];

ll power(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main(){
    ((void)0);
    ((void)0);

    int n, m;
    cin >> n >> m;

    f[0] = f_inv[0] = inv[1] = dp[0][0] = 1;
    for(int i = 1; i <= m; ++i){
        inv[i] = power(i, MOD-2);
        f[i] = f[i-1] * i % MOD;
        f_inv[i] = f_inv[i-1] * inv[i] % MOD;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 2; j <= m; ++j){
            for(int k = 1; k <= j-1; ++k){
                int left = f[j-2] * f_inv[k-1] % MOD * f_inv[j-1-k] % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][k] * left % MOD) % MOD;
            }
        }
        for(int j = 1; j <= m; ++j){
            f[j] = (f[j] + dp[i][j]) % MOD;
        }
    }

    cout << f[m] << "\n";
}