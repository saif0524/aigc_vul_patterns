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

const int MAXN = 1e6 + 5;
char s[MAXN];

int dp[MAXN][2];
int f[MAXN][2];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i <= n; i++) {
        dp[i][0] = dp[i][1] = -1e9;
        f[i][0] = f[i][1] = 1e9;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    f[0][0] = 0;
    f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            f[i][0] = min(f[i - 1][0], f[i - 1][1]) + 1;
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - 1);
            f[i][1] = min(f[i - 1][1], f[i - 1][0] - 1);
        } else if (s[i - 1] == '1') {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - 1) + 1;
            f[i][1] = min(f[i - 1][1], f[i - 1][0] - 1) + 1;
            dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
            f[i][0] = min(f[i - 1][1] + 1, f[i - 1][0]);
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1, dp[i - 1][0] - 1 + 1);
            f[i][0] = min(f[i - 1][0], f[i - 1][1] + 1, f[i - 1][0] - 1 + 1);
            dp[i][1] = max(dp[i - 1][0] - 1 + 1, dp[i - 1][1] + 1, dp[i - 1][1] - 1);
            f[i][1] = min(f[i - 1][0] - 1 + 1, f[i - 1][1] + 1, f[i - 1][1] - 1);
        }
    }
    printf("%d\n", max(dp[n][0], dp[n][1]));
}

int main() {
    solve();
    return 0;
}