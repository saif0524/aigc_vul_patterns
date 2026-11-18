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

const int MOD = 998244353;

int powmod(int a, int b) {
    int res = 1;
    for (; b; b /= 2) {
        if (b % 2) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
    }
    return res;
}

int main() {
    int p, s, r;
    cin >> p >> s >> r;
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < p; ++i) {
        vector<int> new_dp(s + 1, 0);
        for (int j = 0; j <= s; ++j) {
            for (int k = 0; k + j <= s; ++k) {
                new_dp[j + k] = (new_dp[j + k] + 1LL * dp[j] * (s - j + 1) % MOD) % MOD;
            }
        }
        int sum = 0;
        for (int j = 0; j <= s; ++j) {
            sum = (sum + dp[j]) % MOD;
        }
        for (int j = 0; j <= s; ++j) {
            dp[j] = 1LL * new_dp[j] * powmod(sum, MOD - 2) % MOD;
        }
    }
    int total = 0;
    for (int i = 0; i <= s; ++i) {
        total = (total + dp[i]) % MOD;
    }
    int win = 0;
    for (int i = r; i <= s; ++i) {
        int count = (dp[i - r] * powmod(total, MOD - 2)) % MOD;
        if (i * 2 > s) {
            win = (win + count) % MOD;
        } else if (i * 2 == s) {
            win = (win + 1LL * count * (p / 2) % MOD) % MOD;
        } else {
            win = (win + 1LL * count * (total - dp[i]) % MOD) % MOD;
            win = (win + 1LL * count * (p / 2) % MOD) % MOD;
        }
    }
    cout << win << "\n";
}