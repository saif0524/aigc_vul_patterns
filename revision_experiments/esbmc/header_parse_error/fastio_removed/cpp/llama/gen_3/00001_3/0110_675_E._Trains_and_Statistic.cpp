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
const int N = 1e5 + 5;

int n;
int arr[N];
int dp[N];
long long dp2[N];

int main() {
    ((void)0);
    ((void)0);

    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> arr[i];
    }

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = mod;
    }

    dp[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        dp[i] = mod;
        for (int j = i + 1; j <= arr[i]; ++j) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans += dp[j] - dp[i] + 1;
        }
    }
    cout << ans << "\n";

    return 0;
}