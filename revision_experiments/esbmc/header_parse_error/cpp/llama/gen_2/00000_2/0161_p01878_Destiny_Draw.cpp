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
#define mod 1000000007
#define ll long long

const int N = 42, M = 1000005;
ll dp[N][M];

int main() {
    int n, k, c, t;
    cin >> n >> k >> c >> t;

    vector<int> a(k), b(k), w(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = t; j >= 0; j--) {
            for (int l = n - 1; l >= 0; l--) {
                if (j + w[i] <= t && l + b[i] <= n) {
                    (dp[l + b[i]][j + w[i]] += dp[l][j]) %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= t; i++) {
        if (c + i <= n) {
            (ans += dp[c + i][t]) %= mod;
        }
    }

    cout << ans << "\n";
    return 0;
}