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
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> blocked(4, vector<ll>(m+1, 0));
    for(ll i=0;i<n;i++){
        ll a, l, r;
        cin >> a >> l >> r;
        for(ll j=l;j<=r;j++){
            blocked[a][j] = 1;
        }
    }
    vector<vector<ll>> dp(4, vector<ll>(m+1, 0));
    dp[2][1] = 1;
    for(ll j=1;j<m;j++){
        if(blocked[1][j+1] != 1){
            dp[1][j+1] = (dp[1][j+1] + dp[2][j]) % MOD;
            dp[1][j+1] = (dp[1][j+1] + dp[1][j]) % MOD;
        }
        if(blocked[2][j+1] != 1){
            dp[2][j+1] = (dp[2][j+1] + dp[2][j]) % MOD;
            if(j>1) dp[2][j+1] = (dp[2][j+1] + dp[1][j]) % MOD;
            if(j>1) dp[2][j+1] = (dp[2][j+1] + dp[3][j]) % MOD;
        }
        if(blocked[3][j+1] != 1){
            dp[3][j+1] = (dp[3][j+1] + dp[2][j]) % MOD;
            dp[3][j+1] = (dp[3][j+1] + dp[3][j]) % MOD;
        }
    }
    cout << dp[2][m];
}