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

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ((void)0);
    ((void)0);

    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int ans = 0;

    for (int l = 0; l < N; ++l) {
        for (int r = l; r < N; ++r) {
            vector<int> dp(S + 1);
            dp[0] = 1;
            for (int i = l; i <= r; ++i) {
                vector<int> ndp(S + 1);
                for (int j = 0; j <= S; ++j) {
                    ndp[j] = add(ndp[j], dp[j]);
                    if (j + A[i] <= S) {
                        ndp[j + A[i]] = add(ndp[j + A[i]], dp[j]);
                    }
                }
                dp = ndp;
            }
            ans = add(ans, dp[S]);
        }
    }

    cout << ans << '\n';

    return 0;
}