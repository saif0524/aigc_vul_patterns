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
    int n, T;
    cin >> n >> T;
    vector<pair<int, int>> songs(n);
    for(auto &song : songs){
        cin >> song.first >> song.second;
    }
    double dp[T+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int t=1; t<=T; t++){
        for(int k=0; k<n; k++){
            dp[t][k] += dp[t-1][k];
            if(t >= songs[k].second){
                dp[t][k+1] += dp[t-1][k];
            }
            else{
                double p = songs[k].first / 100.0;
                dp[t][k] += dp[t-1][k] * p;
                dp[t][k+1] += dp[t-1][k] * (1-p);
            }
        }
    }
    double ans = 0;
    for(int k=1; k<=n; k++){
        ans += k * dp[T][k];
    }
    cout << fixed << setprecision(10) << ans;
}