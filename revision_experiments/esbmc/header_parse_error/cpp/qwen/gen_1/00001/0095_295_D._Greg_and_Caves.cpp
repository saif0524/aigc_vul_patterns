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

const int MOD = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    if(m < 2){
        cout << 0;
        return 0;
    }
    long long dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=m;++i){
        dp[1][i] = i-1;
    }
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            dp[i][j] = (dp[i-1][j-1] + dp[i][j-1] + (j-1) * dp[i-1][j]) % MOD;
        }
    }
    long long ans = 0;
    for(int i=1;i<=m;++i){
        ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans;
}