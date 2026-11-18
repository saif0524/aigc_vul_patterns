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
const int MOD = 998244353;

int main(){
    ((void)0);
    ((void)0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x: a) cin >> x;
    vector<ll> dp(n);
    if(a[0] != -1) dp[0] = 1;
    else dp[0] = 200;
    if(a[n-1] != -1) dp[n-1] = 1;
    else dp[n-1] = 200;
    for(int i=1;i<n;i++){
        if(a[i] != -1){
            if(a[i-1] != -1){
                if(a[i] > a[i-1]) dp[i] = 0;
                else dp[i] = dp[i-1];
            }
            else{
                dp[i] = min(a[i],200) - 1 + dp[i-1];
                if(a[i] == 200) dp[i] -= 1;
            }
        }
        else{
            if(a[i-1] != -1){
                dp[i] = 200 - a[i-1] + dp[i-1];
            }
            else{
                dp[i] = dp[i-1] * 200 % MOD;
            }
        }
        dp[i] %= MOD;
    }
    for(int i=n-2;i>=0;i--){
        if(a[i] != -1){
            if(a[i+1] != -1){
                if(a[i] > a[i+1]) dp[i] = 0;
                else dp[i] = min(dp[i],dp[i+1]);
            }
            else{
                dp[i] = min(a[i],200) - 1 + dp[i+1];
                if(a[i] == 200) dp[i] -= 1;
            }
        }
        else{
            if(a[i+1] != -1){
                ll add = dp[i+1] * (200 - a[i+1]) % MOD;
                dp[i] = (dp[i] + add) % MOD;
            }
            else{
                ll add = dp[i+1] * 200 % MOD;
                dp[i] = (dp[i] * 200 % MOD + add) % MOD;
            }
        }
        dp[i] %= MOD;
    }
    cout << dp[0];
}