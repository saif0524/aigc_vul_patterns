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

int solve(int N, vector<int> &a) {
    int dp[N + 1] = {};
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (find(a.begin(), a.end(), i) != a.end()) continue;
        if (i - 1 >= 0 && find(a.begin(), a.end(), i - 1) == a.end()) {
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
        if (i - 2 >= 0 && find(a.begin(), a.end(), i - 2) == a.end()) {
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
    }
    return dp[N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
    }

    cout << solve(N, a) << "\n";

    return 0;
}