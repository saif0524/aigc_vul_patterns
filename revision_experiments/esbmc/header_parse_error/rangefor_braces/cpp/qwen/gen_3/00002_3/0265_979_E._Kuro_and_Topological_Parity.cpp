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

int dp[2][51][2];

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> c(n);
    for(int &x : c) { cin >> x; }
    
    dp[0][0][c[0] != -1] = 1;
    
    for(int i = 1; i < n; i++){
        int cur = i % 2;
        int prv = (i - 1) % 2;
        for(int j = 0; j <= i; j++){
            dp[cur][j][0] = dp[cur][j][1] = 0;
            for(int k = 0; k <= j; k++){
                if(c[k] != -1){
                    if(c[i] != -1){
                        if(c[k] != c[i]){
                            dp[cur][j][c[i]] = (dp[cur][j][c[i]] + dp[prv][k][c[k]]) % MOD;
                        }
                    }
                    else{
                        dp[cur][j][0] = (dp[cur][j][0] + dp[prv][k][c[k]]) % MOD;
                        dp[cur][j][1] = (dp[cur][j][1] + dp[prv][k][c[k]]) % MOD;
                    }
                }
            }
            if(c[i] == -1){
                dp[cur][j+1][0] = (dp[cur][j+1][0] + dp[prv][j][1]) % MOD;
                dp[cur][j+1][1] = (dp[cur][j+1][1] + dp[prv][j][0]) % MOD;
            }
            else{
                dp[cur][j][c[i]] = (dp[cur][j][c[i]] + dp[prv][j][c[i]]) % MOD;
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i <= n; i++){
        res = (res + dp[(n-1) % 2][i][0]) % MOD;
        res = (res + dp[(n-1) % 2][i][1]) % MOD;
    }
    
    int all = 1;
    for(int i = 0; i < n; i++) if(c[i] == -1) all = (all * 2) % MOD;
    
    int cnt = 0;
    for(int i = 0; i < n; i++) if(c[i] == -1) cnt++;
    
    int parity = 0;
    for(int mask = 0; mask < (1 << cnt); mask++){
        int cur = 0;
        int cnt0 = 0, cnt1 = 0;
        for(int j = 0, k = 0; j < n; j++){
            if(c[j] == -1){
                cur += (mask & (1 << k)) ? 1 : 0;
                k++;
            }
        }
        if(__builtin_popcount(cur) % 2 == p){
            parity = (parity + 1) % MOD;
        }
    }
    
    parity = (parity * all) % MOD;
    
    int even, odd;
    if(p == 0) even = parity, odd = (all - parity + MOD) % MOD;
    else even = (all - parity + MOD) % MOD, odd = parity;
    
    int ans = (even * dp[(n-1) % 2][n][0] + odd * dp[(n-1) % 2][n][1]) % MOD;
    
    cout << ans;
}