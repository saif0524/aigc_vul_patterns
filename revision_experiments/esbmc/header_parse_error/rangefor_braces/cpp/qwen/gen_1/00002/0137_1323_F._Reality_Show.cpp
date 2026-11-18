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
    int n, m;
    cin >> n >> m;
    vector<int> l(n), s(n), c(n+m+1);
    for(auto &x: l) { cin >> x; }
    for(auto &x: s) { cin >> x; }
    for(int i=1; i<=n+m; ++i) cin >> c[i];
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN));
    dp[0][0] = 0;
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<=m; ++j){
            if(dp[i][j] == INT_MIN) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j < l[i]){
                int current = dp[i][j] - s[i] + c[l[i]];
                int new_aggr = l[i];
                while(current > dp[i+1][new_aggr+1]){
                    current += c[new_aggr+1] - c[new_aggr];
                    new_aggr++;
                }
                dp[i+1][new_aggr] = max(dp[i+1][new_aggr], current);
            }
        }
    }
    
    int ans = INT_MIN;
    for(int j=0; j<=m; ++j) ans = max(ans, dp[n][j]);
    cout << ans;
}