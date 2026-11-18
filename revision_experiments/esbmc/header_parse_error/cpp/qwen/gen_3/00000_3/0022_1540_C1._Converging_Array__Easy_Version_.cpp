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

const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for(auto &x: c) cin >> x;
    vector<int> b(n-1);
    for(auto &x: b) cin >> x;
    int q;
    cin >> q;
    vector<long long> x(q);
    for(auto &xi: x) cin >> xi;

    vector<vector<long long>> dp(n, vector<long long>(201, 0));
    for(int j=0; j<=c[0]; j++) dp[0][j+100] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<=200; j++){
            for(int k=0; k<=c[i]; k++){
                int lo = max(0, min(j-100, (j-100+k-b[i-1])/2)+100);
                int hi = min(200, max(j-100, (j-100+k+b[i-1])/2)+100);
                dp[i][k+100] = (dp[i][k+100] + dp[i-1][lo] + MOD - dp[i-1][hi+1]) % MOD;
            }
        }
    }

    for(int i=0; i<q; i++){
        long long ans = 0;
        int xi = x[i];
        if(xi <= -100) ans = 1;
        else if(xi > 100) ans = 0;
        else ans = (dp[n-1][xi+100] + MOD - dp[n-1][101]) % MOD;
        cout << ans << " ";
    }
}