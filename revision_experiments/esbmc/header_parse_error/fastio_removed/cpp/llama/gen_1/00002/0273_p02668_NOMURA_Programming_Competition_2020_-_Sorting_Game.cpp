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

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    ((void)0);
    ((void)0);

    int N, M;
    cin >> N >> M;

    vector<long long> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    vector<long long> dp(M + 1);
    dp[0] = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1] % MOD * pow2[j * (N - 1) + (i - j - 1)] % MOD) % MOD;
        }
    }

    long long ans = dp[M];
    for (int i = 1; i <= M; i++) {
        ans = ans * modpow(2, N) % MOD;
    }

    cout << ans << endl;

    return 0;
}