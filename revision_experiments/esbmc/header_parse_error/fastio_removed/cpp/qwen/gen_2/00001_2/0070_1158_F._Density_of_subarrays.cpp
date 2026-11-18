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

int main(){
    ((void)0);
    ((void)0);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    vector<int> dp(1<<c, 0);
    dp[0] = 1;
    for(auto x: a){
        int mask = 0;
        mask |= (1<<(x-1));
        for(int j=(1<<c)-1; j>=0; --j){
            if((j|mask) == j){
                dp[j] = (dp[j] + dp[j^mask]) % MOD;
            }
        }
    }
    
    vector<int> fact(n+1, 1), ifact(n+1, 1);
    for(int i=2; i<=n; ++i){
        fact[i] = 1LL * fact[i-1] * i % MOD;
        ifact[i] = 1LL * ifact[i-1] * pow(i, MOD-2, MOD) % MOD;
    }
    
    vector<int> ans(n+1, 0);
    for(int mask=1; mask<(1<<c); ++mask){
        int cnt = __builtin_popcount(mask);
        ans[cnt] = (ans[cnt] + 1LL * dp[mask] * fact[n]) % MOD;
        for(int j=0; j<cnt; ++j){
            ans[cnt-j] = (ans[cnt-j] - 1LL * dp[mask] * fact[n-j] % MOD * ifact[j] % MOD + MOD) % MOD;
        }
    }
    
    for(int i=0; i<=n; ++i){
        cout << ans[i] << (i<n?" ":"\n");
    }
}