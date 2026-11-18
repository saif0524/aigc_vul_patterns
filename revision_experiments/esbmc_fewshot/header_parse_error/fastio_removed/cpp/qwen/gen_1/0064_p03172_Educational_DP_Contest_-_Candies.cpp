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
    ((void)0);
    ((void)0);
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for(auto &x : a) cin >> x;
    
    vector<int> dp(K+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < N; ++i){
        vector<int> new_dp(K+1, 0);
        for(int j = 0; j <= K; ++j){
            if(dp[j] ==0) continue;
            for(int k =0; k <= min(K-j, a[i]); ++k){
                new_dp[j+k] = (new_dp[j+k] + dp[j]) % MOD;
            }
        }
        dp = new_dp;
    }
    
    cout << dp[K] << "\n";
    return 0;
}