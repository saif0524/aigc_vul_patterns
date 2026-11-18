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
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ((void)0);
    ((void)0);

    ll n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    ll dp[n][k + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; j >= 0; j--) {
            sum = (sum * 10 + str[j] - '0') % MOD;
            if (i - j + 1 <= k + 1) {
                for (int x = 0; x <= k; x++) {
                    if (x == 0 && i == j) {
                        if (str[j] != '0')
                            dp[i][x] = (dp[i][x] + sum) % MOD;
                    } else if (x > 0 && i > j) {
                        dp[i][x] = (dp[i][x] + (sum * dp[j - 1][x - 1]) % MOD) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[n - 1][k] << '\n';

    return 0;
}