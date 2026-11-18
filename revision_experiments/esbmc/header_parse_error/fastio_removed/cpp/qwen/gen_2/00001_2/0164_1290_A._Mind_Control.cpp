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

long long dp[3501][3501][2];

long long solve(int l, int r, bool f, int n, int m, int k, const vector<int>& a, int fixed[3501]) {
    if (l > r) return 0;
    long long& ans = dp[l][r][f];
    if (ans != -1) return ans;
    ans = 0;
    if (f) {
        int idx = (f ? l : r) + (m - 1) - (r - l);
        if (fixed[idx] != -1) {
            if (fixed[idx] == 0) {
                ans = a[l] + solve(l+1, r, !f, n, m, k, a, fixed);
            } else {
                ans = a[r] + solve(l, r-1, !f, n, m, k, a, fixed);
            }
        } else {
            if (k > 0) {
                ans = a[l] + solve(l+1, r, !f, n, m, k-1, a, fixed);
                ans = max(ans, a[r] + solve(l, r-1, !f, n, m, k-1, a, fixed));
            }
            ans = max(ans, solve(l, r, !f, n, m, k, a, fixed));
        }
    } else {
        ans = min(a[l] + solve(l+1, r, !f, n, m, k, a, fixed), a[r] + solve(l, r-1, !f, n, m, k, a, fixed));
    }
    return ans;
}

int main(){
    ((void)0);
    ((void)0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        int fixed[n];
        memset(fixed, -1, sizeof(fixed));
        memset(dp, -1, sizeof(dp));
        cout << solve(0, n-1, 1, n, m, k, a, fixed) << "\n";
    }
}