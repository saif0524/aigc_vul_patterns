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
    int n;
    cin >> n;
    vector<pair<int,int>> ab(n);
    for(auto& [a,b]: ab) cin >> a >> b;
    
    int cur = 1;
    vector<int> dp(1,1);
    for(auto& [a, b]: ab){
        for(int i = 0; i < a; ++i){
            vector<int> newdp(cur + 1, 0);
            for(int j = 0; j <= cur; ++j){
                if(j > 0) newdp[j] = (newdp[j] + dp[j-1]) % MOD;
                newdp[j] = (newdp[j] + dp[j]) % MOD;
                if(j < cur) newdp[j] = (newdp[j] + dp[j+1]) % MOD;
            }
            dp = move(newdp);
            ++cur;
        }
        for(int i = 0; i < b; ++i){
            vector<int> newdp(cur - 1, 0);
            for(int j = 0; j < cur; ++j){
                if(j > 0) newdp[j-1] = (newdp[j-1] + dp[j-1]) % MOD;
                newdp[j-1] = (newdp[j-1] + dp[j]) % MOD;
                if(j < cur-1) newdp[j] = (newdp[j] + dp[j]) % MOD;
            }
            dp = move(newdp);
            --cur;
        }
    }
    int ans = 0;
    for(int x: dp) ans = (ans + x) % MOD;
    cout << ans;
}