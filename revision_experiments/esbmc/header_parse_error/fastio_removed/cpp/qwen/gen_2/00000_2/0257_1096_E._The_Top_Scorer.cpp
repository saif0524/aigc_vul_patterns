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
const int MAXN = 105;
const int MAXS = 5005;

int dp[MAXN][MAXS];
int f[MAXS];

int mod_pow(int x, int y) {
    int res = 1;
    for (; y; y /= 2) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
    }
    return res;
}

int inv(int x) {
    return mod_pow(x, MOD - 2);
}

int main(){
    ((void)0);
    ((void)0);
    int p, s, r;
    cin >> p >> s >> r;
    dp[0][0] = 1;
    for(int i=0; i<p; i++){
        for(int j=0; j<=s; j++){
            for(int k=0; k+j<=s; k++){
                dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][j]) % MOD;
            }
        }
    }
    for(int i=r; i<=s; i++){
        f[i] = dp[p][i];
    }
    for(int i=s-1; i>=0; i--){
        f[i] = (f[i] + f[i+1]) % MOD;
    }
    int total_ways = dp[p][s];
    int win_ways = 0;
    for(int i=r; i<=s; i++){
        int ways = dp[p-1][s-i];
        if(i > s-i){
            win_ways = (win_ways + ways) % MOD;
        } else if(i == s-i){
            win_ways = (win_ways + 1LL * ways * inv(2) % MOD) % MOD;
        }
    }
    cout << 1LL * win_ways * inv(total_ways) % MOD;
}