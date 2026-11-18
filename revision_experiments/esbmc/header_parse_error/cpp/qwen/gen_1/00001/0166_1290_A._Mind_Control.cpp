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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<long long> a(n);
        for(auto &x: a) cin >> x;
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        for(int i = 0; i < n; ++i){
            dp[i][i] = a[i];
        }
        for(int len = 2; len <= n; ++len){
            for(int i = 0; i + len - 1 < n; ++i){
                int j = i + len - 1;
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
        
        long long ans = -1;
        for(int i = 0; i + k < m - 1; ++i){
            ans = max(ans, dp[i + k + 1][n - 1]);
        }
        for(int i = m; i + k < n; ++i){
            ans = max(ans, dp[0][i - k - 1]);
        }
        ans = max(ans, dp[max(0, m - k)][min(n - 1, m + k - 1)]);
        cout << ans + accumulate(a.begin(), a.end(), 0LL) / 2 << "\n";
    }
}