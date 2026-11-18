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

int n, m, k;
long long a[20];
vector<pair<int, long long>> rules[20];
long long dp[1 << 18][20];

long long solve(int mask, int last) {
    if (__builtin_popcount(mask) == m) return 0;
    long long &ret = dp[mask][last];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
            long long cur = a[i] + solve(mask | (1 << i), i);
            for (auto &[y, c] : rules[i]) {
                if (y == last) cur += c;
            }
            ret = max(ret, cur);
        }
    }
    return ret;
}

int main(){
    ((void)0);
    ((void)0);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++){
        int x, y;
        long long c;
        cin >> x >> y >> c;
        x--; y--;
        rules[x].emplace_back(y, c);
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << "\n";
}