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
const int mod = 1e9 + 7;

long long powmod(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return powmod(a, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    if (s[0] == 'B' || s[0] == 'X') dp[1][0] = 1;
    if (s[0] == 'W' || s[0] == 'X') dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i - 1] == 'B' || s[i - 1] == 'X') dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        if (s[i - 1] == 'W' || s[i - 1] == 'X') dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    long long ans = 0;
    for (int i = k; i <= n; i++) {
        int cntB = 0, cntW = 0;
        for (int j = i - k + 1; j <= i; j++) {
            if (s[j - 1] == 'B') cntB++;
            if (s[j - 1] == 'W') cntW++;
        }
        if (cntB == k || cntW == k) continue;
        long long res = 1;
        for (int j = i - k + 1; j <= i; j++) {
            if (s[j - 1] == 'X') res = res * 2 % mod;
        }
        ans = (ans + res) % mod;
    }
    for (int i = k; i <= n; i++) {
        int cntB = 0, cntW = 0;
        for (int j = i - k + 1; j <= i; j++) {
            if (s[j - 1] == 'B') cntB++;
            if (s[j - 1] == 'W') cntW++;
        }
        if (cntB != k || cntW != k) continue;
        ans = (ans + mod - 1) % mod;
    }
    cout << ans << endl;
    return 0;
}