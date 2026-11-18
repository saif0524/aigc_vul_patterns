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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    dp[0][0] = 1;
    
    for(int i=1; i<=n; ++i){
        for(int j=0; j<=k; ++j){
            long long num = 0;
            for(int l=i; l>=1; --l){
                num = (num + (s[l-1]-'0') * pow(10, i-l, MOD)) % MOD;
                if(j >0) dp[i][j] = (dp[i][j] + dp[l-1][j-1] * num) % MOD;
                else if(l ==1) dp[i][j] = (dp[i][j] + num) % MOD;
            }
        }
    }
    
    cout << dp[n][k] << "\n";
    return 0;
}

long long pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while(exp > 0){
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}