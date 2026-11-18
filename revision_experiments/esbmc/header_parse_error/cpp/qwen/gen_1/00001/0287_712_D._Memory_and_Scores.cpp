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

int dp[201][201][101];

int main() {
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    int offset = k * t;
    dp[a + offset][b + offset][0] = 1;
    for (int turn = 0; turn < t; ++turn) {
        for (int ma = -k * t; ma <= k * t; ++ma) {
            for (int mb = -k * t; mb <= k * t; ++mb) {
                if (dp[ma + offset][mb + offset][turn] == 0) continue;
                for (int da = -k; da <= k; ++da) {
                    for (int db = -k; db <= k; ++db) {
                        int nma = ma + da;
                        int nmb = mb + db;
                        dp[nma + offset][nmb + offset][turn + 1] = (dp[nma + offset][nmb + offset][turn + 1] + dp[ma + offset][mb + offset][turn]) % MOD;
                    }
                }
            }
        }
    }
    int result = 0;
    for (int ma = b + 1; ma <= k * t; ++ma) {
        for (int mb = -k * t; mb <= k * t; ++mb) {
            result = (result + dp[ma + offset][mb + offset][t]) % MOD;
        }
    }
    cout << result;
}