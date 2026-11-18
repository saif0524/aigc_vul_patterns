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

int main(){
    ((void)0);
    ((void)0);
    int n, k;
    cin >> n >> k;
    vector<long long> dp(n+1, 0);
    vector<int> ans1(n), ans2(n);
    for(int i=1; i<=n; ++i){
        vector<long long> new_dp(dp);
        for(int j=1; j<=n; ++j){
            if(dp[i-1] + max(i, j) <= k){
                if(dp[i-1] + max(i, j) > new_dp[i]){
                    new_dp[i] = dp[i-1] + max(i, j);
                    if(i >= j){
                        ans1[i-1] = i;
                        ans2[i-1] = j;
                    }
                    else{
                        ans1[i-1] = j;
                        ans2[i-1] = i;
                    }
                }
            }
        }
        dp = new_dp;
    }
    if(dp[n] == 0){
        cout << "-1";
        return 0;
    }
    cout << dp[n] << "\n";
    for(int i=0; i<n; ++i) cout << ans1[i] << " \n"[i==n-1];
    for(int i=0; i<n; ++i) cout << ans2[i] << " \n"[i==n-1];
}