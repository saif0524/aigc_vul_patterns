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
    int n;
    cin >> n;
    const int mod = 998244353;
    vector<long long> dp(1, 1);
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        int current_width = dp.size();
        for(int j = 0; j < a; ++j){
            dp.push_back(0);
            for(int k = max(0, current_width - 1); k < (int)dp.size() - 1; ++k){
                dp[k + 1] = (dp[k + 1] + dp[k]) % mod;
            }
            current_width++;
        }
        for(int j = 0; j < b; ++j){
            for(int k = current_width - 1; k >= 1; --k){
                dp[k - 1] = (dp[k - 1] + dp[k]) % mod;
                dp[k] = 0;
            }
            current_width--;
        }
    }
    long long ans = 0;
    for(long long x : dp){
        ans = (ans + x) % mod;
    }
    cout << ans;
}