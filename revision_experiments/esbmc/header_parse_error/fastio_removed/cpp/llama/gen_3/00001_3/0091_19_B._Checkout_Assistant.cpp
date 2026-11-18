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

const int MAX_N = 2005;
const long long INF = 1e18;

int n;
int t[MAX_N], c[MAX_N];
long long dp[MAX_N][MAX_N];

int main() {
    ((void)0);
    ((void)0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> c[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + c[i]);
            dp[i + 1][max(0, j - t[i])] = min(dp[i + 1][max(0, j - t[i])], dp[i][j]);
        }
    }

    long long ans = INF;

    for (int j = 0; j <= n; ++j) {
        ans = min(ans, dp[n][j]);
    }

    cout << ans << '\n';

    return 0;
}