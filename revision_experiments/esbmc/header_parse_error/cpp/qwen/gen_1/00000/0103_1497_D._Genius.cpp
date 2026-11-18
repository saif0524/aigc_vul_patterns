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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> tags(n);
        vector<long long> scores(n);
        for(int i=0;i<n;i++) cin >> tags[i];
        for(int i=0;i<n;i++) cin >> scores[i];
        vector<vector<long long>> dp(47, vector<long long>(n+1, LLONG_MIN));
        for(int i=0;i<n;i++){
            dp[0][i] = scores[i];
        }
        for(int i=1;i<47;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(tags[j]!=tags[k] && (1LL<<(i-1)) < abs((1LL<<j) - (1LL<<k))){
                        dp[i][k] = max(dp[i][k], dp[i-1][j] + abs(scores[j] - scores[k]));
                    }
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<47;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
}