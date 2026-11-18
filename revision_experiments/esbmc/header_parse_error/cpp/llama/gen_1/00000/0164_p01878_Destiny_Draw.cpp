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

int N, K, C, T;
int a[100], b[100], t[100];
int dp[1000005][41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> C >> T;
    for (int i = 1; i <= K; ++i) {
        cin >> a[i] >> b[i] >> t[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j <= K; ++j) {
            if (dp[i][j] == 0) continue;
            if (j < K) {
                int ni = i + t[j + 1], nj = j + 1;
                if (ni <= T) {
                    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % mod;
                }
            }
            for (int k = 1; k <= K; ++k) {
                if (t[k] + i <= T) {
                    int nj = (j + b[k]) % N;
                    dp[i + t[k]][nj] = (dp[i + t[k]][nj] + dp[i][j]) % mod;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= T; ++i) {
        ans = (ans + dp[i][C - 1]) % mod;
    }

    cout << ans << endl;

    return 0;
}