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

const int INF = 1e9;

int main() {
    ((void)0);
    ((void)0);

    int K, N;
    cin >> K >> N;

    vector<int> t(N);
    for (auto &x : t) { cin >> x; }

    sort(t.begin(), t.end());

    vector<vector<int>> dp(K + 1, vector<int>(N, INF));
    for (int i = 0; i < N; ++i) dp[0][i] = 0;

    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[k][i] = min(dp[k][i], dp[k - 1][j] + t[i] - t[j]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        ans = min(ans, dp[K][i]);
    }

    cout << ans << '\n';

    return 0;
}