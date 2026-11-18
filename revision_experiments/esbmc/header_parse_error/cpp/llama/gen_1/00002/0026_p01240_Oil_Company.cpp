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

const int MAXN = 25;
int grid[MAXN][MAXN];
int memo[MAXN][MAXN][2]; // 2 for not taken, 1 for taken
int w, h;

int dp(int i, int j, bool taken) {
    if (i >= h) return 0;
    if (j >= w) return dp(i + 1, 0, 0);
    int& ret = memo[i][j][taken];
    if (ret != -1) return ret;

    int exclude = dp(i, j + 1, taken);
    int include = 0;
    if (!taken && (i == 0 || j == 0 || grid[i - 1][j - 1] == 0)) {
        include = grid[i][j] + dp(i, j + 1, 1);
    }
    return ret = max(include, exclude);
}

int solve() {
    memset(memo, -1, sizeof memo);
    return dp(0, 0, 0);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> w >> h;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
            }
        }
        int ans = solve();
        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}