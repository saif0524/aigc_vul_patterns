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
const int MOD = 1e9 + 7;
const int MAXN = 55;

int n, p;
int c[MAXN];
int dp[MAXN][MAXN][2];

int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    ((void)0);
    ((void)0);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 1; k++) {
                if (c[i] == -1) {
                    dp[i][j][0] = add(dp[i][j][0], dp[i-1][j][k]);
                    dp[i][j][1] = add(dp[i][j][1], dp[i-1][j][k]);
                } else if (c[i] == k) {
                    dp[i][j][k] = add(dp[i][j][k], dp[i-1][j][k]);
                }
                for (int l = 1; l < i; l++) {
                    if (c[i] == -1) {
                        dp[i][j+l][0] = add(dp[i][j+l][0], dp[i-1][j][1]);
                        dp[i][j+l][1] = add(dp[i][j+l][1], dp[i-1][j][0]);
                    } else if (c[i] == 0) {
                        dp[i][j+l][0] = add(dp[i][j+l][0], dp[i-1][j][1]);
                    } else {
                        dp[i][j+l][1] = add(dp[i][j+l][1], dp[i-1][j][0]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = add(ans, dp[n][i][p]);
    }
    cout << ans << endl;
    return 0;
}