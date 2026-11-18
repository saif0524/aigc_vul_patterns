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

const int MAXN = 4005;

int dp[2][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;

    int now = 0;
    for (int i = 1; i <= n; ++i) {
        now ^= (s[i - 1] - '0');
        dp[now][i][0] = 0;
    }

    now = 0;
    for (int i = 1; i <= m; ++i) {
        now ^= (t[i - 1] - '0');
        dp[now][0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[k][i - 1][j] != -1) {
                    dp[k][i][j] = min(dp[k][i][j], (s[i - 1] - '0') ^ k);
                }
                if (dp[k][i][j - 1] != -1) {
                    dp[k][i][j] = min(dp[k][i][j], (t[j - 1] - '0') ^ k);
                }
            }
        }
    }

    string ans;
    int x = n, y = m, now1 = 0;
    while (x > 0 || y > 0) {
        if (x > 0 && dp[0][x - 1][y] != -1 && dp[1][x - 1][y] != -1) {
            if (dp[0][x - 1][y] < dp[1][x - 1][y]) {
                ans += '0';
                now1 = 0;
            } else {
                ans += '1';
                now1 = 1;
            }
            --x;
        } else if (y > 0 && dp[0][x][y - 1] != -1 && dp[1][x][y - 1] != -1) {
            if (dp[0][x][y - 1] < dp[1][x][y - 1]) {
                ans += '0';
                now1 = 0;
            } else {
                ans += '1';
                now1 = 1;
            }
            --y;
        } else if (x > 0) {
            ans += '0';
            now1 = 0;
            --x;
        } else {
            ans += '0';
            now1 = 0;
            --y;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}