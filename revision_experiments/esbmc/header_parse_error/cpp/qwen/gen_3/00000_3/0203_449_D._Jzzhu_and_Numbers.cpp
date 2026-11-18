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

const int MOD = 1000000007;
const int MAX = 20;
const int MAX_MASK = (1 << MAX) + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> dp(MAX_MASK, 0);
    dp[0] = 1;
    for(int x : a) {
        for(int mask = MAX_MASK - 1; mask >= 0; --mask) {
            if(dp[mask] == 0) continue;
            dp[mask | x] = (dp[mask | x] + dp[mask]) % MOD;
        }
    }
    int result = 0;
    for(int mask = 1; mask < MAX_MASK; ++mask) {
        if(dp[mask] > 0 && (mask & (mask - 1)) == 0) {
            result = (result + dp[mask]) % MOD;
        }
    }
    cout << result;
    return 0;
}