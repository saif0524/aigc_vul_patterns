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
    int N, R;
    cin >> N >> R;
    vector<int> F(N), S(N);
    vector<double> P(N);
    for(int i=0;i<N;i++){
        cin >> F[i] >> S[i] >> P[i];
        P[i]/=100.0;
    }
    vector<double> dp(R+1, 1e18);
    dp[0] = 0.0;
    for(int i=0;i<N;i++){
        vector<double> ndp(R+1, 1e18);
        for(int r=0;r<=R;r++){
            if(dp[r] >= 1e18) continue;
            if(r + F[i] <= R){
                ndp[r + F[i]] = min(ndp[r + F[i]], dp[r] + F[i]);
            }
            if(r + S[i] <= R){
                ndp[r + S[i]] = min(ndp[r + S[i]], dp[r] + (1.0 / P[i]) * S[i]);
            }
            ndp[0] = min(ndp[0], dp[r] + (1.0 / P[i]) * S[i]);
        }
        dp = ndp;
    }
    double ans = 1e18;
    for(int r=0;r<=R;r++){
        ans = min(ans, dp[r]);
    }
    cout << fixed << setprecision(9) << ans;
}