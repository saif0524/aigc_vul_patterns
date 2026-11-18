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
    vector<pair<int,int>> songs(n);
    for(auto &s: songs) { cin >> s.first >> s.second; }
    vector<double> dp(T+1, 0.0);
    for(int i=0; i<n; i++){
        vector<double> new_dp(T+1, 0.0);
        for(int t=1; t<=T; t++){
            if(t >= songs[i].second){
                new_dp[t] = 1.0;
            } else {
                new_dp[t] = (dp[t] * (1.0 - songs[i].first / 100.0));
            }
            if(t-1 > 0) new_dp[t] += (dp[t-1] * (songs[i].first / 100.0));
        }
        dp = new_dp;
    }
    double expected = 0.0;
    for(int t=1; t<=T; t++) expected += dp[t];
    cout << fixed << setprecision(9) << expected << "\n";
}