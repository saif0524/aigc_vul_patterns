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

double solve(vector<int>& f, int n) {
    if (n == 0) return f[0];
    vector<double> dp(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        int count = __builtin_popcount(mask);
        if (count == n) {
            dp[mask] = f[mask];
            continue;
        }
        int cnt = n - count;
        double best = 1e9;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0) {
                double val = dp[mask | (1 << i)];
                best = min(best, val);
                if (count == 0) {
                    val = dp[mask | (1 << i)];
                    best = max(best, val);
                }
            }
        }
        dp[mask] = count == 0 ? best / cnt : best / cnt;
    }
    return dp[0];
}

int main(){
    ((void)0);
    ((void)0);
    int n, r;
    cin >> n >> r;
    vector<int> f(1 << n);
    for(auto &x: f) cin >> x;
    cout << fixed << setprecision(6) << solve(f, n) << "\n";
    for(int i=0;i<r;i++){
        int z, g;
        cin >> z >> g;
        f[z] = g;
        cout << fixed << setprecision(6) << solve(f, n) << "\n";
    }
}