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

long long dp[1<<18];

double evaluate(int n, long long dp[]) {
    double res = 0;
    for (int i = 0; i < (1 << n); ++i) {
        res += dp[i];
    }
    return res / (1 << n);
}

void update_dp(int n, int pos, long long val, long long dp[]) {
    for (int mask = 0; mask < (1 << n); ++mask) {
        if ((mask & (1 << pos)) == 0) {
            dp[mask] -= val;
            dp[mask | (1 << pos)] += val;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector<long long> f(1<<n);
    for(auto &i: f) cin >> i;
    copy(f.begin(), f.end(), dp);
    for(int i=0;i<n;++i){
        for(int mask = (1<<n)-1;mask>=0;--mask){
            if(mask & (1<<i)){
                dp[mask] -= f[mask];
                dp[mask^(1<<i)] += f[mask];
            }
        }
    }
    cout << fixed << setprecision(6);
    cout << evaluate(n, dp) << "\n";
    for(int i=0;i<r;++i){
        int z, g;
        cin >> z >> g;
        long long diff = g - f[z];
        f[z] = g;
        update_dp(n, z, diff, dp);
        cout << evaluate(n, dp) << "\n";
    }
}