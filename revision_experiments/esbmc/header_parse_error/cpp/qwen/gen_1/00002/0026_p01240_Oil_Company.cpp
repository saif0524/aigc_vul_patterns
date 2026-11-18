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

int main() {
    int N;
    cin >> N;
    for (int test = 1; test <= N; ++test) {
        int W, H;
        cin >> W >> H;
        vector<vector<int>> grid(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> grid[i][j];
            }
        }
        vector<vector<int>> dp(H, vector<int>(W));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                int value = grid[i][j];
                if (i > 0) value = max(value, dp[i - 1][j]);
                if (j > 0) value = max(value, dp[i][j - 1]);
                if (i > 0 && j > 0) value = max(value, dp[i - 1][j - 1]);
                if (i > 0 && j < W - 1) value = max(value, dp[i - 1][j + 1]);
                dp[i][j] = value + grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << "Case " << test << ": " << ans << "\n";
    }
    return 0;
}