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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> intervals(n);
    for(auto &p : intervals){
        cin >> p.first >> p.second;
    }
    sort(intervals.begin(), intervals.end());
    
    vector<long long> dp(k+1, 0);
    dp[0] = 1;
    vector<long long> prefix(k+1, 0);
    prefix[0] = 1;
    
    int current_right = -1;
    int active = 0;
    
    for(int i = 0; i < n; ++i){
        int l = intervals[i].first;
        int r = intervals[i].second;
        while(current_right < l){
            current_right++;
            if(active >= k){
                prefix[active+1] = (prefix[active+1] + prefix[active]) % MOD;
            }
            if(active >= k){
                dp[active] = (dp[active] + prefix[active+1] - prefix[k] + MOD) % MOD;
            }
            if(active >= 1){
                prefix[active] = (prefix[active] + dp[active-1]) % MOD;
            }
            if(active >= k){
                prefix[k] = (prefix[k] + dp[k-1]) % MOD;
            }
            if(active >= 1){
                active--;
            }
        }
        if(active < k){
            dp[active+1] = (dp[active+1] + prefix[active]) % MOD;
            prefix[active+1] = (prefix[active+1] + prefix[active]) % MOD;
            active++;
        }
    }
    long long result = dp[k];
    cout << result;
    return 0;
}