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

const int MAXN = 205;

int a[MAXN];
bool dp[MAXN][MAXN][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, false, sizeof(dp));
    dp[0][0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            for (int x = 0; x <= k; x++) {
                if (dp[i-1][j][x]) {
                    dp[i][j][x] = true;
                    if (x < k && j < i) {
                        dp[i][j+1][x+1] = true;
                    }
                }
            }
        }
    }

    int ans = -1000000;
    for (int j = 0; j <= n; j++) {
        for (int x = 0; x <= k; x++) {
            if (dp[n][j][x]) {
                int sum = 0;
                for (int i = 1; i <= j; i++) {
                    sum += a[i];
                }
                for (int i = n; i > n-j; i--) {
                    sum += a[i];
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;

    return 0;
}