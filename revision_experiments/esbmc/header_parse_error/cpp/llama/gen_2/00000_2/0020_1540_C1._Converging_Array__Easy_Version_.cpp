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
const int N = 105;

int n, c[N], b[N], q;

long long dp[N][N * N];

long long count(int idx, int sum, int min_val) {
    if (idx == n) {
        if (min_val >= 0) return 1;
        else return 0;
    }

    if (dp[idx][sum] != -1) return dp[idx][sum];

    long long ans = 0;
    for (int i = 0; i <= c[idx]; i++) {
        int new_sum = sum + i;
        int new_min = min(min_val, new_sum - (b[idx - 1] + sum));
        if (idx < n - 1) ans = (ans + count(idx + 1, new_sum, new_min)) % mod;
        else {
            if (new_min >= 0) ans = (ans + 1) % mod;
        }
    }

    return dp[idx][sum] = ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        memset(dp, -1, sizeof dp);
        cout << count(0, 0, x) << "\n";
    }

    return 0;
}